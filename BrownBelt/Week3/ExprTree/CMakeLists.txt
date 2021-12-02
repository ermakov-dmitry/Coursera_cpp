cmake_minimum_required(VERSION 3.20)
project(ExprTree)

set(CMAKE_CXX_STANDARD 17)

add_executable(ExprTree main.cpp Common.h test_runner.h Common.cpp)
