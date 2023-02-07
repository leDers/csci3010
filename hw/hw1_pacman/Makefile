CXX = g++
CXXFLAGS = -std=c++2a -Wall

.PHONY: Player.o Game.o run_game

all: Player.o Game.o run_game

clean: 
	Player.o Game.o run_game

Player.o:
	$(CXX) $(CXXFLAGS) Player.cpp -c -o Player.o

Game.o:
	$(CXX) $(CXXFLAGS) Game.cpp -c -o Game.o

run_game: Player.o Game.o run_game.cpp
	$(CXX) $(CXXFLAGS) run_game.cpp Player.o Game.o -o run_game