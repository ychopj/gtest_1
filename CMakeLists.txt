cmake_minimum_required(VERSION 3.23)
project(gtest_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

file(GLOB ALL_SOURCE "*.cpp" "*.c"
        src/*.cpp
        testSrc/*.cpp)

file(GLOB ALL_HEAD "*.hpp" "*.h"
        include/*.h
        testSuits/*.h)

add_executable(gtest_1 ${ALL_SOURCE} ${ALL_HEAD} )

target_link_libraries(gtest_1 gtest gtest_main pthread)