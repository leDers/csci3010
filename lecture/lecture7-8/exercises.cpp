#include <iostream>
#include <string>
#include <vector>

// Names:
//      Leif Anders
//


// 1) implement two functions, AddToValues(std::vector<int> v1, int v2)
// and AddToValues(std::vector<double> v1, double v2)

// NEED return type because vectors are pass by value

std::vector<int> AddToValues(std::vector<int> v1, int v2){
    for (long unsigned int i = 0; i < v1.size(); i++){
        v1[i] += v2;
    }
    return v1;
}

std::vector<double> AddToValues(std::vector<double> v1, double v2){
    for (long unsigned int i = 0; i < v1.size(); i++){
        v1[i] += v2;
    }
    return v1;
}

// 2) Do your AddToValues functions have return values? why/ why not?
// Answer:
// Yes. Because we are not modifying the vector itself but perform a function on a copy of it to remap it to new values.

int main() {
    // 3) Instantiate an int vector
    std::vector<int> vA = {1,2,3,4,5};

    // 4) call AddToValues, passing in your int vector and another int.
    int x = 1;
    AddToValues(vA, x);

    // 5) compile this file to object code
    // g++ -std=c++17 -Wall exercises.cpp -c

    // then run the command: nm -C exercises.o | grep "AddToValues"
    // How many versions of the AddToValues function are in the
    // compiled object code? Copy + paste the relevant lines here:

    // Answer:
    //      nm -C exercises.o | grep "AddToValues"
    //      0000000000000317 t _GLOBAL__sub_I__Z11AddToValuesSt6vectorIiSaIiEEi
    //      00000000000000b0 T AddToValues(std::vector<double, std::allocator<double> >, double)
    //      0000000000000000 T AddToValues(std::vector<int, std::allocator<int> >, int)

    // If the -C flag isn't working, you can omit it and still complete the exercise--this flag
    // makes the output easier to read but isn't strictly necessary
}
