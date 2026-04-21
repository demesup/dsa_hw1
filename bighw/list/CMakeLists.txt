cmake_minimum_required(VERSION 3.27)
project(list)

set(CMAKE_CXX_STANDARD 14)

include_directories(dsa)

add_executable(list
        dsa/FlightBookingSystem.h
        dsa/main.cpp
)
