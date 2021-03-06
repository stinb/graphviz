# tools

MAKE=make
PLATFORMSDK=$(PROGRAMFILES)\Microsoft Visual Studio 8\VC\PlatformSDK
MSBUILD=$(WINDIR)\Microsoft.NET\Framework\v2.0.50727\MSBuild.exe
WIX = $(PROGRAMFILES)\Windows Installer XML v3\bin
CANDLE = $(WIX)\candle.exe
LIGHT = $(WIX)\light.exe
HEAT = $(WIX)\heat.exe
SED = sed

# local

PREBUILD=$(CURDIR)/../prebuild
LOCAL=$(PREBUILD)/usr/local
LOCAL_BIN=$(LOCAL)/bin
LOCAL_INCLUDE=$(LOCAL)/include
LOCAL_LIB=$(LOCAL)/lib

# base

GV_DIR=../..
DOT=dot.exe
DLLS=iconv.dll libcairo-2.dll libexpat-1.dll libfontconfig-1.dll libfreetype-6.dll libgd-2.dll libglib-2.0-0.dll libgmodule-2.0-0.dll libgobject-2.0-0.dll libintl-8.dll libpango-1.0-0.dll libpangocairo-1.0-0.dll libpangoft2-1.0-0.dll libpangowin32-1.0-0.dll libpixman-1-0.dll libpng12.dll zlib1.dll
DIRS=bin etc include lib share

#
# compose the MSI
#

graphviz.msi : graphviz.wixobj $(addsuffix .wixobj, $(DIRS))
	@echo
	@echo LIGHTING GRAPHVIZ...
	@echo
	"$(LIGHT)" -ext WixUIExtension -cultures:en-us -out $@ $^

#
# process the directories
#

$(addsuffix .wixobj, $(DIRS)) : %.wixobj : %.wxs
	@echo
	@echo CANDLING GRAPHVIZ...
	@echo
	"$(CANDLE)" -sw1092 -out $@ $^
	
# we need to post process dir.wxs with sed to:
# (1) change the GUID markers PUT-GUID-HERE to the autogenerated *
# (2) change the ComponentGroup1 ID to the dir
# (3) change the graphviz id of a directory to dir_graphviz
# (4) convert first <Directory Name="dir"> in Fragment to <DirectoryRef Id="dir">
# (5) convert last </Directory> in Fragment to </DirectoryRef>
$(addsuffix .wxs, $(DIRS)) : %.wxs : usr/local/bin/$(DOT)
	@echo
	@echo HEATING GRAPHVIZ...
	@echo
	"$(HEAT)" dir "usr\local\$*" -sfrag -out $*-pre.wxs && \
	$(SED) 's/PUT-GUID-HERE/*/g; s/Id="ComponentGroup1"/Id="$*"/g; s/Id="graphviz"/Id="$*_graphviz"/g; $!N; s/\(<Fragment>\W*\)<Directory.*Name="$*".*>/\1<DirectoryRef Id="$*">/g; s/<\/Directory>\(\W*<\/Fragment>\)/<\/DirectoryRef>\1/g; P; D' $*-pre.wxs >$*.wxs  

# bin directory also requires the dependent DLL's to be copied over first

bin.wxs : $(addprefix usr/local/bin/, $(DLLS))

$(addprefix usr/local/bin/, $(DLLS)) : usr/local/bin/% : $(LOCAL_BIN)/%
	mkdir -p usr/local/bin && cp $^ usr/local/bin

# etc directory also requires the fontconfig files to be copied over first

etc.wxs : usr/local/etc/fonts

usr/local/etc/fonts : $(LOCAL)/etc/fonts
	mkdir -p usr/local/etc && cp -R $^ usr/local/etc 

# install into usr/local

usr/local/bin/$(DOT): $(GV_DIR)/cmd/dot/.libs/$(DOT)
	@echo
	@echo INSTALLING GRAPHVIZ...
	@echo
	$(MAKE) DESTDIR=$(CURDIR) -C $(GV_DIR) install-strip
	
#
# process the viewer
#

graphviz.wixobj : $(GV_DIR)/Makefile x86/Release/Graphviz.exe
	@echo
	@echo CANDLING GRAPHVIZ GUI...
	@echo
	"$(CANDLE)" -out graphviz.wixobj graphviz.wxs

x86/Release/Graphviz.exe: ../*.cs ../*.resx ../Properties/*.cs
	@echo
	@echo BUILDING GRAPHVIZ GUI...
	@echo
	"$(MSBUILD)" "..\graphviz.csproj" -p:Configuration=Release -p:Platform=x86

#
# configure + make
#

$(GV_DIR)/cmd/dot/.libs/$(DOT): $(GV_DIR)/Makefile
	@echo
	@echo MAKING GRAPHVIZ...
	@echo
	if [[ -e $@ ]]; then $(MAKE) -C $(GV_DIR) clean; fi && \
	$(MAKE) -C $(GV_DIR)
	
$(GV_DIR)/Makefile: $(GV_DIR)/configure
	@echo
	@echo CONFIGURING GRAPHVIZ...
	@echo
	cd $(GV_DIR) && ./configure --enable-swig=no --enable-tcl=no --without-x --with-ipsepcola --with-gdiplus --with-platformsdkincludedir="$(PLATFORMSDK)\Include" --with-platformsdklibdir="$(PLATFORMSDK)\Lib" CFLAGS="-O2 -mms-bitfields -I$(LOCAL_INCLUDE)" CXXFLAGS="-O2 -mms-bitfields -I$(LOCAL_INCLUDE)" LDFLAGS="-L$(LOCAL_LIB)" GDLIB_CONFIG="$(LOCAL_BIN)/gdlib-config.exe" LEX="$(LOCAL_BIN)/flex.exe" PKG_CONFIG="$(LOCAL_BIN)/pkg-config.exe" PKG_CONFIG_PATH="$(LOCAL_LIB)/pkgconfig" YACC="$(LOCAL_BIN)/yacc.exe"
