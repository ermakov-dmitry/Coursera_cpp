cmake_minimum_required(VERSION 3.17)
project(sort_students)

set(CMAKE_CXX_STANDARD 17)

add_executable(sort_students main.cpp test_runner.h student.h profile.h)