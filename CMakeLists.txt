cmake_minimum_required(VERSION 3.0.0)
project(Sudoku)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(Sudoku
        main.cpp
        Sudoku.cpp
        Sudoku.hpp)
