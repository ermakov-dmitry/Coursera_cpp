cmake_minimum_required(VERSION 3.20)
project(RAIIBooking)

set(CMAKE_CXX_STANDARD 17)

add_executable(RAIIBooking main.cpp test_runner.h new_trip_manager.h new_booking_providers.h old_booking_providers.h old_trip_manager.h booking.h)
