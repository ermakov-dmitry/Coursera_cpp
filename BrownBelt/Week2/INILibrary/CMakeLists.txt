cmake_minimum_required(VERSION 3.20)
project(INILibrary)

set(CMAKE_CXX_STANDARD 17)

add_executable(INILibrary main.cpp test_runner.h ini.cpp ini.h)
