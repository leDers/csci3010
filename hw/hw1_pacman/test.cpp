/**
 * @file test.cpp
 * @author Leif Anders
 * @brief test.cpp for pacman hw1
 * @version 0.1
 * @date 2023-02-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Player.h"
#include "Game.h"

// Player --- --- --- --- --- --- --- ---

// SquareType  --- --- --- --- --- --- --- ---

TEST_CASE ("Square Type Tests"){
    
    int num_of_sqType = 9;
    for (int i = 0; i < num_of_sqType; i++ ){
        std::cout << SquareTypeStringify( static_cast<SquareType>(i) ) << std::endl;
    }
    
}

// Board --- --- --- --- --- --- --- ---

TEST_CASE ("Board Tests"){

    SECTION ("read from file check"){
        Board nuBoard = Board();
        std::cout << "board made!" << std::endl;
        std::cout << nuBoard << std::endl;
    }
}

// Game --- --- --- --- --- --- --- ---
