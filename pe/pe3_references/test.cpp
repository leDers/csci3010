/**
 * @file test.cpp
 * @author Leif Anders
 * @brief   this is the test.cpp for the pe3_references.cpp assignment
 * @version 0.1
 * @date 2023-02-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "pe3_references.cpp"

TEST_CASE ("#9 -- foo1()"){
    int x = 0;
    int *p = &x;
    
    foo1(p);
    REQUIRE (x == 1);
}

TEST_CASE ("#11 -- foo2()"){
    int x = 0;
    int &r = x;

    foo2(r);
    REQUIRE (x == 1);

}

TEST_CASE ("#14 -- foo3()"){
    int x = 0;
    int &r = x;
    int *p = &x;

    foo3(r, p);
    REQUIRE (x == 1);

}

TEST_CASE ("#16 -- myClass"){
    myClass a = myClass(0);
    myClass b = myClass(0);

    REQUIRE(a+b == 0);
    REQUIRE((a==b) == true);
}