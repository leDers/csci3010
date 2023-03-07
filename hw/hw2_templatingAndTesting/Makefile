CXX = g++
CXXFLAGS	= -std=c++2a -Wall
CXXTESTFLAGS = --coverage
CXXGDB = -ggdb 

.PHONY: main test read

all: main test read

read:
	$(CXX) $(CXXFLAGS) read.cpp -o read 

test:
	$(CXX) $(CXXFLAGS) test.cpp -o test 

main:
	$(CXX) $(CXXFLAGS) main.cpp -o main 

clean:
	rm main test read