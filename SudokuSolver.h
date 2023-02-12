//
// Created by samcbk on 20/12/22.
//

#ifndef SUDOKU_SUDOKUSOLVER_H
#define SUDOKU_SUDOKUSOLVER_H

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <stack>
#include "Sudoku.hpp"

enum class SOLVER_STATUS{
     UNSOLVED,
     UNIQUE,
     MULTIPLE,
     IMPOSSIBLE,
};

class SudokuSolver{
public:
    SudokuSolver() = default;
    static std::pair<Sudoku, SOLVER_STATUS> solve(Sudoku sudoku, SOLVER_STATUS solverStatus = SOLVER_STATUS::UNSOLVED);

private:
    static Sudoku fillUniqueMissing(Sudoku sudoku);
    static int getNextSearchPosition(const std::unordered_map<int, std::set<int>>& map);

};


#endif //SUDOKU_SUDOKUSOLVER_H
