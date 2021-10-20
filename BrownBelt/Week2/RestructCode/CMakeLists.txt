cmake_minimum_required(VERSION 3.20)
project(RestructCode)

set(CMAKE_CXX_STANDARD 17)

add_executable(RestructCode main.cpp stats_aggregator.cpp stats_aggregator.h test_runner.h stats_aggregator_test.cpp)
