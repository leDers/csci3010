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
TEST_CASE ("Player"){

    SECTION("INIT TEST"){
        Position p = {0,0};
        
        std::string name = "Leif";
        bool is_human = true;
        Player nu = Player(name, is_human);

        REQUIRE(nu.get_name() == "Leif");
        REQUIRE(nu.get_points() == 0 );
        REQUIRE(nu.get_position() == p);
        REQUIRE(nu.is_human() == true);
        REQUIRE(nu.isDead() == false );
        REQUIRE(nu.getLives() == 3);
        REQUIRE(nu.getMoves() == 0);
    }

}

// SquareType  --- --- --- --- --- --- --- ---

TEST_CASE ("Square Type Tests"){
    // testing squaretype stringify
    int num_of_sqType = 9;
    std::cout << "Emoji Test:\n";
    for (int i = 0; i < num_of_sqType; i++ ){
        std::cout << SquareTypeStringify( static_cast<SquareType>(i) ) << " ";
    } std::cout << "\n";
    
}

// Board --- --- --- --- --- --- --- ---

TEST_CASE ("Board Tests"){
    // testing constructors
    Board b = Board();
    Player *p = new Player("Leif", true);
    std::vector<Player*> e;

    SECTION ("read from file check"){
        std::cout << "Print Board Test:\n" << b << std::endl;
    }

    // testing getMoves() and relativePosition()
    SECTION("test moves"){
        std::vector<Position> v = b.GetMoves(p);

        std::cout << "Print Relative Direction Test:\n";
        for (long unsigned int i = 0; i < v.size(); i++){
            std::cout << p->ToRelativePosition(v[i]) << " ";
        } std::cout << "\n";
    }

    // testing MovePlayer()
    SECTION("Test Moving"){
        Position p1 = {0,1};
        Position p2 = {1,1};

        b.MovePlayer(p, p1, e);
        std::cout << "First Move:\n" << b;

        b.MovePlayer(p, p2, e);
        std::cout << "Second Move:\n"<< b;
    }
}

// Game --- --- --- --- --- --- --- ---
