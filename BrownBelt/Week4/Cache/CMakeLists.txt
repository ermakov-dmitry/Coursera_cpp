cmake_minimum_required(VERSION 3.20)
project(Cache)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(Cache main.cpp test_runner.h Common.h Solution.cpp)
