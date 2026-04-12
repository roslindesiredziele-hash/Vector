#include "Vec.h"

Vec::Vec(int n)
    : cap(n), len(0), mem(new int[n])
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
