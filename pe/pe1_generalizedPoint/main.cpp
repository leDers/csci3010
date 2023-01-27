#include <iostream>
#include <vector>
#include "Point.cpp"


int main(){
    // part 1 --- --- ---
    // create three points
    // calculate distance between them
    // report coorinates and distances
    Point p1(2);
    
    std::vector<int> v2 = {1,1};
    Point p2(v2);

    std::vector<int> v3 = {-1,-1};
    Point p3(v3);

    std::cout << "Distance beween p1 and p2: " << p1.distance(p2) << std::endl;
    std::cout << "Distance beween p2 and p3: " << p2.distance(p3) << std::endl;
    std::cout << "Distance beween p3 and p1: " << p3.distance(p1) << std::endl;

    // part 2 --- --- ---
    // translate one point by '+' amount
    // report cooridnates and distances
    // translate SAME POINT by '-' amount
    // report cooridnates and distances

    int modify = 2;
    p3.translate(modify);
    std::cout << "translating point..." << std::endl;
    std::cout << "Distance beween p1 and p2: " << p1.distance(p2) << std::endl;
    std::cout << "Distance beween p2 and p3: " << p2.distance(p3) << std::endl;
    std::cout << "Distance beween p3 and p1: " << p3.distance(p1) << std::endl;

    modify = -2;
    p3.translate(modify);
    std::cout << "translating point..." << std::endl;
    std::cout << "Distance beween p1 and p2: " << p1.distance(p2) << std::endl;
    std::cout << "Distance beween p2 and p3: " << p2.distance(p3) << std::endl;
    std::cout << "Distance beween p3 and p1: " << p3.distance(p1) << std::endl;

    return 0;
}