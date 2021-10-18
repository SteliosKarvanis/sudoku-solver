cmake_minimum_required(VERSION 3.20)
project(Sudoku)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Sudoku
        main.cpp
        Sudoku.cpp
        Sudoku.h)
