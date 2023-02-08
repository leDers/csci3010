/**
 * @file Player.cpp
 * @author Leif Anders 
 * @brief CSCI 3010 -- Hw1. 
 *        CPP file for game object
 * @version 0.1
 * @date 2023-02-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include "Player.h"

// Player --- --- --- --- --- --- --- ---

/**
 * @brief Construct a new Player:: Player object
 * 
 * @param name -- the name of this player
 * @param is_human -- player status; true if human, false if computer
 */
Player::Player(const std::string name, const bool is_human){
    this->name_ = name;
    this->is_human_ = is_human;

    // this->pos_ = ??
    this->points_ = 0;
    this->has_Treasure_ = false;
    this->isDead_ = false;
    // this-> lives -- in Player.h
    this->moves_ = 0;
}

/**
 * @brief changes the value fo player's points
 * 
 * @param x -- the value to change player points to
 */
void Player::ChangePoints(const int x){
    this->points_ = x;
}

/**
 * @brief set's the new position of the player object
 * 
 * @param pos -- the position to change the player to
 */
void Player::SetPosition(Position pos){
    this->pos_ = pos;
}

/**
 * @brief setHasTrasure_ to true
 * 
 */
void Player::setHasTreasure(){
    this->has_Treasure_ = true;
}

/**
 * @brief checks to see if nan ENEMY player is dead
 * 
 * @param isdead -- the value to set isDead_ to
 */
void Player::setIsDead(bool isdead){
    this->isDead_ = isdead;
}

/**
 * @brief update/ set the lives of player
 * 
 */
void Player::setLives(){
    this->lives_ = 3;
}

/**
 * @brief translates nearby valid positions to directions (Up, down, left, right)
 * 
 * @param other -- the other player 
 * @return std::string -- nearby locations
 */
std::string Player::ToRelativePosition(Position other){

}

/**
 * @brief uses the overloaded '<<' operator to print players name and points
 * 
 * @return std::string -- a string reprensentation of player's name and points
 */
std::string Player::Stringify(){
    std::cout << this << std::endl; 
}

/**
 * @brief gets the number of moves made by this player object
 * 
 * @return int -- the int value for number of moves made by a player
 */
int Player::getMoves(){
    return this->moves_;
}

/**
 * @brief increment this player objects moves_ by 1
 * 
 */
void Player::incrementMoves(){
    this->moves_++;
}