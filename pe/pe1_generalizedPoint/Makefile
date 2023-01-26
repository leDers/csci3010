# Makefile 

CXX = g++ #compiler
CXXFLAGS = -std=c++20 -Wall #flags for the compiler (add -ggdb if you want to use gdb to debug!)

#runs for make all
all: all main clean

main: Point.o main.cpp
	$(CXX) $(CXXFlags) main.cpp -o main

Point.o: Point.cpp
	$(CXX) $(CXXFlags) -c Point.cpp

clean:
	rm Points.o main