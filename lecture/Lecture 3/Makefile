# This is an example make file

CXX = g++  # the compiler
CXXFLAGS = -std=c++2a -Wall  # flags for the compiler (use c++17 standards, turn on all optional warnings); add -ggdb if you want to use gdb to debug!

# runs for "make all"
all: test main 

# note that lines below targets must be
# TABBED in (not spaces!)
clean:
	rm test main 

test: test.cpp
	$(CXX) $(CXXFLAGS) test.cpp -o test

main: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o main
