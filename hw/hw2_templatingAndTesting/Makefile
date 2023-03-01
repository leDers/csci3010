CXX = g++
CXXFLAGS	= -std=c++2a -Wall
CXXTESTFLAGS = --coverage
CXXGDB = -ggdb 

.PHONY: main test

all: main test

test:
	$(CXX) $(CXXFLAGS) test.cpp -o test 

main:
	$(CXX) $(CXXFLAGS) main.cpp -o main 

clean:
	rm main test