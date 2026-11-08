cmake_minimum_required(VERSION 3.10)

project(CustomDynamicVector)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_executable(
    Vec_TDD
    src/Vec.cpp
    tests/Vec_TDD.cpp
)

target_include_directories(Vec_TDD PRIVATE
    src
    external
)

add_test(
    NAME VecTests
    COMMAND Vec_TDD
)