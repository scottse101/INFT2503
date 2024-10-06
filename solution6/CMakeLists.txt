cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ChessGame)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable warnings (optional but useful)
add_compile_options(-Wall -Wextra -pedantic)

# Add the executable
add_executable(ChessGame exercise1.cpp)
