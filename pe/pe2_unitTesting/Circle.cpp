/*
CSCI 3010 SP 23
Leif Anders
PE2 - circles
*/

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

#include "Circle.h"

 /*
    @param unsigned int number: the value to copute the factorial of
    @return the factorial of the given number
 */
unsigned int Factorial( unsigned int number ){
    if (number <= 1) {return 1; }
    else{ return number * Factorial(number-1); } 
}


/*
    NOTE: The original constructor allowed circles to be made with 
    neagative radius. We avoid this now by defaulting a neagative radius
    to zero radius

    @param Point p: the point of circles center
    @param int rad: the radius of the circle, must be rad >= 0
    @return constructs circle object with given fields
*/
Circle::Circle(Point p, int rad){
    this->center_ = p;

    if (rad < 0) {
        std::cout << "\nCircle cannot have negative radius. \nSetting Radius to 0" << std::endl;
        this->radius_ = 0;
    }
    else {
        this->radius_ = rad;
    }
}

/*
    NOTE: the original overlap() failed to return true when: 
    - there was more than one over lapping point
    - similar circles 
    - smaller circle touches point of larger from the inside
    - generally, ANYTIME distance between centers was < sum(rad1,rad2)

    @param Circle &other: the other circle object to check overlap with
    @return true if overlap exisits, false if not
*/
bool Circle::Overlaps(Circle& other){
    // euclid distance between points
    double a = pow((this->center_.x - other.center_.x), 2);
    double b = pow((this->center_.y - other.center_.y), 2);
    double d = sqrt(a+b);

    // distance check
    if ( d > (this->radius_ + other.radius_) ) {
        return false;
    }
    else return true;
}

/*
    NOTE: in the original, this function failed to compute properly,
    returned integers rather than doubles/ precise areas

    @return the volume of areas circle -- forced to return as int
*/
int Circle::CalculateArea(){
    return (double)(M_PI * pow(this->radius_, 2));
}

/*
    NOTE: nothing to fix here, except potential

    @return expands the circle radius by 1
*/
void Circle::Expand(){
    this->radius_ +=1;
}

/*
    NOTE: original allowed radius to shink beyond 0. Here, we disallow that

    @return shrinks circles area by 1, but not beyond 0.
*/
void Circle::Shrink(){
    if (this->radius_ > 0) {
        this->radius_ -=1;
    }
    else {
        std::cout << "Cannot decrease radius below zero." << std::endl;
    }
}