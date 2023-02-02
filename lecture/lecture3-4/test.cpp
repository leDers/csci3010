#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "functions_to_implement.cpp"
#include <vector>

TEST_CASE ("Signs are computed","[signs]") {
    REQUIRE (Sign(-2) == -1);
    REQUIRE (Sign(2) == 1);
}

TEST_CASE ("Sums are computed","[sums]") {
    std::vector<int> v1 {0,1,2};
    REQUIRE (Sum(v1) == 3);
}

TEST_CASE ("Factorials are computed","[factorial]") {
    REQUIRE (Factorial(1) == 1 );
    REQUIRE (Factorial(3) == 6 );
}