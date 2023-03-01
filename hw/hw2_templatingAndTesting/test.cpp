/**
 * @file test.cpp
 * @author Leif Anders
 * @brief 
 * @version 0.1
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Linear.h"
#include "Tree.h"
#include "HashMap.h"


// Linear --------------------------------------
TEST_CASE("Linear Template Tests"){
    // integer
        std::vector<int> int_vec = {};
        Linear<int> int_lin(int_vec);
        
        int_lin.insertValue(0);

        SECTION("insertValue"){
            REQUIRE(int_lin.getSizeOfList() == 1);
        }

        SECTION("getElementAt") {
            REQUIRE(int_lin.getElementAt(0) == 0);
        }

        SECTION("search") {
            REQUIRE(int_lin.search(1) == 0);
            REQUIRE(int_lin.search(0) == 1);
        }
        
        SECTION("deleteElement") {
            int_lin.deleteElement(0);
            REQUIRE(int_lin.search(0) == 0);
        }

    // double
        std::vector<double> dbl_vec = {};
        Linear<double> dbl_lin(dbl_vec);
        
        dbl_lin.insertValue(0.1);

        SECTION("insertValue"){
            REQUIRE(dbl_lin.getSizeOfList() == 1);
        }

        SECTION("getElementAt") {
            REQUIRE(dbl_lin.getElementAt(0) == 0.1);
        }

        SECTION("search") {
            REQUIRE(dbl_lin.search(1) == 0);
            REQUIRE(dbl_lin.search(0.1) == 1);
        }
        
        SECTION("deleteElement") {
            dbl_lin.deleteElement(0.1);
            REQUIRE(dbl_lin.search(0) == 0);
        }

    // user-class
}

// Tree ----------------------------------------
TEST_CASE("Tree Template Tests"){
    // char
        char char_root = 'n';
        Tree<char> char_tree(char_root);
        
        SECTION("insertElement") {
            char_tree.insertElement('a');

            REQUIRE(char_tree.search('n')==1);
            REQUIRE(char_tree.search('a')==1);
        }

        SECTION("search") {
            REQUIRE(char_tree.search('n')==1); 
            REQUIRE(char_tree.search('b')==0);
        }
        
        SECTION("deleteElement") {
            char_tree.insertElement('a');
            REQUIRE(char_tree.search('a')==1);

            char_tree.deleteElement('a');
            REQUIRE(char_tree.search('a')==0);
            REQUIRE(char_tree.search('n')==1);

            // fix delete root node error

        }
    
    // user class
}

// HashMap -------------------------------------
TEST_CASE("HashMap Template Cases"){

}