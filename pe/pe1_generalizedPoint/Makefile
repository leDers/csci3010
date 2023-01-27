# Makefile 

CXX = g++ #compiler
CXXFLAGS = -std=c++20 -Wall #flags for the compiler (add -ggdb if you want to use gdb to debug!)

# .PHONY creates
.PHONY: main Point.o 

#runs for make all
all: main

main: Point.o main.cpp
	$(CXX) $(CXXFlags) main.cpp -o main

Point.o: Point.cpp
	$(CXX) $(CXXFlags) -c Point.cpp -o Point.o

clean:
	rm Point.o main