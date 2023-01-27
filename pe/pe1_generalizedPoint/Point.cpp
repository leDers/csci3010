// CSCI 3010 Sp 23
// Leif Anders
// HW1 - generalized point

#include <iostream>
#include <vector>
#include <cmath>

#include "Point.h"

    Point::Point(int n){
        // int constructor
        // a "default" constructor takes one integer, n, and constructs a point of n dimensions at the origin
        dim_ = std::vector<int> (n,0);
    }
    Point::Point(std::vector<int> v){
        // vector constructo
        // second constructor that takes either a vector or an array of integers as an argument. 
        dim_ = v;
    }

    std::vector<int> Point::getter(){
        // get cooridnates at dimension n
        return dim_;
    }
    int Point::setter(std::vector<int> v){
        // set cooridnates
        dim_ = v;
        return 0; 
    }

    float Point::distance(Point b){
        // compute distance
        // pass by value
        // distance across all dimensional points

        // catch unequal dim
        if (this->dim_.size() != b.dim_.size()){
            std::cout << "Dimensions of points not equal" << std::endl; 
            return 0; // or error??
        }
        else{
            float sum = 0;
            for (int i = 0; i< this->dim_.size(); i++){
                sum += pow(((float)this->dim_.at(i) - (float)b.dim_.at(i)), 2);
            }
            return sqrt(sum);
        }
    }
    void Point::translate(int n){
        // translate point
        // pass by reference
        // call setter on passed point
        for (int i=0; i < dim_.size(); i++){
            this->dim_.at(i) += n;
        }
    }
