/*
    CSCI 3010 SP 23
    Leif Anders
    HW1 - Pacman
*/

#include <iostream>
#include "Player.h"

/*
    Constructor

    @param std::sting name -- the name of this player
    @param bool is_human -- player status; true if human, false if computer
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

/*
    @param const in x -- the value to change player points to
*/
void Player::ChangePoints(const int x){
    this->points_ = x;
}

/*
    @param Poisition pos -- the position to change the player to
*/
void Player::SetPosition(Position pos){
    this->pos_ = pos;
}

/*
    setHasTrasure to true
*/
void Player::setHasTreasure(){
    this->has_Treasure_ = true;
}

/*
    @param bool isdead -- the value to set isDead_ to 
*/
void Player::setIsDead(bool isdead){
    this->isDead_ = isdead;
}

/*
    set lives
*/
void Player::setLives(){
    this->lives_ = 3;
}


std::string Player::ToRelativePosition(Position other){

}

std::string Player::Stringify(){
    std::cout << this << std::endl; 
}

int Player::getMoves(){
    return this->moves_;
}

void Player::incrementMoves(){
    this->moves_++;
}

std::ostream & operator << (std::ostream &out, const Player &p){
    out << "Name: " << p.get_name();
    out << "Points: " << p.get_points();
    return out;
}


