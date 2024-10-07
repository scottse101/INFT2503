cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ChessGame)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable warnings (optional but useful)
add_compile_options(-Wall -Wextra -pedantic)

# Add executable for exercise1.cpp (ChessGame)
add_executable(ChessGame exercise1.cpp)

# Add executable for exercise2.cpp (Exercise2Server)
add_executable(Exercise2Server exercise2.cpp)

# Find Boost package
find_package(Boost 1.86 REQUIRED COMPONENTS system)

# Link Boost to Exercise2Server
target_include_directories(Exercise2Server PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(Exercise2Server PRIVATE ${Boost_LIBRARIES} Boost::system)
