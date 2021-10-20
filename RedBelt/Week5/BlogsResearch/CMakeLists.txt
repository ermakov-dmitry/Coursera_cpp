cmake_minimum_required(VERSION 3.20)
project(BlogsResearch)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(BlogsResearch main.cpp test_runner.h)
