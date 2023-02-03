CXX = g++
CXXFLAGS	= -std=c++17 -Wall
CXXTESTFLAGS = --coverage # can be used to generate files that help calculate unit test coverage
CXXGDB = -ggdb 

# .PHONY creates
.PHONY: main test oldTest Circle.o 

all: test oldTest

clean: 
	rm test myTest Circle.o

# my Circle.o implementation
Circle.o: Circle.cpp
	$(CXX) $(CXXFLAGS) -c Circle.cpp -o Circle.o

test: Circle.o test.cpp
	$(CXX) $(CXXFLAGS) test.cpp Circle.o -o test

main: Circle.o main.cpp
	$(CXX) $(CXXFLAGS) main.cpp Circle.o -o main

# mv Circl.o givenCircle.o
oldTest: givenCircle.o test.cpp
	$(CXX) $(CXXFLAGS) test.cpp givenCircle.o -o oldTest

