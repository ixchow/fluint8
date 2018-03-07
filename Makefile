
UNAME=$(shell uname -s)
ifeq ($(UNAME),Darwin)
	#OSX/llvm
	CPP=clang++ -std=c++14 -g -Wall -Werror
else
	#assume Linux/g++
	CPP=g++ -g -Wall -Werror
endif


test_fluint8 : test_fluint8.cpp fluint8.hpp
	$(CPP) -otest_fluint8 test_fluint8.cpp
