#!/usr/bin/python3
# -*- coding: utf-8 -*-

from optparse import OptionParser
import os
import json
import sys
import re

def main():
  supported_output_formats = [
      "JSON",
      "HTML",
  ]
  parser = OptionParser(usage="usage: %prog [options] files...")
  parser.description = "Generate a table of the Graphviz compile " \
  "configuration for different platforms from files generated by the " \
  "./configure command."
  parser.add_option("-v", "--verbose", action="store_true",
                    dest="verbose", default=False,
                    help="Log info about what is going on")
  parser.add_option("-c", "--color", action="store_const",
                    dest="colors", const = "green:red", default=None,
                    help="Color output using default coloring. Yes is colored \
                    green and No is colored red")
  parser.add_option("--colors", action="store",
                    dest="colors", default=None,
                    help="Color output using specifed COLORS. The format is <Yes-color>:<No-color>")
  parser.add_option("-s", "--short", action="store_true",
                    dest="short", default=False,
                    help="Output only Yes or No")
  parser.add_option("--output-format", action="store",
                    dest="output_format", default="JSON",
                    help="Set output format. Supported formats are " +
                    " and ".join(supported_output_formats))

  (opts, args) = parser.parse_args()

  if opts.output_format.upper() not in supported_output_formats:
    print("Error:", opts.output_format, "output format is not supported", file=sys.stderr)
    parser.print_help(file=sys.stderr)
    exit(1)

  if opts.colors == None:
    styles = {
        "Yes": "",
        "No": "",
    }
  else:
    if opts.colors == "":
      yes_color = "green"
      no_color = "red"
    else:
      colors = opts.colors.split(":")
      if len(colors) == 2:
        yes_color, no_color = colors
      else:
        print("Error:", opts.colors, "color specification is illegal", file=sys.stderr)
        parser.print_help(file=sys.stderr)
        exit(1)
    styles = {
        "Yes": ' style="color: ' + yes_color + ';"',
        "No": ' style="color: ' + no_color + ';"',
    }

  table = {}
  table_sections = []
  component_names = {}
  platforms = []

  for filename in args:
    os_path = os.path.dirname(filename)
    os_version_id = os.path.basename(os_path)
    os_id = os.path.basename(os.path.dirname(os_path))
    platform = os_id.capitalize() + " " + os_version_id
    if platform not in platforms:
      platforms.append(platform)
    fp = open(filename, "r")
    lines = fp.readlines()
    for line in lines:
      item = [item.strip() for item in line.split(":")]
      if len(item) == 2:
        if item[1] == "":
          section_name = item[0]
          if section_name not in table:
            table[section_name] = {};
            table_sections.append(section_name)
            component_names[section_name] = []
        else:
          component_name, component_value = item;
          short_value = re.sub("(Yes|No).*", "\\1", component_value)
          if opts.short:
            component_value = short_value
          if component_name not in table[section_name]:
            table[section_name][component_name] = {};
            component_names[section_name].append(component_name)
          table[section_name][component_name][platform] = component_value

  if opts.output_format.upper() == "JSON":
    print(json.dumps(table, indent=4))
  elif opts.output_format.upper() == "HTML":
    colspan = str(len(platforms) + 1)
    indent = ""
    print(indent + "<!DOCTYPE html>")
    print(indent + "<html>")
    indent += "  "
    print(indent + "<head>")
    indent += "  "
    print(indent + '<meta charset="utf-8">')
    print(indent + "<style>")
    indent += "  "
    print(indent + "table {text-align: left; white-space: nowrap; position: relative;}")
    print(indent + "thead tr th {padding-right: 1em; padding-bottom: 5px; position: sticky; top: 0px;  background-color: white;}")
    print(indent + "td, th {padding-left: 1.5em;}")
    indent = indent[:-2]
    print(indent + "</style>")
    indent = indent[:-2]
    print(indent + "</head>")
    print(indent + "<body>")
    indent += "  "
    header = table_sections[0].replace("will be", "was")
    print(indent + "<h1>" + header + ":</h1>")
    print(indent + "<table>")
    indent += "  "
    print(indent + "<thead>")
    indent += "  "
    print(indent + "<tr>")
    indent += "  "
    print(indent + "<th></th>")
    for platform in platforms:
      print(indent + "<th>" + platform + "</th>")
    indent = indent[:-2]
    print(indent + "</tr>")
    print(indent + "</thead>")
    print(indent + "<tbody>")
    indent += "  "
    indent = indent[:-2]
    for section_name in table_sections[1:]:
      print(indent + '<tr><th colspan="' + colspan + '">' + section_name + ':</th></tr>')
      for component_name in component_names[section_name]:
        print(indent + "<tr>")
        indent += "  "
        print(indent + "<td>" + component_name + "</td>")
        for platform in platforms:
          component_value = table[section_name][component_name][platform]
          short_value = re.sub("(Yes|No).*", "\\1", component_value)
          color_style = styles[short_value]
          print(indent + "<td" + color_style + ">" + component_value + "</td>")
        indent = indent[:-2]
        print(indent + "</tr>")
      print(indent + '<tr><th colspan="' + colspan + '">&nbsp;</th></tr>')
    indent = indent[:-2]
    print(indent + "</tbody>")
    indent = indent[:-2]
    print(indent + "</table>")
    indent = indent[:-2]
    print(indent + "</body>")
    indent = indent[:-2]
    print(indent + "</html>")

# Python trick to get a main routine
if __name__ == "__main__":
  main()
