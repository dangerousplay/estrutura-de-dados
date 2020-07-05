cmake_minimum_required(VERSION 3.15)
project(exercise)

set(CMAKE_CXX_STANDARD 20)

find_package(Catch2 REQUIRED)

add_executable(exercise_f main.cpp draw.h)

add_executable(exercise_test tests/test_main.cpp draw.h)
target_link_libraries(exercise_test Catch2::Catch2)

include(CTest)
include(ParseAndAddCatchTests)