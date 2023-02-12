//
// Created by samcbk on 20/12/22.
//

#include "SudokuSolver.h"

Sudoku SudokuSolver::fillUniqueMissing(Sudoku sudoku){
    bool changed = true;
    while(changed){
        changed = false;
        auto allPossibilities = sudoku.getAllPossibilities();
        for(const auto& possibilities : allPossibilities){
            if (possibilities.second.size() == 1){
                sudoku.putValue(possibilities.first, *(possibilities.second.begin()));
                changed = true;
            }
        }
    }
    return sudoku;
}

std::pair<Sudoku, SOLVER_STATUS> SudokuSolver::solve(Sudoku sudoku, SOLVER_STATUS solverStatus){
    // Fill unique possible values
    sudoku = fillUniqueMissing(sudoku);

    auto possibilities = sudoku.getAllPossibilities();
    if((int)possibilities.size() == 0)
        return std::make_pair(sudoku, SOLVER_STATUS::UNIQUE);
    // If not solved, guess a value in a possition with the lower number of possibilities
    int optimal_next_position = getNextSearchPosition(possibilities);
    for(const int & value : possibilities[optimal_next_position]){
        Sudoku next = sudoku;
        if (next.putValue(optimal_next_position, value)){
            auto output = solve(next, solverStatus);
            Sudoku finalSolution = output.first;
            SOLVER_STATUS finalStatus = output.second;
            if(finalStatus == SOLVER_STATUS::UNIQUE)
                return std::make_pair(finalSolution, finalStatus);
        }
    }
    return std::make_pair(sudoku, SOLVER_STATUS::UNSOLVED);
}

int SudokuSolver::getNextSearchPosition(const std::unordered_map<int, std::set<int>>& map){
    int minSize = 10;
    int optimal_next_position = -1;
    for(auto& it : map){
        int posSize = (int)it.second.size();
        if(posSize < minSize){
            minSize = posSize;
            optimal_next_position = it.first;
        }
    }
    return optimal_next_position;
}
