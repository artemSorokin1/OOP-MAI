cmake_minimum_required(VERSION 3.20)

project(lab2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab2 src/main.cpp src/money.cpp src/MoneyBuilder.cpp)
add_executable(tests2 test/test.cpp src/money.cpp src/MoneyBuilder.cpp)


enable_testing()

find_package(GTest CONFIG REQUIRED)
target_link_libraries(tests2 PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(NAME LAB1 COMMAND tests2)