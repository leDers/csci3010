// CSCI 3010 Sp 23
// Leif Anders
// HW1 - generalized point

// header guard
#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <vector>

class Point{
    private:
        // members --- --- ---
        // dimension / cooridnates 
        std::vector<int> dim_;
    
    public:
        // methods --- --- ---
        Point(int n); //default constructor
        Point(std::vector<int> v); // vector constructor

        std::vector<int> getter();   // get cooridnates
        int setter(std::vector<int> v);   // set cooridnates

        float distance(Point b);   // compute distance
        void translate(int n);    // translate point
};

#endif