CXX = g++
CXXFLAGS	= -std=c++17 -Wall
CXXTESTFLAGS = --coverage
CXXGDB = -ggdb 

.PHONY: main test

all: main test

clean:
	rm main test

main:
	$(CXX) $(CXXFLAGS) pe3_references.cpp -o main 

test:
	$(CXX) $(CXXFLAGS) test.cpp -o test 