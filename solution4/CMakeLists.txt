cmake_minimum_required(VERSION 3.5)

project(NameCombiner LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(exercise1 exercise1.cpp)
add_executable(exercise2 exercise2.cpp)

target_link_libraries(exercise2 ${GTKMM_LIBRARIES})

