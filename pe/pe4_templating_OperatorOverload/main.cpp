/**
 * @file main.cpp
 * @author Leif Anders
 * @brief  The main file for pe4
 * @version 0.1
 * @date 2023-02-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Compare.h"

class myClass{
    private:
        int x_ = 0;

    public:
        myClass() {this->x_ = 0;}
        myClass(int x) {this->x_ = x;}

        friend std::ostream& operator<<(std::ostream& os, const myClass& m){
            os << m.x_;
            return os;
        }

        friend bool operator== ( const myClass& lhs, const myClass& rhs){
            return (lhs.x_ == rhs.x_);
        } 

        friend bool operator< ( const myClass& lhs, const myClass& rhs){
            return (lhs.x_ < rhs.x_);
        }

        friend bool operator> ( const myClass& lhs, const myClass& rhs){
            return (lhs.x_ > rhs.x_);
        }

};

int main(){

    // int values --- --- ---
    std::vector<int> int_vec = {1, 2, 3, 4, 5};
    int int_val= 3;
    Compare<int> int_Compare(int_vec);

    std::vector<int> int_less = int_Compare.getLessThan(int_val);
    std::vector<int> int_greater = int_Compare.getGreaterThan(int_val);
    int int_matches = int_Compare.matches(int_val);

    // double values --- --- ---
    std::vector<double> dbl_vec = {0.1, 0.2, 0.3, 0.4, 0.5};
    double dbl_val= 0.35;
    Compare<double> dbl_Compare(dbl_vec);

    std::vector<double> dbl_less = dbl_Compare.getLessThan(dbl_val);
    std::vector<double> dbl_greater = dbl_Compare.getGreaterThan(dbl_val);
    int dbl_matches = dbl_Compare.matches(dbl_val);

    // char values --- --- ---
    std::vector<char> char_vec = {'a', 'b', 'c', 'd', 'e'};
    char char_val= 'd';
    Compare<char> char_Compare(char_vec);

    std::vector<char> char_less = char_Compare.getLessThan(char_val);
    std::vector<char> char_greater = char_Compare.getGreaterThan(char_val);
    int char_matches = char_Compare.matches(char_val);
    
    // custom class values --- --- ---
    std::vector<myClass> myClass_vec = {myClass(0), myClass(1), myClass(2), myClass(3)};
    myClass myClass_val = myClass(2);
    Compare<myClass> myClass_Compare(myClass_vec);

    std::vector<myClass> myClass_less = myClass_Compare.getLessThan(myClass_val);
    std::vector<myClass> myClass_greater = myClass_Compare.getGreaterThan(myClass_val);
    int myClass_matches = myClass_Compare.matches(myClass_val);

   
    // -- --- --- --- --- --- ---
    // function calls --- --- ---
    // -- --- --- --- --- --- ---

    // less than calls --- --- ---
    std::cout << "\n\ngetLessThan() calls...";

    std::cout << "\nint -- less than: "<< int_val << std::endl;
    for ( auto i : int_less){
        std::cout << i << " ";
    } 

    std::cout << "\ndouble -- less than: "<< dbl_val << std::endl;
    for ( auto i : dbl_less){
        std::cout << i << " ";
    } 

    std::cout << "\nchar -- less than: "<< char_val << std::endl;
    for ( auto i : char_less){
        std::cout << i << " ";
    } 
    
    std::cout << "\nmyClass -- less than: "<< myClass_val << std::endl;
    for ( auto i : myClass_less){
        std::cout << i << " ";
    } 

    // greater than calls --- --- ---
    std::cout << "\n\ngetGreaterThan() calls...";

    std::cout << "\nint -- greater than: "<< int_val << std::endl;
    for ( auto i : int_greater){
        std::cout << i << " ";
    } 

    std::cout << "\ndouble -- greater than: "<< dbl_val << std::endl;
    for ( auto i : dbl_greater){
        std::cout << i << " ";
    } 

    std::cout << "\nchar -- greater than: "<< char_val << std::endl;
    for ( auto i : char_greater){
        std::cout << i << " ";
    } 

    std::cout << "\nmyClass -- greater than: "<< myClass_val << std::endl;
    for ( auto i : myClass_greater){
        std::cout << i << " ";
    } 

    // matches calls --- --- ---
    std::cout << "\n\nmatches() calls...";

    std::cout << "\nint -- number matches for: "<< int_val << std::endl;
    std::cout << int_matches; 

    std::cout << "\ndouble -- number matches for: "<< dbl_val << std::endl;
    std::cout << dbl_matches; 

    std::cout << "\nchar -- number matches for: "<< char_val << std::endl;
    std::cout << char_matches; 

    std::cout << "\nmyClass -- number matches for: "<< myClass_val << std::endl;
    std::cout << myClass_matches;
    
    std::cout << std::endl;     

    return 0;
}