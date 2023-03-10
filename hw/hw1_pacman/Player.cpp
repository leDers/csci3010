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
    
    if (is_human){
        Position p = {0,0};
        this->pos_ = p;
    }else{
        Position e = { (rand()%8)+1, (rand()%8)+1 };
        this->pos_ = e;
    }
    
    this->name_ = name;
    this->is_human_ = is_human;
    this->points_ = 0;
    this->has_Treasure_ = false;
    this->isDead_ = false;
    this->lives_ = 3;
    this->moves_ = 0;
}

/**
 * @brief Changes the value of player's points
 * 
 * @param x -- the value to change player points to
 */
void Player::ChangePoints(const int x){
    this->points_ += x;
}

/**
 * @brief Sets the new position of the player object
 * 
 * @param pos -- the position to change the player to
 */
void Player::SetPosition(Position pos){
    this->pos_ = pos;
}

/**
 * @brief Sets player object's setHasTrasure_ to true
 * 
 */
void Player::setHasTreasure(){
    this->has_Treasure_ = (!this->hasTreasure());
}

/**
 * @brief Checks to see if nan ENEMY player is dead
 * 
 * @param isdead -- the value to set isDead_ to
 */
void Player::setIsDead(bool isdead){
    this->isDead_ = isdead;
}

/**
 * @brief Update/ set the lives of player
 * 
 */
void Player::setLives(){
    this->lives_ -= 1;
}

/**
 * @brief Translates nearby valid positions to directions (Up, down, left, right)
 * 
 * @param other -- the other position 
 * @return std::string -- nearby locations
 */
std::string Player::ToRelativePosition(Position other){
    if (this->pos_.row-1 == other.row && this->pos_.col == other.col) { return "UP      W";}
    if (this->pos_.row+1 == other.row && this->pos_.col == other.col) { return "DOWN    S";}
    if (this->pos_.row == other.row && this->pos_.col-1 == other.col) { return "LEFT    A";}
    if (this->pos_.row == other.row && this->pos_.col+1 == other.col) { return "RIGHT   D";}
    else return "No relative Position";
}

/**
 * @brief Uses the overloaded '<<' operator to print player objects name and points
 * 
 * @return std::string -- a string reprensentation of player's name and points
 */
std::string Player::Stringify(){
    return ("Name: " + this->get_name() 
          + "\tTotal Moves: " +std::to_string(this->getMoves())
          + "\nPoints: " + std::to_string(this->get_points()) 
          + "\tLives: " + std::to_string(this->getLives())
          
    ); 
}

/**
 * @brief Gets the number of moves made by this player object
 * 
 * @return int -- the int value for number of moves made by a player
 */
int Player::getMoves(){
    return this->moves_;
}

/**
 * @brief Increment this player objects moves_ by 1
 * 
 */
void Player::incrementMoves(){
    this->moves_++;
}

