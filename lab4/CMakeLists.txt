cmake_minimum_required(VERSION 3.20)

project(lab4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(lab4 src/main.cpp)
add_executable(tests4 test/Figure_test.cpp)

enable_testing()

find_package(GTest CONFIG REQUIRED)
target_link_libraries(tests4 PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(NAME LAB4 COMMAND tests4)
