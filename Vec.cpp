#include "Vec.h"
#include <algorithm>

Vec::Vec(int n)
    : cap(n), len(n), mem(new int[cap])
{
}

Vec::~Vec()
{
    delete[] mem;
}

int Vec::size() const
{
    return len;
}

int Vec::capacity() const
{
    return cap;
}

int& Vec::get(int i)
{
    return mem[i];
}

const int& Vec::get(int i) const
{
    return mem[i];
}

void Vec::pop()
{
    if (!empty())
        len--;
}

bool Vec::empty() const
{
    return len == 0;
}

void Vec::resize(int new_cap)
{
    // Ensure capacity is at least 1
    cap = std::max(1, new_cap);

    // Allocate new memory
    int* new_mem = new int[cap];

    // Adjust length if needed
    len = std::min(len, cap);

    // Copy existing elements
    for (int i = 0; i < len; i++)
        new_mem[i] = mem[i];

    // Replace old memory
    delete[] mem;
    mem = new_mem;
}

void Vec::push(int el)
{
    if (len == cap)
        resize(2 * cap);

    mem[len] = el;
    len++;
}

int& Vec::first()
{
    return mem[0];
}

const int& Vec::first() const
{
    return mem[0];
}

int& Vec::last()
{
    return mem[len - 1];
}

const int& Vec::last() const
{
    return mem[len - 1];
}



