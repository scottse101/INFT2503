cmake_minimum_required(VERSION 3.5)

project(Solution3)

set(CMAKE_CXX_STANDARD 11)

add_executable(exercise2_program 
    exercise1.cpp  
    exercise2.cpp  
    Commodity.cpp  
)

add_executable(exercise4_program 
    exercise4.cpp  
)

add_executable(test_client_program 
    Commodity.cpp  
    testKlient.cpp
)

target_include_directories(exercise2_program PUBLIC ${PROJECT_SOURCE_DIR})
target_include_directories(exercise4_program PUBLIC ${PROJECT_SOURCE_DIR})
target_include_directories(test_client_program PUBLIC ${PROJECT_SOURCE_DIR})
