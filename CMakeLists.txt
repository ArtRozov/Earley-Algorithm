cmake_minimum_required(VERSION 3.15)
project(FormalPrac2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER_ID "GNU")
SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage --coverage")
SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage --coverage")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}  ${GTEST_INCLUDE_DIRS} )
enable_testing()
add_executable(Test main_test.cpp)

add_test(Test ${PROJECT_SOURCE_DIR}/bin/testing)

add_executable(FormalPrac2 main.cpp)

add_library(Earley SHARED
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Earley.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Earley.h
        )

add_library(Grammar SHARED
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Grammar.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Grammar.h
        )

target_link_libraries(FormalPrac2 Earley Grammar)

target_link_libraries(Test Earley Grammar)
target_link_libraries(Test Threads::Threads ${GTEST_LIBRARIES} ${GMOCK_BOTH_LIBRARIES})
