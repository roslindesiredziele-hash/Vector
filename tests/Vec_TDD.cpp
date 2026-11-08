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

TEST_CASE("sum computes total")
{
    Vec v(3);

    v.push(1);
    v.push(2);
    v.push(3);

    CHECK(v.sum() == 6);
}

TEST_CASE("avg computes mean")
{
    Vec v(3);

    v.push(2);
    v.push(4);
    v.push(6);

    CHECK(v.avg() == Approx(4.0));
}

TEST_CASE("reverse flips vector")
{
    Vec v(3);

    v.push(1);
    v.push(2);
    v.push(3);

    v.reverse();

    CHECK(v[0] == 3);
    CHECK(v[1] == 2);
    CHECK(v[2] == 1);
}

TEST_CASE("reverse range reverses subsection")
{
    Vec v(5);

    for(int i=1;i<=5;i++)
        v.push(i);

    v.reverse(1,3);

    CHECK(v[0] == 1);
    CHECK(v[1] == 4);
    CHECK(v[2] == 3);
    CHECK(v[3] == 2);
    CHECK(v[4] == 5);
}

TEST_CASE("rotate right")
{
    Vec v(4);

    v.push(1);
    v.push(2);
    v.push(3);
    v.push(4);

    v.rotate(1);

    CHECK(v[0] == 4);
    CHECK(v[1] == 1);
    CHECK(v[2] == 2);
    CHECK(v[3] == 3);
}

TEST_CASE("linear search finds existing value")
{
    Vec v(3);

    v.push(1);
    v.push(2);
    v.push(3);

    CHECK(v.linearSearch(2));
    CHECK_FALSE(v.linearSearch(99));
}

TEST_CASE("binary search returns index")
{
    Vec v(5);

    v.push(1);
    v.push(3);
    v.push(5);
    v.push(7);
    v.push(9);

    CHECK(v.binarySearch(5) == 2);
    CHECK(v.binarySearch(99) == -1);
}

TEST_CASE("empty vector behavior")
{
    Vec v(1);

    CHECK(v.empty());

    REQUIRE_THROWS(v.first());
    REQUIRE_THROWS(v.last());
}

TEST_CASE("first and last return correct values")
{
    Vec v(3);

    v.push(1);
    v.push(2);
    v.push(3);

    CHECK(v.first() == 1);
    CHECK(v.last() == 3);
}

TEST_CASE("clear empties vector")
{
    Vec v(3);

    v.push(1);
    v.push(2);

    v.clear();

    CHECK(v.empty());
    CHECK(v.size() == 0);
}

TEST_CASE("pop removes last element")
{
    Vec v(3);

    v.push(1);
    v.push(2);

    v.pop();

    CHECK(v.size() == 1);
    CHECK(v.last() == 1);
}

TEST_CASE("resize shrinks vector")
{
    Vec v(5);

    for(int i = 1; i <= 5; i++)
        v.push(i);

    v.resize(3);

    CHECK(v.size() == 3);
    CHECK(v.capacity() == 3);

    CHECK(v[0] == 1);
    CHECK(v[1] == 2);
    CHECK(v[2] == 3);
}

TEST_CASE("resize to zero keeps minimum capacity")
{
    Vec v(3);

    v.push(1);
    v.push(2);

    v.resize(0);

    CHECK(v.capacity() == 1);
    CHECK(v.size() == 1);

    CHECK(v[0] == 1);
}

TEST_CASE("pop on empty vector is safe")
{
    Vec v(1);

    CHECK(v.empty());

    v.pop();

    CHECK(v.empty());
    CHECK(v.size() == 0);
}

TEST_CASE("moved-from vector remains valid")
{
    Vec a(2);

    a.push(10);
    a.push(20);

    Vec b(std::move(a));

    CHECK(a.size() == 0);
    CHECK(a.capacity() == 0);

    CHECK(b.size() == 2);
    CHECK(b[0] == 10);
    CHECK(b[1] == 20);
}

