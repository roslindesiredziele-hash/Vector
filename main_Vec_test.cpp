#include <iostream>
#include "Vec.h"

int main()
{
    Vec v(10);
    std::cout << "Size: " << v.size() << "\n";
    std::cout << "Capacity: " << v.capacity() << "\n";
    return 0;
}
