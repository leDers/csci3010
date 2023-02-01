// CSCI 3010 SP 23
// Leif Anders
// PE2 - circles

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Circle.h"

#define _USE_MATH_DEFINES
#include <cmath>


TEST_CASE ( "Factorials are computed", "[factorial]") {
  REQUIRE( Factorial(2) == 2 );
  REQUIRE( Factorial(3) == 6 );
}

// write test cases for circle!!
TEST_CASE ("Constructor Checks","[constructor]") {
  // origin point and 0 radius circle
  Point p = {0,0};
  Circle c = {p,0};

  SECTION ("check center getter"){
    Point q = c.get_center();
    REQUIRE(q.x == 0);
    REQUIRE(q.y == 0);
    REQUIRE(c.get_radius() == 0);
  }
  
  SECTION ("origin point and -1 radius") {
    Circle d = {p,-1};
    REQUIRE(d.get_radius() >= 0);
    // !!! note: constructor allows negative radius !!! 
  }
  
}

TEST_CASE ("Overlaps Checks","[overlaps]"){
  Point pA = {-1,0};
  Point pB = {0,0};
  Point pC = {1,0};

  SECTION( "self overlap" ){
    Circle c_0 = {pA,1};
    Circle c_1 = {pA,1};
    REQUIRE(c_0.Overlaps(c_1) == true); // full overlap
    // !!! note: fails when circles are similar !!!
  }
  
  SECTION("overlap circle with point"){
    Circle c_0 = {pA,1};
    Circle c_1 = {pB,0};
    REQUIRE(c_0.Overlaps(c_1) == true); // one point
  }
  
  SECTION ("overlap circle with circle at circumference, outside") {
    Circle c_0 = {pA,1};
    Circle c_1 = {pC,1};
    REQUIRE(c_0.Overlaps(c_1) == true); // one point
  }
  
  SECTION ("overlap circle with circle at circumference, inside") {
    Circle c_0 = {pC,1};
    Circle c_1 = {pB,2};    
    REQUIRE(c_0.Overlaps(c_1) == true); // one point
    // !!! note: fails smaller circle inside larger touches at point !!!
  }

  SECTION ("overlap two adjacent circles") {
    Circle c_0 = {pA,1};
    Circle c_1 = {pB,1};
    REQUIRE(c_0.Overlaps(c_1) == true); // two points
    // !!! note: fails when more than one overlap point !!!
  }

  SECTION("Circle inside a circle, non touching") {
    Circle c_0 = {pB,1};
    Circle c_1 = {pB,2};
    REQUIRE(c_0.Overlaps(c_1) == false);
  }
}

TEST_CASE ("Area Checks","[area]") {
  Point p = {0,0};
  Circle c0 = {p, 0};
  Circle c1 = {p, 1};

  SECTION("0 radius") {
    REQUIRE(c0.CalculateArea() == 0);
  }

  SECTION("1 radius"){
    REQUIRE(c1.CalculateArea() == M_PI);
    // !!! note: this returns an integer not, a double !!!
  }
  
}

TEST_CASE ("Expand and Shrink checks", "[Expand, Shrink]") {
  // create point at (0,0)
  Point p = {0,0};
  // create circle from p0, radius 0
  Circle c = {p,0};

  SECTION("check radius"){
    REQUIRE( c.get_radius() == 0 );
  }

  SECTION("expand from 0, check radius"){
    c.Expand();
    REQUIRE( c.get_radius() == 1 );    
  }

  SECTION("shrink from 0; circles should not drop below 0 radius"){
    c.Shrink();
    REQUIRE( c.get_radius() == 0 );
    // !!! note: provided shrink() breaks here !!!
  }
}