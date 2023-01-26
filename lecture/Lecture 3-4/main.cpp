#include <iostream>
#include <vector>
#include "functions_to_implement.cpp"

// returns -1 if the number is negative and 1 if positive
extern double Sign(double num);

// takes an int, n, and returns the factorial of that int (n!)
extern int Factorial(int n);

// Sums all numbers in a vector and returns the resulting value
extern int Sum(std::vector<int> nums);

int main(){
    // one
    std::cout << Sign(-38) << std::endl;
    std::cout << Sign(0) << std::endl;
    std::cout << Sign(42) << std::endl;

    // two
    std::cout << Factorial(1) << std::endl;
    std::cout << Factorial(6) << std::endl;
    std::cout << Factorial(8) << std::endl;

    // three
    std::vector<int> vect1;
    std::vector<int> vect2;
  
    vect1.push_back(10);
    vect1.push_back(20);
    vect1.push_back(30);

    vect2.push_back(-30);
    vect2.push_back(0);
    vect2.push_back(30);

    std::cout << Sum(vect1) << std::endl;
    std::cout <<Sum(vect2) << std::endl;

    return 0;
}