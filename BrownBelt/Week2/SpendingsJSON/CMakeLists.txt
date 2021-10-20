cmake_minimum_required(VERSION 3.20)
project(SpendingsJSON)

set(CMAKE_CXX_STANDARD 17)

add_executable(SpendingsJSON main.cpp json.cpp json.h test_runner.h)
