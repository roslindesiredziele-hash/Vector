#include <iostream>
#include "Vec.h"

using namespace std;

int tests_run = 0;
int tests_failed = 0;

void assert_true(bool condition, const char* message)
{
    tests_run++;
    if (!condition)
    {
        tests_failed++;
        cout << "[FAIL] " << message << "\n";
    }
}

void test_push_and_get()
{
    Vec v(1);
    v.push(10);
    v.push(20);
    v.push(30);

    assert_true(v.size() == 3, "push(): size should be 3");
    assert_true(v.get(0) == 10, "push(): first element should be 10");
    assert_true(v.get(2) == 30, "push(): last element should be 30");
}

void test_copy_constructor()
{
    Vec a(1);
    a.push(5);
    a.push(7);

    Vec b = a; // copy

    assert_true(b.size() == 2, "copy constructor: size should match");
    assert_true(b.get(0) == 5, "copy constructor: first element copied");
    assert_true(b.get(1) == 7, "copy constructor: second element copied");

    a.get(0) = 99;
    assert_true(b.get(0) == 5, "copy constructor: deep copy, not shallow");
}

void test_assignment_operator()
{
    Vec a(1);
    a.push(1);
    a.push(2);

    Vec b(1);
    b.push(9);

    b = a;

    assert_true(b.size() == 2, "operator=: size should match");
    assert_true(b.get(0) == 1, "operator=: first element copied");
    assert_true(b.get(1) == 2, "operator=: second element copied");

    a.get(0) = 77;
    assert_true(b.get(0) == 1, "operator=: deep copy, not shallow");
}

void test_reverse()
{
    Vec v(1);
    v.push(1);
    v.push(2);
    v.push(3);

    v.reverse();

    assert_true(v.get(0) == 3, "reverse(): first element should be 3");
    assert_true(v.get(2) == 1, "reverse(): last element should be 1");
}

void test_rotate()
{
    Vec v(1);
    v.push(1);
    v.push(2);
    v.push(3);
    v.push(4);

    v.rotate(1);

    assert_true(v.get(0) == 4, "rotate(): last element should move to front");
    assert_true(v.get(1) == 1, "rotate(): second element should be 1");
}

int main()
{
    test_push_and_get();
    test_copy_constructor();
    test_assignment_operator();
    test_reverse();
    test_rotate();

    cout << "\nTests run: " << tests_run << "\n";
    cout << "Tests failed: " << tests_failed << "\n";

    if (tests_failed == 0)
        cout << "All tests passed!\n";
}



