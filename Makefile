CXX = g++
CXXFLAGS	= -std=c++2a -Wall
CXXTESTFLAGS = --coverage
CXXGDB = -ggdb

.PHONY: main

all: main

main:
	$(CXX) $(CXXFLAGS) main.cpp -o main
	
clean: 
	rm main