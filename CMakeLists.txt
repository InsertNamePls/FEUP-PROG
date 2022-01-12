cmake_minimum_required(VERSION 3.16)
project(FEUP_PROG)

set(CMAKE_CXX_STANDARD 14)

include_directories(LAB7)

add_executable(FEUP_PROG1
        LAB7/exc1.cpp
        LAB7/exc1.h)

add_executable(FEUP_PROG3
        LAB7/exc3.cpp
        LAB7/exc3.h)
