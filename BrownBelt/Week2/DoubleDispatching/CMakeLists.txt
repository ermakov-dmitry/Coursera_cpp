cmake_minimum_required(VERSION 3.20)
project(DoubleDispatching)

set(CMAKE_CXX_STANDARD 17)

add_executable(DoubleDispatching main.cpp geo2d.cpp geo2d.h game_object.h test_runner.h)
