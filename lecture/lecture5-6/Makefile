# This is an example make file

CXX = g++  # the compiler
CXXFLAGS = -std=c++2a -Wall  # flags for the compiler (use c++17 standards, turn on all optional warnings); add -ggdb if you want to use gdb to debug!

.PHONY: run_library Library.o

# runs for "make all"
all: Library.o run_library 

# note that lines below targets must be
# TABBED in (not spaces!)
clean:
	rm Library.o run_library 

Library.o: 
	$(CXX) $(CXXFLAGS) Library.cpp -c -o Library.o

run_library: Library.o  run_library.cpp 
	$(CXX) $(CXXFLAGS) run_library.cpp Library.o -o run_library
