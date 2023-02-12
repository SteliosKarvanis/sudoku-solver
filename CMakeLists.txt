cmake_minimum_required(VERSION 3.0.0)
project(Sudoku)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wextra -Wall -O0 -g -pedantic -lm -fsanitize=address,leak,undefined")

include_directories(.)
file(GLOB cpp_files "*.cpp")
add_executable(program Sudoku.cpp SudokuSolver.cpp main.cpp)
add_executable(test SudokuSolver.cpp Sudoku.cpp test.cpp)
