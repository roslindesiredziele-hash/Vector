#include "Vec.h"

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


