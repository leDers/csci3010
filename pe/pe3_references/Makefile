CXX = g++
CXXFLAGS	= -std=c++17 -Wall
CXXTESTFLAGS = --coverage
CXXGDB = -ggdb 

.PHONY: main test

all: test main

main:
	$(CXX) $(CXXFLAGS) main.cpp -o main 

test:
	$(CXX) $(CXXFLAGS) test.cpp -o test 

clean:
	rm main test