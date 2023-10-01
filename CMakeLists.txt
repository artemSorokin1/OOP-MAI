cmake_minimum_required(VERSION 3.10)
project(labs)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lab1)

add_subdirectory(lab2)

# add_executable(lab1 lab1/src/main.cpp lab1/src/vowel_deleter.cpp)
# add_executable(tests1 lab1/test/test_vowel_deleter.cpp lab1/src/vowel_deleter.cpp)

#add_executable(lab2 lab2/src/main.cpp lab2/src/money.cpp)
#add_executable(tests2 lab2/test/test.cpp lab2/src/money.cpp)
#
#enable_testing()
#
#find_package(GTest CONFIG REQUIRED)
## target_link_libraries(tests1 PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
#target_link_libraries(tests2 PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
#
## add_test(NAME LAB1 COMMAND tests1)
#add_test(NAME LAB2 COMMAND tests2)

