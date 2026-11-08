#ifndef VEC_H
#define VEC_H

#include <ostream>

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
    int capacity() const;

    int swapInt(int &a, int &b);


    int& operator[](int i);
    const int& operator[](int i) const;

    int& get(int i);
    const int& get(int i) const;

    void pop();
    bool empty() const;

    void resize(int new_cap);

    void push(int el);

    int& first();
    const int& first() const;

    int& last();
    const int& last() const;

    void clear();

    bool linearSearch(int x) const;
    int binarySearch(int x) const;

    int sum() const;
    double avg() const;

    void reverse();
    void reverse(int l, int r);
    void rotate(int x);

    int* begin ();
    const int* begin() const;

    int* end();
    const int* end() const;

    Vec(const Vec& other);
    Vec& operator=(Vec cpy);
    Vec(Vec&& other) noexcept;
};

std::ostream& operator<<(std::ostream& ostr, const Vec& v);

#endif

