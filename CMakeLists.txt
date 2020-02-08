cmake_minimum_required(VERSION 3.5)

project(simple_prng CXX)
set(CMAKE_VERBOSE_MAKEFILE ON)

message(STATUS ${PROJECT_SOURCE_DIR})

include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(prng_example src/prng_example.cpp)
add_executable(prng src/prng.cpp)
