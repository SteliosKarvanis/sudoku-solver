//
// Created by stelios on 15/09/2021.
//

#include "solver/SudokuSolver.hpp"

int main(int argc, char *argv[]){
    shp<Sudoku> sudoku = mshp<Sudoku>("examples/1.in");
    auto output = SudokuSolver::solve(*sudoku);
    Sudoku solve = output.first;
    SOLVER_STATUS status = output.second;
    if (status == SOLVER_STATUS::UNIQUE) {
        std::cout << "Solved\n";
    } else {
        std::cout << "Unsolved\n";
    }
    return 0;
}