#include <iostream>
#include <string>
#include <vector>

// Names:   Leif Anders
//
//


// we'd like to write a function that is applicable to many types but
// we don't want to copy paste everything

// For example, here is a templated Add function
template <typename T>
T Add(T v1, T v2) {
    return v1 + v2;
}

// 6) implement a templated version of AddToValues, "AddToValues2".

template <typename T, typename U>
T AddtoValues2(T v, U u){
    for (long unsigned int i = 0; i < v.size(); i++){
        v[i] += u;
    }
    return v;
}

struct myStruct{
    int a_ = 0;
    friend std::ostream& operator<<(std::ostream& os, const myStruct& m){
        os << m.a_;
        return os;
    }

    friend myStruct& operator+= ( myStruct& lhs, const myStruct& rhs){
        lhs.a_ += rhs.a_;
        return lhs;
    } 
};



int main() {
    // 7) call AddToValues2, passing in an int vector and another int.
    std::vector<int> vB = {1,2,3,4,5};
    int y = 1;

    std::vector<int> vb = AddtoValues2(vB,y);
    std::cout << "first call..." << std::endl;
    for (int i : vb){
        std::cout << i;
    }
    std::cout << std::endl;

    // 8) compile this file to object code
    // g++ -Wall -std=c++17 exercises2.cpp -c
    // then run: nm -C exercises2.o | grep "AddToValues2"
    // How many versions of the AddToValues2 function are in the
    // compiled object code? Copy + paste the relevant lines here:


    // 9) call AddToValues2, passing in a vector of a non-int type and a value that you can add
    // successfully to the elements
    std::vector<double> vC = {1.0, 2.0, 3.0, 4.0, 5.0};
    double z = 0.5;

    std::vector<double> vc = AddtoValues2(vC,z);
    std::cout << "second call..." << std::endl;
    for (double i : vc){
        std::cout << i;
    }
    std::cout << std::endl;

    // 10) compile this file to object code
    // g++ -Wall -std=c++17 exercises2.cpp -c
    // then run: nm -C exercises2.o | grep "AddToValues2"
    // How many versions of the AddToValues2 function are in the
    // compiled object code? Copy + paste the relevant lines here:

    // 11) Experiment to find calls to this function that you would like to work but that do
    // not yet work. for each function call that doesn't work, comment about what type of 
    // error is produced.

    // experiment 1 (string, int)
    // FAILS
    std::vector<std::string> vD = {"a", "b", "c"};
    std::vector<std::string> vd = AddtoValues2(vD,y);

    std::cout << "experiment 1..." << std::endl;
    for (std::string i : vd){
        std::cout << i;
    }
    std::cout << std::endl;

    // experiment 2 (string, string)
    // WORKS
    std::string s = "x";
    std::vector<std::string> vd2 = AddtoValues2(vD,s);
    
    std::cout << "experiment 1..." << std::endl;
    for (std::string i : vd2){
        std::cout << i;
    }
    std::cout << std::endl;

    // 12) Create a struct that has an int field. Instantiate a vector of these structs.
    // Instantiate another instance of this struct.
    std::vector<myStruct> vec_myStruct(5);
    myStruct struct1;
    struct1.a_= 1;

    std::vector<myStruct> out = AddtoValues2(vec_myStruct, struct1);
    std::cout << "struct exp..." << std::endl;
    for (myStruct i : out){
        std::cout << i;
    }
    std::cout << std::endl;
    
    // 13) Call AddToValues2 w/ the vector of structs and single struct from #12
    // Is there an error? If yes, what is it?
    //
    // Answer: 
    //      yes error. cannot '<<' myStruct object.
    //      we need to overload the '<<' operator to print this struct
    //      it also does not add properly so we need to overload '+=' 

    // 14) If there was an error, attempt to fix it.
}
