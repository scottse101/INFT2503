cmake_minimum_required(VERSION 3.1)

project(Set)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(Set main.cpp set.cpp)