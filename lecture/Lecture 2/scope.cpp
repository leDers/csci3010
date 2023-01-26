#include <iostream>
#include <string.h>
#include <vector>

// Leif Anders
// CSCI 3010 SP 23


// scope: "what can we see right here"
// - what variables/functions/other can we access from inside x, where x is a function, method, etc.

// 1) what happens in c++ if you try to acces a variable out of scope?
//  A: If we access a variable out of scope the program would likely crash or behave unexpectedly

// 2) what happens if we make everything global?
//  A: If we make everything global it leaves these variables susceptible to side effects from other functions calls. 


// Summary:
// pass-by-value vs. pass-by-reference
// pass-by-value: give the function a copy of the value
// pass-by-reference: give the address of the location of the value


// *************************************************


// When you are done: turn in your file on canvas

// Names (be sure to include the initial of your last name(s)!):
// Leif Anders

// 1) Write a function that demonstrates whether ints are pass-by-value or pass-by-reference
// (do not use pointers or c++ references in this function)
// Answer:
void prob1(int a){
    std::cout << "modifying values..." << std::endl;
    
    a+=10;

    std::cout << "int a:" << a << std::endl;
    std::cout << "returning to main..." << std::endl;

}

// 2) Write a function that tests demonstrates whether strings (std::string) are pass-by-value or pass-by-reference
// (do not use pointers or c++ references in this function)
// Answer:
void prob2(std::string b){
    std::cout << "modifying values..." << std::endl;
    
    b+="xxx";

    std::cout << "string b:" << b << std::endl;
    std::cout << "returning to main..." << std::endl;
}


// 3) Write a function that demonstrates whether arrays are pass-by-value or pass-by-reference
// recall: to initialize an array-- type name[] = {comma separated elements};
// (do not use pointers or c++ references in this function)
// Answer:
void prob3(int c[]){
    std::cout << "modifying values..." << std::endl;
    
    c[0] = 9;

    std::cout << "int c[]: {";
    for (int i =0; i < 3; i++){
        std::cout << c[i];
        if ( i < 2 ) std::cout << ", ";
    }
    std::cout << "}" << std::endl;

    std::cout << "returning to main..." << std::endl;
}

// 4) Write a function that demonstrates whether vectors are pass-by-value or pass-by-reference
// Answer:
void prob4(std::vector<int> d){
    std::cout << "modifying values..." << std::endl;

    d[0] = 9;
    std::cout << "vector d: {";
    for (auto i = 0; i<3 ; ++i) 
        std::cout << d[i] << ", ";

    std::cout << "}" << std::endl;

    std::cout << "returning to main..." << std::endl;

}


int main() {
    // code to call your functions goes here.

    // you may find it useful to print out values in main as well as inside your functions
    // to appropriately demonstrate whether the given type is pass-by-value or 
    // pass-by-reference

    // prob1 --- --- --- ---
    int a = 1;
    std::cout << "problem1..." << std::endl;
    std::cout << "int a:" << a << std::endl;
    std::cout << "entering call..." << std::endl;
    prob1(a);
    std::cout << "int a:" << a << std::endl << std::endl ;

    // prob2  --- --- --- ---
    std::string b = "b";
    std::cout << "problem2..." << std::endl;
    std::cout << "string b:" << b << std::endl;
    std::cout << "entering call..." << std::endl;
    prob2(b);
    std::cout << "string b:" << b << std::endl << std::endl;
    

    // prob3  --- --- --- ---
    int c[3] = {0,1,2};
    
    std::cout << "problem3..." << std::endl;
    std::cout << "int c[]: {";
    for (int i =0; i < 3; i++){
        std::cout << c[i];
        if ( i < 2 ) std::cout << ", ";
    }
    std::cout << "}" << std::endl;


    std::cout << "entering call..." << std::endl;
    prob3(c);
    std::cout << "int c[]: {";
    for (int i =0; i < 3; i++){
        std::cout << c[i];
        if ( i < 2 ) std::cout << ", ";
    }
    std::cout << "}" << std::endl << std::endl;

    // prob4  --- --- --- ---
    std::vector<int> d = {0,0,0};
    std::cout << "problem4..." << std::endl;
    std::cout << "vector d: {";
    for (auto i = 0; i<3 ; ++i) 
        std::cout << d[i] << ", "; 
    std::cout << "}" << std::endl;

    std::cout << "entering call..." << std::endl;
    prob4(d);
    std::cout << "vector d: {";
    for (auto i = 0; i < 3; ++i) 
        std::cout << d[i] << ", "; 
    std::cout << "}" << std::endl;


    // end --- --- --- ---
    return 0;
}
