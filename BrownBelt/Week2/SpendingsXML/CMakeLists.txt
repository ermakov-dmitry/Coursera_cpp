cmake_minimum_required(VERSION 3.20)
project(SpendingsXML)

set(CMAKE_CXX_STANDARD 17)

add_executable(SpendingsXML main.cpp xml.cpp xml.h test_runner.h)
