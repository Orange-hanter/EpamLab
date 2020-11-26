#include <catch2/catch_test_macros.hpp>

#include "funk.h"

std::list<int> const l1 = {7, 8, 9, 4, 5, 6, 1, 2, 3, 4};
std::list<int> const l2 = {-3, -2, -1, 0, 0, 1, 2, 3, 4, 5};
        std::list<int> const l3 = {5};
        std::list<int> const l4;
        std::list<int> const l5 = {6, 5};
        std::list<int> const l6 = {5, 6};
        

TEST_CASE( "2: Factorial of 0 is 1 (fail)", "[multi-file:2]" ) {
    REQUIRE( max_increasing_len(l1.begin(), l1.end()) == 4 );
    REQUIRE( max_increasing_len(l2.begin(), l2.end()) == 6 );
    REQUIRE( max_increasing_len(l4.begin(), l4.end()) == 0 );
    REQUIRE( max_increasing_len(l3.begin(), l3.end()) == 1 );
    REQUIRE( max_increasing_len(l5.begin(), l5.end()) == 1 );
    REQUIRE( max_increasing_len(l6.begin(), l6.end()) == 2 );
}