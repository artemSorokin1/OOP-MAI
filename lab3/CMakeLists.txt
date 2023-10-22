cmake_minimum_required(VERSION 3.20)

project(lab2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab3 src/main.cpp src/Point.cpp src/Triangle.cpp src/Figure.cpp src/Box.cpp src/Rectangle.cpp src/Validator.cpp src/Fabric.cpp ../../lib/Vector.cpp)
add_executable(tests3 test/Figure_test.cpp src/Point.cpp src/Triangle.cpp src/Figure.cpp src/Box.cpp src/Rectangle.cpp src/Validator.cpp src/Fabric.cpp ../../lib/Vector.cpp)


enable_testing()

find_package(GTest CONFIG REQUIRED)
target_link_libraries(tests3 PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(NAME LAB1 COMMAND tests3)
