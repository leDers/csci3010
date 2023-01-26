// header guard
#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <vector>

class Point{
    private:
        // members --- --- ---
        std::vector<int> dimensions;
    
    public:
        // methods --- --- ---
        Point(int n); //default constructor
        Point(std::vector<int> v); // vector constructor

        int getter(int i);   // get cooridnates
        int setter(int n, int i);   // set cooridnates

        float distance(Point a, Point b);   // compute distance
        void translate(Point a, int n);    // translate point
};

#endif