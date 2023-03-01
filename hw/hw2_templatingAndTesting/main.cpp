/**
 * @file main.cpp
 * @author Leif Anders
 * @brief   main file for testing outside of unit tests
 * @version 0.1
 * @date 2023-02-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <string>

#include "Linear.h"
#include "Tree.h"
#include "HashMap.h"

int main(){

    std::cout << "Hello, World!" << std::endl;

    // linear --- --- --- --- --- ---
    std::cout << "\n-------- LINEAR --------" << std::endl;
    std::vector<int> int_v = {0,1,2,3,4};
    Linear<int> lin_int(int_v);
    std::cout << "After init: " << lin_int << std::endl;
    lin_int.insertValue(5);
    std::cout << "After insert '5': " << lin_int << std::endl;
    std::cout << "Getting element '5': " << lin_int.getElementAt(5) << std::endl;
    std::cout << "Search element '5': " << lin_int.search(5) << std::endl;
    lin_int.deleteElement(0);
    std::cout << "After delete: " << lin_int << std::endl; 

    // tree --- --- --- --- --- --- -
    std::cout << "\n-------- TREE --------" << std::endl;
    char r = 'b';
    Tree<char> T(r);
    T.insertElement('a');
    T.insertElement('c');
    T.insertElement('z');
    T.insertElement('p');
    T.insertElement('q');
    T.insertElement('h');
    T.deleteElement('a');

    std::cout << "After Init: " << T << std::endl;

    // hashmap --- --- --- --- --- --
    std::cout << "\n-------- HASH --------" << std::endl;
    std::vector<double> dbl_vect = {1.1, 2.2, 3.3, 4.4, 5.5};
    int dbl_size = 6;
    HashMap<double> dbl_hash(dbl_vect, dbl_size);

    dbl_hash.insertElement(6.6);    

    std::cout << dbl_hash << std::endl;

    std::cout << dbl_hash.search(3.3) << std::endl;
    
    dbl_hash.deleteElement(3.3);
    std::cout << dbl_hash << std::endl;


    return 0;
}