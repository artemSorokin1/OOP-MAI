cmake_minimum_required(VERSION 3.10)
project(lab1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab1 lab1/main.cpp lab1/time_refactor.cpp)

add_executable(tests lab1/test/test.cpp lab1/time_refactor.cpp)

enable_testing()

find_package(GTest CONFIG REQUIRED)
target_link_libraries(tests PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(NAME BASIC COMMAND tests)
