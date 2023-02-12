//
// Created by stelios on 15/09/2021.
//

#include "Sudoku.hpp"
#include "SudokuSolver.h"

int main(int argc, char *argv[]){
    for(int i = 1; i <= 46; i++) {
        shp<Sudoku> sudoku = mshp<Sudoku>("tests/" + std::to_string(i) + ".in");
        auto output = SudokuSolver::solve(*sudoku);
        auto solve = output.first;
        auto status = output.second;
        if (status == SOLVER_STATUS::UNIQUE) {
            //std::cout << solve << "\n";
            std::cout << "Solved" + std::to_string(i) + "\n";
        } else {
            std::cout << "Unsolved " + std::to_string(i) + "\n";
        }

        shp<Sudoku> sudoku2 = mshp<Sudoku>("tests/" + std::to_string(i) + ".out");
//        std::cout << *sudoku2 << "\n";
//    for (int line = 0; line < 9; ++line) {
//        for (int col = 0; col < 9; ++col) {
//            if(solve.getValue(line, col) != sudoku2->getValue(line, col))
//                std::cout << line << " " << col << "\n";
//        }
//    }
    }
    return 0;
}