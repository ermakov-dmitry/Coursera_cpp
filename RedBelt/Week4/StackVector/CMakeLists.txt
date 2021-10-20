cmake_minimum_required(VERSION 3.20)
project(StackVector)

set(CMAKE_CXX_STANDARD 17)

add_executable(StackVector main.cpp test_runner.h stack_vector.h profile.h)
