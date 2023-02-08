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
std::string SquareTypeStringify(SquareType sq);

// Board --- --- --- --- --- --- --- ---

/**
 * @brief Construct a new Board:: Board object
 * 
 */
Board::Board(){

}

/**
 * @brief Set the Square Value object
 * 
 * @param pos -- the position of square that is to be changed
 * @param value -- the valuse to change a square to
 */
void Board::SetSquareValue(Position pos, SquareType value){

}

/**
 * @brief Get the Moves object
 * 
 * @param p -- pointer for player object
 * @return std::vector<Position> -- the possible positions a player/enemy could move to
 */
std::vector<Position> Board::GetMoves(Player *p){

}

/**
 * @brief 
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
 * @brief 
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
 * @brief Construct a new Game object
 * 
 */
Game::Game(){

}

/**
 * @brief 
 * 
 * @param human -- pointer to human player
 * @param enemylist -- list of enemy players
 * @param enemies   -- number of enemies 
 */
void Game::NewGame(Player *human,std::vector<Player*> enemylist, const int enemies){

}

/**
 * @brief 
 * 
 * @param p -- pointer to human player
 * @param enemylist -- vector list of enemy players
 */
void Game::TakeTurn(Player *p,std::vector<Player*> enemylist){

}

/**
 * @brief 
 * 
 * @param p  -- pointer to enemy player
 */
void Game::TakeTurnEnemy(Player *p){

}

/**
 * @brief 
 * 
 * @param p -- pointer to human player
 * @return true -- if human player isDead_ == true
 * @return false -- if human player isDead == false
 */
bool Game::IsGameOver(Player *p){

}

/**
 * @brief 
 * 
 * @return true -- if all pellets are gone
 * @return false -- if any number of pellets remain
 */
bool Game::CheckifdotsOver(){

}

/**
 * @brief 
 * 
 * @param p -- pointer to human player
 * @return std::string -- sting info about the game's conditions after it is over
 */
std::string Game::GenerateReport(Player *p){

}
