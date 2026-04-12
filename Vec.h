#ifndef VEC_H
#define VEC_H

class Vec
{
private:
    int cap;
    int len;
    int* mem;

public:
    Vec(int n);
    ~Vec();
    int size() const;

};

#endif
