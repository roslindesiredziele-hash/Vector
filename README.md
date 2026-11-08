# Vec

A custom dynamic array implementation written in modern C++ to explore memory management, copy and move semantics, dynamic resizing, iterator support, algorithm implementation, and automated testing.

The project was developed to better understand how containers such as `std::vector` work internally while applying modern software engineering practices including automated testing, build automation, and continuous integration.

## Highlights

- Dynamic memory management
- Deep copy semantics
- Move semantics
- Iterator support
- Automated testing with Catch2
- CMake build system
- CTest integration
- GitHub Actions CI

## Features

### Memory Management

- Dynamic memory allocation
- Automatic capacity growth through capacity doubling
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

Supports range-based loops:

```cpp
for (int value : vec)
{
    std::cout << value << '\n';
}
```

## Design Goals

This project focuses on:

- Understanding dynamic memory management
- Exploring copy and move semantics
- Implementing common container operations
- Practicing exception handling
- Building automated test suites with Catch2
- Using CMake and CTest for build automation
- Applying continuous integration through GitHub Actions

## Example Usage

```cpp
#include "Vec.h"
#include <iostream>

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

## Design Notes

### Capacity Growth

When the vector reaches its capacity during insertion, the storage capacity is automatically doubled.

### Resize Behavior

In this implementation, `resize()` modifies both capacity and logical size when shrinking. If the new capacity is smaller than the current number of stored elements, excess elements are discarded.

### Binary Search

`binarySearch()` assumes elements are stored in ascending sorted order.

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

## Testing

The project uses **Catch2** for automated testing.

### Coverage

✅ Construction and initialization  
✅ Negative capacity validation  
✅ Deep copy semantics  
✅ Move semantics  
✅ Assignment operator behavior  
✅ Bounds checking  
✅ Resize behavior  
✅ Search algorithms  
✅ Reverse operations  
✅ Rotation behavior  
✅ Iterator support  
✅ Aggregate operations  
✅ Empty vector behavior  
✅ First/Last element access  
✅ Clear operation  
✅ Pop operation  

### Results

```text
34 test cases
84 assertions
100% passing
```

CTest output:

```text
100% tests passed out of 1

All tests passed (84 assertions in 34 test cases)
```

## Continuous Integration

GitHub Actions automatically:

1. Configures the project using CMake
2. Builds the project
3. Executes the Catch2 test suite through CTest

Current CI Status:

```text
Build: Passing
Tests: Passing
34 test cases
84 assertions
100% passing
```

## Requirements

- C++17 compatible compiler
- CMake 3.10+
- Catch2 Single Header (`external/catch.hpp`)

Supported compilers:

- GNU g++
- Clang
- Microsoft Visual Studio (MSVC)

## Build

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

Linux/macOS:

```bash
ctest --verbose
```

Visual Studio:

```bash
ctest -C Debug --verbose
```

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

## Technologies

- C++17
- Catch2
- CMake
- CTest
- GitHub Actions
- Git
- GitHub

## Future Improvements

Potential extensions include:

- `shrink_to_fit()`
- Additional exception-safety guarantees
- Generic template implementation (`Vec<T>`)

## Author

**Desire Roslin Dziele**  
Computer Science Student  
University of Łódź