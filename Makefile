CXX = g++
CXXFLAGS	= -std=c++2a -Wall
CXXTESTFLAGS = --coverage
CXXGDB = -ggdb

.PHONY: main User.o Product.o Driver.o

all: main

main: User.o Product.o Driver.o
	$(CXX) $(CXXFLAGS) $? main.cpp -o $@

User.o: User.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

Product.o: Product.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

Driver.o: Driver.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

clean: 
	rm main User.o Product.o Driver.o