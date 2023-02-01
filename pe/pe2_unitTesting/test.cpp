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

  // check center getter
  Point q = c.get_center();
  REQUIRE(q.x == 0);
  REQUIRE(q.y == 0);
  REQUIRE(c.get_radius() == 0);

  // origin point and -1 radius
  // should fail
  Circle d = {p,-1};
  REQUIRE(d.get_radius() >= 0);
  // !!! note: constructor allows negative radius !!! 
}

TEST_CASE ("Overlaps Checks","[overlaps]"){
  Point p0 = {-1,0};
  Point p1 = {0,0};
  Point p2 = {1,0};

  Circle c0 = {p0,1};
  Circle c1 = {p1,0};
  Circle c2 = {p2,1};
  Circle c4 = {p1,1};


  // self overlap
  REQUIRE(c0.Overlaps(c0) == true);
  // overlap circle with point
  REQUIRE(c0.Overlaps(c1) == true);
  // overlap circle with circle at circumference
  REQUIRE(c0.Overlaps(c2) == true);
  // overlap two adjacent circles
  REQUIRE(c1.Overlaps(c4) == true);
  // !!! note: fails when more than one overlap point

}

TEST_CASE ("Area Checks","[area]") {
  Point p = {0,0};
  Circle c0 = {p, 0};
  Circle c1 = {p, 1};

  // 0 radiues
  REQUIRE(c0.CalculateArea() == 0);

  // 1 radius
  REQUIRE(c1.CalculateArea() == M_PI);
  // !!! note: this returns an integer not, a double !!!
}

TEST_CASE ("Shrink and Expand checks", "[shrink, expand]") {
  // create point at (0,0)
  Point p = {0,0};
  // create circle from p0, radius 0
  Circle c = {p,0};

  // check radius
  REQUIRE( c.get_radius() == 0 );

  // expand, check radius
  c.Expand();
  REQUIRE( c.get_radius() == 1 );
  // shrink back to 0
  c.Shrink();

  // shrink; circles should not drop below 0 radius
  c.Shrink();
  REQUIRE( c.get_radius() == 0 );
  // !!! note: provided shrink() breaks here !!!
}