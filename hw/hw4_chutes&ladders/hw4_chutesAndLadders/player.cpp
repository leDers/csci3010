#include "player.h"

Player::Player(int x, int y, int currValue, int diameter, QString name, int color, QGraphicsItem *parent)
    : QObject(nullptr), QGraphicsEllipseItem(parent)
{
    // set player's initial position and size
    x_ = x;
    y_ = y;
    prevValue_ = 0;
    currValue_ = currValue;
    diameter_ = diameter;
    setRect(x_, y_, diameter_, diameter_);

    name_ = name;
    color_ = color;
    undoCount_ = 3;
    rerollCount_ = 5;
    rollCount_ = 0;
    onBoard_ = false;

    // set player's color
    if (color_%4 == 0){
        setBrush(QBrush(Qt::red));
    }
    if (color_%4 == 1){
        setBrush(QBrush(Qt::yellow));
    }
    if (color_%4 == 2){
        setBrush(QBrush(Qt::green));
    }
    if (color_%4 == 3){
        setBrush(QBrush(Qt::blue));
    }

}

Player::Player(QGraphicsItem *parent)
    : QObject(nullptr), QGraphicsEllipseItem(parent)
{
    // set player's initial position and size
    x_ = 0;
    y_ = 0;
    prevValue_ = 0;
    currValue_ = 0;
    diameter_ = 0;
    setRect(x_, y_, diameter_, diameter_);

    name_ = "name";
    color_ = 0;
    undoCount_ = 0;
    rerollCount_ = 0;
    rollCount_ = 0;
    onBoard_ = false;

    // set player's color
    if (color_%4 == 0){
        setBrush(QBrush(Qt::red));
    }
    if (color_%4 == 1){
        setBrush(QBrush(Qt::yellow));
    }
    if (color_%4 == 2){
        setBrush(QBrush(Qt::green));
    }
    if (color_%4 == 3){
        setBrush(QBrush(Qt::blue));
    }

}

int Player::getX()
{
    return x_;
}

int Player::getY()
{
    return y_;
}

int Player::getPrevValue(){
    return prevValue_;
}

int Player::getCurrValue()
{
    return currValue_;
}

void Player::setX(int x)
{
    x_ = x;
    setRect(x_, y_, diameter_, diameter_);
}

void Player::setY(int y)
{
    y_ = y;
    setRect(x_, y_, diameter_, diameter_);
}

void Player::setPrevValue(int v){
    prevValue_ = v;
}

void Player::setCurrValue(int v){
    currValue_ = v;
}

void Player::useUndo(){
    undoCount_--;
}

int Player::getUndoCount() {
    return undoCount_;
}

void Player::useReroll(){
    rerollCount_--;
}

int Player::getRerollCount() {
    return rerollCount_;
}

void Player::useRoll(){
    rollCount_++;
}

int Player::getRollCount() {
    return rollCount_;
}
