//
// Created by stelios on 15/09/2021.
//

#include "SudokuSolver.h"

int main(int argc, char *argv[]){
    for(int i = 1; i <= 46; i++) {
        shp<Sudoku> sudoku = mshp<Sudoku>("examples/" + std::to_string(i) + ".in");
        auto output = SudokuSolver::solve(*sudoku);
        Sudoku solve = output.first;
        SOLVER_STATUS status = output.second;
        if (status == SOLVER_STATUS::UNIQUE)
            std::cout << "Solved " + std::to_string(i) + "\n";
        else
            std::cout << "Unsolved " + std::to_string(i) + "\n";
    }
    return 0;
}