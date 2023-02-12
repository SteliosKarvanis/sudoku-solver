cmake_minimum_required(VERSION 3.0.0)
project(Sudoku)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wextra -Wall -O0 -g -pedantic -lm -fsanitize=address,leak,undefined")

include_directories(.)

file(GLOB cpp_files "*.cpp")
add_executable(test_all data_structures/Sudoku.cpp solver/SudokuSolver.cpp tests/test_all.cpp)
add_executable(test solver/SudokuSolver.cpp data_structures/Sudoku.cpp tests/test.cpp)
