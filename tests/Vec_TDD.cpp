#define CATCH_CONFIG_MAIN

#include "../external/catch.hpp"

#include "Vec.h"

TEST_CASE("push increases size and stores values")
{
    Vec v(1);

    v.push(10);
    v.push(20);
    v.push(30);

    REQUIRE(v.size() == 3);

    CHECK(v.get(0) == 10);
    CHECK(v.get(1) == 20);
    CHECK(v.get(2) == 30);
}

TEST_CASE("copy constructor performs deep copy")
{
    Vec a(1);

    a.push(5);
    a.push(7);

    Vec b = a;

    REQUIRE(b.size() == 2);

    CHECK(b.get(0) == 5);
    CHECK(b.get(1) == 7);

    a.get(0) = 99;

    CHECK(b.get(0) == 5);
}



