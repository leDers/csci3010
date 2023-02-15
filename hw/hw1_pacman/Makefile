# CSCI 3010 SP 23
# Leif Anders
# HW1 - Pacman

# To Run Unit Tests:
# make && ./test

CXX = g++
CXXFLAGS = -std=c++2a -Wall
OBJECTS = Player.o Game.o

.PHONY: Player.o Game.o test main

all: Player.o Game.o test main

Player.o: Player.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

Game.o: Game.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

test: $(OBJECTS) test.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

main: $(OBJECTS) main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean: 
	rm Player.o Game.o test main

# NOTE: See how the old way (below) lack dependencies 
# Player.o:
# 	$(CXX) $(CXXFLAGS) Player.cpp -c -o Player.o

# Game.o:
# 	$(CXX) $(CXXFLAGS) Game.cpp -c -o Game.o

# test: Player.o Game.o test.cpp
# 	$(CXX) $(CXXFLAGS) test.cpp Player.o Game.o -o test

# main: Player.o Game.o main.cpp
# 	$(CXX) $(CXXFLAGS) main.cpp Player.o Game.o -o main