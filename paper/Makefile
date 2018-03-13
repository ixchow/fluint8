.PHONY : all

all : \
	ieee754-binary32.pdf \
	fmodf.pdf \



UNAME := $(shell uname -s)

ifeq ($(UNAME),Darwin)
	INKSCAPE := /Applications/Inkscape.app/Contents/Resources/bin/inkscape
	CPP := clang++ -std=c++14 -g -Wall -Werror
endif

ifeq ($(UNAME),Linux)
	INKSCAPE := inkscape
	CPP := g++ -g -Wall -Werror
endif


%.pdf : %.svg
	$(INKSCAPE) --without-gui --file=`pwd`/$< --export-area-page --export-background=white --export-background-opacity=1.0 --export-pdf=`pwd`/$@ --export-text-to-path

% : %.cpp
	$(CPP) -o '$@' '$<'

and_table.tex : make_and_table
	./make_and_table > and_table.tex

milt_graph.csv : make_milt_graph
	./make_milt_graph > milt_graph.csv

mod_graph.csv : make_mod_graph
	./make_mod_graph > mod_graph.csv

#NOTE:
#gnuplot> plot 'mod_graph.csv' using 1:3 title 'fmodf', 'mod_graph.csv' using 1:2 title 'x - a + c - c'

floor_graph.csv : make_floor_graph
	./make_floor_graph > floor_graph.csv

#NOTE: floor.R
