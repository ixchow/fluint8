.PHONY : all

all : \
	ieee754-binary32.pdf \



UNAME := $(shell uname)

ifeq ($(UNAME),Darwin)
	INKSCAPE := /Applications/Inkscape.app/Contents/Resources/bin/inkscape
endif

ifeq ($(UNAME),Linux)
	INKSCAPE := inkscape
endif


%.pdf : %.svg
	$(INKSCAPE) --without-gui --file=`pwd`/$< --export-area-page --export-background=white --export-background-opacity=1.0 --export-pdf=`pwd`/$@ --export-text-to-path
