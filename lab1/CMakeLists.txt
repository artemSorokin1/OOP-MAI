cmake_minimum_required(VERSION 3.20)

project(lab1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab1 src/main.cpp src/vowel_deleter.cpp)
add_executable(tests1 test/test_vowel_deleter.cpp src/vowel_deleter.cpp)


enable_testing()

find_package(GTest CONFIG REQUIRED)
target_link_libraries(tests1 PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(NAME LAB1 COMMAND tests1)
