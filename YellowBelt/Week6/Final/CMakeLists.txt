cmake_minimum_required(VERSION 3.17)
project(Final)

set(CMAKE_CXX_STANDARD 17)

add_executable(Final main.cpp token.cpp token.h condition_parser.cpp condition_parser.h condition_parser_test.cpp date.cpp date.h database.cpp database.h node.cpp node.h test_runner.h test_db.cpp test_db.h overloaded_operators.cpp overloaded_operators.h)