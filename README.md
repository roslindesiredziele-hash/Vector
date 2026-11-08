# Vec

A custom dynamic array implementation in modern C++ designed to explore memory management, value semantics, dynamic resizing, search algorithms, and automated testing.

The project was developed as an educational exercise to better understand how containers such as `std::vector` work internally.

---

## Features

### Memory Management

- Dynamic memory allocation
- Automatic capacity growth
- Deep copy semantics
- Move semantics
- Resource ownership management

### Container Operations

- `push()`
- `pop()`
- `clear()`
- `resize()`
- `size()`
- `capacity()`
- `empty()`

### Element Access

- `operator[]`
- `get()`
- `first()`
- `last()`

### Algorithms

- Linear Search
- Binary Search
- Reverse
- Range Reverse
- Rotation
- Sum
- Average

### Iterator Support

- `begin()`
- `end()`

Supports range-based `for` loops:

```cpp
for (int value : vec)
{
    std::cout << value << '\n';
}
```

---

## Design Goals

The project focuses on:

- Understanding dynamic memory management
- Exploring copy and move semantics
- Implementing common container operations
- Practicing exception handling
- Building automated tests using Catch2
- Using CMake and CTest for build automation

---

## Example Usage

```cpp
#include "Vec.h"

int main()
{
    Vec v(2);

    v.push(10);
    v.push(20);
    v.push(30);

    std::cout << v << '\n';
}
```

Output:

```text
[10; 20; 30]
```

---

## Complexity

| Operation | Complexity |
|------------|------------|
| push | O(1) amortized |
| pop | O(1) |
| get | O(1) |
| operator[] | O(1) |
| linearSearch | O(n) |
| binarySearch | O(log n) |
| reverse | O(n) |
| rotate | O(n) |
| sum | O(n) |
| avg | O(n) |

---

## Build

### Requirements

- C++17 compatible compiler
- CMake 3.10+
- Catch2 (single-header version)

---

### Configure

```bash
mkdir build
cd build

cmake ..
```

### Build

```bash
cmake --build .
```

### Run Tests

```bash
ctest --verbose
```

For Visual Studio generators:

```bash
ctest -C Debug --verbose
```

---

## Testing

The project uses **Catch2** for automated testing.

Current coverage includes:

- Construction
- Deep copy semantics
- Move semantics
- Assignment operator
- Bounds checking
- Resize behavior
- Search algorithms
- Reverse operations
- Rotation
- Aggregate operations

Current results:

```text
21 test cases
49 assertions
100% passing
```

---

## Continuous Integration

GitHub Actions automatically:

1. Configures the project with CMake
2. Builds the project
3. Runs the full test suite

Every push and pull request is validated automatically.

---

## Project Structure

```text
Vector/
│
├── .github/
│   └── workflows/
│       └── ci.yml
│
├── external/
│   └── catch.hpp
│
├── src/
│   ├── Vec.h
│   └── Vec.cpp
│
├── tests/
│   └── Vec_TDD.cpp
│
├── CMakeLists.txt
│
└── README.md
```

---

## Future Improvements

Potential extensions:

- Move assignment operator
- reserve()
- shrink_to_fit()
- Additional exception-safety guarantees

---

## Author

Desire Roslin Dziele

Computer Science Student  
University of Łódź