cmake_minimum_required(VERSION 3.20)

project(lab6)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(COMPILE_FILES
    src/UI.cpp
    src/NPC.cpp
    src/NPCFabric.cpp
    src/ObserverConsolOutput.cpp
    src/ObserverFileOutput.cpp
    src/Visitor.cpp
    src/DeathAgregator.cpp
    src/Menu.cpp
)

add_executable(lab6 main.cpp ${COMPILE_FILES})
add_executable(tests6 tests)

enable_testing()

find_package(GTest CONFIG REQUIRED)
target_link_libraries(tests6 PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(NAME LAB6 COMMAND tests6)
