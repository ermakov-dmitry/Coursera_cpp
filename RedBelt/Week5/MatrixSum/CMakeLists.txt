cmake_minimum_required(VERSION 3.20)
project(MatrixSum)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(MatrixSum main.cpp test_runner.h)
