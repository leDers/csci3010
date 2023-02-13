/**
 * @file Game.cpp
 * @author Leif Anders 
 * @brief CSCI 3010 -- Hw1. 
 *        CPP file for game object
 * @version 0.1
 * @date 2023-02-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "Game.h"

// SquareType  --- --- --- --- --- --- --- ---

/**
 * @brief this function takes an enumerated squareType and returns it as a string
 * 
 * @param sq -- the enum class of Square type to be stringified
 * @return std::string -- the string equivalent of the square type
 */
std::string SquareTypeStringify(SquareType sq){
    switch (sq){
        case SquareType::Wall: return "\U0001F7E6"; break;            // blue square
        case SquareType::Dots: return "\U0001F7E1"; break;            // yellow circle
        case SquareType::Pacman: return "\U0001F604"; break;          // smiley face 
        case SquareType::Treasure: return "\U0001F344"; break;        // mushroom
        case SquareType::Enemies: return "\U0001F47B"; break;         // ghost
        case SquareType::Empty: return "\U000026AA"; break;             // white circle small
        case SquareType::PowerfulPacman: return "\U0001F608"; break;  // steamy nose face 
        case SquareType::Trap: return "\U0001F525"; break;            // fire
        case SquareType::EnemySpecialTreasure: return "\U0001F480"; break; // skull
        default: return "bad tile";      
    } 
}

/**
 * @brief converts int array into squaretype array
 * 
 */
SquareType intToSquare(int x){
    
    switch(x){
        case 0: return SquareType::Wall;
        case 1: return SquareType::Dots;
        case 2: return SquareType::Pacman;
        case 3: return SquareType::Treasure;
        case 4: return SquareType::Enemies;
        case 5: return SquareType::Empty;
        case 6: return SquareType::PowerfulPacman;
        case 7: return SquareType::Trap;
        case 8: return SquareType::EnemySpecialTreasure;
    }

}

// Board --- --- --- --- --- --- --- ---

/**
 * @brief Construct a new Board:: Board object
 * 
 */
Board::Board(){
    std::ifstream in_file("board1.txt");

    // create int board
    if (in_file){
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){

                in_file >> this->arr2_[i][j];
            }
        }
    }
    else if (!in_file){
        std::cout << "invalid board.txt" << std::endl;
    }

    // convert int board into squareType board
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            this->arr_[i][j] = intToSquare(this->arr2_[i][j]);
        }
    }
}

/**
 * @brief Get the square value object
 * 
 * @param pos -- the position on board to retreive value
 * @return SquareType -- the squretpe that is returned
 */
SquareType Board::get_square_value(Position pos) const{
    return this->arr_[pos.row][pos.col];
}

/**
 * @brief Set the Square Value object at the given position
 * 
 * @param pos -- the position of square that is to be changed
 * @param value -- the valuse to change a square to
 */
void Board::SetSquareValue(Position pos, SquareType value){
    this->arr_[pos.row][pos.col] = value;
}

/**
 * @brief Get the the possible moves that the player obj. can move to
 * 
 * @param p -- pointer for player object
 * @return std::vector<Position> -- the possible positions a player/enemy could move to
 */
std::vector<Position> Board::GetMoves(Player *p){

}

/**
 * @brief Move a player to a new position
 * 
 * @param p -- pointer for the player object
 * @param pos -- new position to move player too
 * @param enemylist -- vector of enemy player pointers
 * @return true -- if move was successful
 * @return false -- if move was failed
 */
bool Board::MovePlayer(Player *p, Position pos, std::vector<Player*> enemylist){

}

/**
 * @brief Move any enemy toa new location
 * 
 * @param p -- pointer for the player object
 * @param pos -- the position to move the enemy to
 * @return true -- if move was successful
 * @return false -- if move was failure
 */
bool Board::MoveEnemy(Player *p, Position pos){
    
}

// Game --- --- --- --- --- --- --- ---

/**
 * @brief Construct a new Game::Game object
 * 
 */
Game::Game(){

}

/**
 * @brief Create a new game
 * 
 * @param human -- pointer to human player
 * @param enemylist -- list of enemy players
 * @param enemies   -- number of enemies 
 */
void Game::NewGame(Player *human,std::vector<Player*> enemylist, const int enemies){

}

/**
 * @brief Sequence for human player's turn
 * 
 * @param p -- pointer to human player
 * @param enemylist -- vector list of enemy players
 */
void Game::TakeTurn(Player *p,std::vector<Player*> enemylist){

}

/**
 * @brief Sequence for enemy players turn
 * 
 * @param p  -- pointer to enemy player
 */
void Game::TakeTurnEnemy(Player *p){

}

/**
 * @brief Checks human players isDead_ status to see if game is over
 * 
 * @param p -- pointer to human player
 * @return true -- if human player isDead_ == true
 * @return false -- if human player isDead == false
 */
bool Game::IsGameOver(Player *p){

}

/**
 * @brief Checks if all pellets are gone from board
 * 
 * @return true -- if all pellets are gone
 * @return false -- if any number of pellets remain
 */
bool Game::CheckifdotsOver(){

}

/**
 * @brief Generates a report of game statistics
 * 
 * @param p -- pointer to human player
 * @return std::string -- sting info about the game's conditions after it is over
 */
std::string Game::GenerateReport(Player *p){

}
