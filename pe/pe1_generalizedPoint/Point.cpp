#include <iostream>
#include <vector>
#include <cmath>

#include "Point.h"

    Point::Point(int n){
        // int constructor
        dimensions = std::vector<int> (0,n);
    }
    Point::Point(std::vector<int> v){
        // vector constructo
        dimensions = v;
    }

    int Point::getter(int i){
        // get cooridnates at dimension n
        return dimensions.at(i);
    }
    int Point::setter(int n, int i){
        // set cooridnates
        dimensions.at(i) == n;
        return 0; 
    }

    float Point::distance(Point a, Point b){
        // compute distance
        // pass by value
        // distance across all dimensional points

        // catch unequal dim
        if (a.dimensions.size() != b.dimensions.size()){
            std::cout << "Dimensions of points not equal" << std::endl; 
            return 0; // or error??
        }
        else{
            float sum = 0;
            for (int i = 0; i<dimensions.size(); i++){
                sum += pow(((float)a.dimensions.at(i) - (float)b.dimensions.at(i)), 2);
            }
            return sqrt(sum);
        }
    }
    void Point::translate(Point a, int n){
        // translate point
        // pass by reference
        // call setter on passed point
        for (int i=0; i < dimensions.size(); i++){
            a.dimensions.at(i) += n;
        }
    }
