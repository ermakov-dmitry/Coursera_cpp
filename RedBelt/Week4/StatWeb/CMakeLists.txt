cmake_minimum_required(VERSION 3.20)
project(StatWeb)

set(CMAKE_CXX_STANDARD 17)

add_executable(StatWeb main.cpp test_runner.h http_request.h stats.h stats.cpp)
