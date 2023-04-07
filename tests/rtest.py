#!/usr/bin/env python3

"""
Graphviz regression test driver

TODO:
 Report differences with shared version and with new output.
"""

import io
import os
import platform
import re
import shutil
import subprocess
import sys
from pathlib import Path
from typing import TextIO

TESTFILE = Path(__file__).parent / "tests.txt"
# Test specifications
GRAPHDIR = Path(__file__).parent / "graphs"
# Directory of input graphs and data
OUTDIR = Path("ndata")  # Directory for test output
OUTHTML = Path("nhtml")  # Directory for html test report

CRASH_CNT = 0
DIFF_CNT = 0
TOT_CNT = 0
TESTTYPES = {}


def readLine(f3: TextIO):
    """
    Read single line, storing it in LINE.
    Returns the line on success, else returns None
    """
    LINE = f3.readline()
    if LINE != "":
        return LINE.strip()
    return None


def skipLines(f3: TextIO):
    """
    Skip blank lines and comments (lines starting with #)
    Use first real line as the test name
    """
    while True:
        LINE = readLine(f3)
        if LINE is None:
            return None
        if LINE and not LINE.startswith("#"):
            return LINE


def readSubtests(f3: TextIO):
    """
    Subtests have the form: layout format optional_flags
    Store the 3 parts in the arrays ALG, FMT, FLAGS.
    Stop at a blank line
    """
    while True:
        LINE = readLine(f3)
        if LINE == "":
            return
        if not LINE.startswith("#"):
            ALG0, FMT0, *FLAGS0 = LINE.split(" ")
            yield {
                "ALG": ALG0,
                "FMT": FMT0,
                "FLAGS": FLAGS0,
            }


def readTest(f3: TextIO):
    """
    Read and parse a test.
    """
    # read test name
    LINE = skipLines(f3)
    if LINE is not None:
        TESTNAME = LINE
    else:
        return None

    # read input graph
    LINE = skipLines(f3)
    if LINE is not None:
        GRAPH = LINE
    else:
        return None

    SUBTESTS = list(readSubtests(f3))
    return {
        "TESTNAME": TESTNAME,
        "GRAPH": GRAPH,
        "SUBTESTS": SUBTESTS,
    }


def doDiff(OUTFILE, testname, fmt):
    """
    Compare old and new output and report if different.
     Args: testname index fmt
    """
    global DIFF_CNT
    FILE1 = OUTDIR / OUTFILE
    FILE2 = REFDIR / OUTFILE
    F = fmt.split(":")[0]
    # FIXME: Remove when https://gitlab.com/graphviz/graphviz/-/issues/1789 is
    # fixed
    if (
        platform.system() == "Windows"
        and F in ["ps", "gv"]
        and testname in ["clusters", "compound", "rootlabel"]
    ):
        print(
            f"Warning: Skipping {F} output comparison for test "
            f"{testname}: format {fmt} because the order of "
            "clusters in gv or ps output is not stable on Windows (#1789)",
            file=sys.stderr,
        )
        return
    if F in ["ps", "ps2"]:
        with open(FILE1, "rt", encoding="latin-1") as src:
            dst1 = io.StringIO()
            done_setup = False
            for line in src:
                if done_setup:
                    dst1.write(line)
                else:
                    done_setup = re.match(r"%%End.*Setup", line) is not None

        with open(FILE2, "rt", encoding="latin-1") as src:
            dst2 = io.StringIO()
            done_setup = False
            for line in src:
                if done_setup:
                    dst2.write(line)
                else:
                    done_setup = re.match(r"%%End.*Setup", line) is not None

        returncode = 0 if dst1.getvalue() == dst2.getvalue() else -1
    elif F == "svg":
        with open(FILE1, "rt", encoding="utf-8") as f:
            a = re.sub(r"^<!--.*-->$", "", f.read(), flags=re.MULTILINE)
        with open(FILE2, "rt", encoding="utf-8") as f:
            b = re.sub(r"^<!--.*-->$", "", f.read(), flags=re.MULTILINE)
        returncode = 0 if a.strip() == b.strip() else -1
    elif F == "png":
        # FIXME: remove when https://gitlab.com/graphviz/graphviz/-/issues/1788 is fixed
        if os.environ.get("build_system") == "cmake" and platform.system() == "Windows":
            print(
                f"Warning: Skipping PNG image comparison for test {testname}:"
                f" format: {fmt} because CMake builds on Windows "
                "do not contain the diffimg utility (#1788)",
                file=sys.stderr,
            )
            return
        returncode = subprocess.call(
            ["diffimg", FILE1, FILE2, OUTHTML / f"dif_{OUTFILE}"],
        )
        if returncode != 0:
            with open(OUTHTML / "index.html", "at", encoding="utf-8") as fd:
                fd.write("<p>\n")
                shutil.copyfile(FILE2, OUTHTML / f"old_{OUTFILE}")
                fd.write(f'<img src="old_{OUTFILE}" width="192" height="192">\n')
                shutil.copyfile(FILE1, OUTHTML / f"new_{OUTFILE}")
                fd.write(f'<img src="new_{OUTFILE}" width="192" height="192">\n')
                fd.write(f'<img src="dif_{OUTFILE}" width="192" height="192">\n')
        else:
            (OUTHTML / f"dif_{OUTFILE}").unlink()
    else:
        with open(FILE2, "rt", encoding="utf-8") as a:
            with open(FILE1, "rt", encoding="utf-8") as b:
                returncode = 0 if a.read().strip() == b.read().strip() else -1
    if returncode != 0:
        print(f"Test {testname}: == Failed == {OUTFILE}", file=sys.stderr)
        DIFF_CNT += 1


def genOutname(name, alg, fmt):
    """
    Generate output file name given 3 parameters.
      testname layout format
    If format ends in :*, remove this, change the colons to underscores,
    and append to basename
    If the last two parameters have been used before, add numeric suffix.
    """
    fmt_split = fmt.split(":")
    if len(fmt_split) >= 2:
        F = fmt_split[0]
        XFMT = f'_{"_".join(fmt_split[1:])}'
    else:
        F = fmt
        XFMT = ""

    IDX = alg + XFMT + F
    j = TESTTYPES.get(IDX, 0)
    if j == 0:
        TESTTYPES[IDX] = 1
        J = ""
    else:
        TESTTYPES[IDX] = j + 1
        J = str(j)
    OUTFILE = f"{name}_{alg}{XFMT}{J}.{F}"
    return OUTFILE


def doTest(test, SUBTEST):
    """
    Run a single test.
    """
    global TOT_CNT
    global CRASH_CNT
    global TESTTYPES
    TESTNAME = test["TESTNAME"]
    GRAPH = test["GRAPH"]
    if os.path.splitext(GRAPH)[1] == ".gv":
        INFILE = GRAPHDIR / GRAPH
    else:
        print(f"Unknown graph spec, test {TESTNAME} - ignoring", file=sys.stderr)
        return

    TOT_CNT += 1
    OUTFILE = genOutname(TESTNAME, SUBTEST["ALG"], SUBTEST["FMT"])
    OUTPATH = OUTDIR / OUTFILE
    KFLAGS = f"-K{SUBTEST['ALG']}"
    TFLAGS = f"-T{SUBTEST['FMT']}"
    testcmd = ["dot", KFLAGS, TFLAGS]
    testcmd += SUBTEST["FLAGS"] + ["-o", OUTPATH, INFILE]
    # FIXME: Remove when https://gitlab.com/graphviz/graphviz/-/issues/1786 is
    # fixed
    if os.environ.get("build_system") == "cmake" and SUBTEST["FMT"] == "png:gd":
        print(
            f'Skipping test {TESTNAME}: format {SUBTEST["FMT"]} because '
            "CMake builds does not support format png:gd (#1786)",
            file=sys.stderr,
        )
        return
    # FIXME: Remove when https://gitlab.com/graphviz/graphviz/-/issues/1269 is
    # fixed
    if (
        platform.system() == "Windows"
        and os.environ.get("build_system") == "msbuild"
        and "-Goverlap=false" in SUBTEST["FLAGS"]
    ):
        print(
            f"Skipping test {TESTNAME}: with flag -Goverlap=false because "
            "it fails with Windows MSBuild builds which are not built with "
            "triangulation library (#1269)",
            file=sys.stderr,
        )
        return
    # FIXME: Remove when https://gitlab.com/graphviz/graphviz/-/issues/1787 is
    # fixed
    if (
        platform.system() == "Windows"
        and os.environ.get("build_system") == "msbuild"
        and os.environ.get("configuration") == "Debug"
        and TESTNAME == "user_shapes"
    ):
        print(
            f"Skipping test {TESTNAME}: using shapefile because it fails "
            "with Windows MSBuild Debug builds (#1787)",
            file=sys.stderr,
        )
        return
    # FIXME: Remove when https://gitlab.com/graphviz/graphviz/-/issues/1790 is
    # fixed
    if platform.system() == "Windows" and TESTNAME == "ps_user_shapes":
        print(
            f"Skipping test {TESTNAME}: using PostScript shapefile "
            "because it fails with Windows builds (#1790)",
            file=sys.stderr,
        )
        return

    RVAL = subprocess.call(testcmd, stderr=subprocess.STDOUT)

    if RVAL != 0 or not OUTPATH.exists():
        CRASH_CNT += 1
        print(f"Test {TESTNAME}: == Layout failed ==", file=sys.stderr)
        print(f'  {" ".join(str(a) for a in testcmd)}', file=sys.stderr)
    elif (REFDIR / OUTFILE).exists():
        doDiff(OUTFILE, TESTNAME, SUBTEST["FMT"])
    else:
        sys.stderr.write(
            f"Test {TESTNAME}: == No file {REFDIR}/{OUTFILE} for comparison ==\n"
        )

    # clear TESTTYPES
    TESTTYPES = {}


# Set REFDIR
if platform.system() == "Linux":
    REFDIR = Path("linux.x86")
elif platform.system() == "Darwin":
    REFDIR = Path("macosx")
elif platform.system() == "Windows":
    REFDIR = Path("nshare")
else:
    print(f'Unrecognized system "{platform.system()}"', file=sys.stderr)
    REFDIR = Path("nshare")

# Check environment and initialize

if not REFDIR.is_dir():
    print(f"Test data directory {REFDIR} does not exist", file=sys.stderr)
    sys.exit(1)

if not OUTDIR.is_dir():
    OUTDIR.mkdir()

OUTHTML.mkdir(exist_ok=True)
for entry in OUTHTML.iterdir():
    entry.unlink()

with open(TESTFILE, "rt", encoding="utf-8") as testfile:
    while True:
        TEST = readTest(testfile)
        if TEST is None:
            break
        for subtest in TEST["SUBTESTS"]:
            doTest(TEST, subtest)
print(
    f"No. tests: {TOT_CNT} Layout failures: {CRASH_CNT} Changes: " f"{DIFF_CNT}",
    file=sys.stderr,
)
EXIT_STATUS = CRASH_CNT + DIFF_CNT
sys.exit(EXIT_STATUS)
