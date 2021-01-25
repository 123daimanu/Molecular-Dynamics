project(TestVector3)
cmake_minimum_required(VERSION 2.6)

add_definitions(-std=c++14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")


set(
    sources
    main_test.cpp
    Vector3Test.cpp
    ../maths/Vector3.cpp
)



add_executable(test ${sources})
target_link_libraries(test pthread)
target_link_libraries(test gmock)
target_link_libraries(test gtest)



