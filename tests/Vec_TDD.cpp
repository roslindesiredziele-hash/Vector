#define CATCH_CONFIG_MAIN

#include "../external/catch.hpp"

#include "../src/Vec.h"

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

TEST_CASE("Constructor initializes empty vector")
{
    Vec v(10);

    CHECK(v.size() == 0);
    CHECK(v.capacity() == 10);
    CHECK(v.empty());
}

TEST_CASE("Negative capacity throws")
{
    REQUIRE_THROWS_AS(
        Vec(-1),
        std::invalid_argument
    );
}

TEST_CASE("push updates size")
{
    Vec v(2);

    v.push(1);
    v.push(2);

    CHECK(v.size() == 2);
    CHECK(v.capacity() >= 2);
}

TEST_CASE("Copy constructor performs deep copy")
{
    Vec a(1);

    a.push(5);

    Vec b = a;

    a[0] = 99;

    CHECK(b[0] == 5);
}

TEST_CASE("Move constructor transfers ownership")
{
    Vec a(2);

    a.push(1);
    a.push(2);

    Vec b(std::move(a));

    CHECK(b.size() == 2);
    CHECK(b[0] == 1);
    CHECK(b[1] == 2);

    CHECK(a.size() == 0);
}

TEST_CASE("Assignment operator performs deep copy")
{
    Vec a(1);
    a.push(10);

    Vec b(1);

    b = a;

    a[0] = 20;

    CHECK(b[0] == 10);
}

TEST_CASE("get throws on invalid index")
{
    Vec v(1);

    REQUIRE_THROWS_AS(
        v.get(0),
        std::out_of_range
    );
}

TEST_CASE("operator[] throws on invalid index")
{
    Vec v(1);

    REQUIRE_THROWS_AS(
        v[0],
        std::out_of_range
    );
}

TEST_CASE("resize preserves data")
{
    Vec v(1);

    v.push(1);
    v.push(2);
    v.push(3);

    v.resize(10);

    CHECK(v.size() == 3);

    CHECK(v[0] == 1);
    CHECK(v[1] == 2);
    CHECK(v[2] == 3);
}
