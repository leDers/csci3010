// CSCI 3010 SP 23
// Leif Anders
// PE2 - circles

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

#include "Circle.h"

// constructor
/*
    The original constructor allowed circles to be made with 
    neagative radius. We avoid this now by defaulting a neagative radius
    to zero radius
*/
Circle::Circle(Point p, int rad){
    center_ = p;

    if (rad < 0) {
        std::cout << "\nCircle cannot have negative radius. \nSetting Radius to 0" << std::endl;
        radius_ = 0;
    }
    radius_ = rad;
}

//returns the radius of the circle
/*
    there is no need to modify this function
*/
int Circle::get_radius() const { return radius_; }

//returns the center of the circle
/*
    there is no need to modify this function
*/
Point Circle::get_center() const { return center_; }

// returns true iff this circle shares any points with the other one
/*
    the original overlap() failed to return true when: 
    - there was more than one over lapping point
    - similar circles 
    - smaller circle touches point of larger from the inside
*/
bool Circle::Overlaps(Circle& other){
    double a = pow((this->center_.x - other.center_.x), 2);
    double b = pow((this->center_.y - other.center_.y), 2);
    double d = sqrt(a+b);

    if ( d > (this->radius_ + other.radius_) 
        || d < abs(this->radius_ - other.radius_)) {
            return false;
        }
    else return true;
}

// returns the area of this circle
/*
    in the original, this function failed to compute properly,
    returned integers rather than doubles/ precise areas
*/
int Circle::CalculateArea(){
    return 2 * M_PI * pow(this->radius_, 2)
;}

// increases the radius by one
/*
    nothing to fix here
*/
void Circle::Expand(){
    this->radius_ +=1;
}


// decreases the radius by one
/*
    original allowed radius to shink beyond 0
    here, we disallow that
*/
void Circle::Shrink(){
    if (this->radius_ > 0) {
        this->radius_ -=1;
    }
    else {
        std::cout << "Cannot decrease radius below zero." << std::endl;
    }
}