// CSCI 3010 SP 23
// Leif Anders
// PE2 - circles

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

#include "Circle.h"

// constructor
Circle::Circle(Point p, int rad){
    center_ = p;

    if (rad < 0) {
        std::cout << "Circle cannot have negative radius. \nPlease try again." << std::endl;
    }
    radius_ = rad;
}

//returns the radius of the circle
int Circle::get_radius() const { return radius_; }

//returns the center of the circle
Point Circle::get_center() const { return center_; }

// returns true iff this circle shares any points with the other one
bool Circle::Overlaps(Circle& other){
    double a = pow((this->center_.x - other.center_.x), 2);
    double b = pow((this->center_.y - other.center_.y), 2);
    double d = sqrt(a+b);

    if ( d > (this->radius_ + other.radius_) ) return false;
    else return true;
}

// returns the area of this circle
// should this be flaot/ double?
int Circle::CalculateArea(){
    return 2 * M_PI * pow(this->radius_, 2)
;}

// increases the radius by one
void Circle::Expand(){
    this->radius_ +=1;
}

// decreases the radius by one
void Circle::Shrink(){
    if (this->radius_ > 0) {
        this->radius_ -=1;
    }
    else {
        std::cout << "Cannot decrease radius below zero." << std::endl;
    }
}