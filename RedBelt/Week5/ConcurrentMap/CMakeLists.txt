cmake_minimum_required(VERSION 3.20)
project(ConcurrentMap)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(ConcurrentMap main.cpp test_runner.h profile.h)
