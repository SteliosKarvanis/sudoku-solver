//
// Created by stelios on 15/09/2021.
//

#include "Sudoku.hpp"
#include "SudokuSolver.h"

int main(int argc, char *argv[]){
    shp<Sudoku> sudoku = mshp<Sudoku>("tests/1.in");
    std::cout << *sudoku << "\n";
    auto output = SudokuSolver::solve(*sudoku);
    auto solve = output.first;
    auto status = output.second;
    if (status == SOLVER_STATUS::UNIQUE) {
        //std::cout << solve << "\n";
        std::cout << "Solved\n";
    } else {
        std::cout << "Unsolved\n";
    }
    shp<Sudoku> sudoku2 = mshp<Sudoku>("tests/1.out");
//        std::cout << *sudoku2 << "\n";
//    for (int line = 0; line < 9; ++line) {
//        for (int col = 0; col < 9; ++col) {
//            if(solve.getValue(line, col) != sudoku2->getValue(line, col))
//                std::cout << line << " " << col << "\n";
//        }
//    }
    return 0;
}