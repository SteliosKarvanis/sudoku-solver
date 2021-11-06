//
// Created by stelios on 13/09/2021.
//

#ifndef LAB1EX_MATRIX_HPP
#define LAB1EX_MATRIX_HPP

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

struct Sudoku{
public:
    Sudoku() = default;
    bool solved();
    void solve();
    friend std::istream& operator>>(std::istream& is, Sudoku& m);
    friend std::ostream& operator<<(std::ostream& os, Sudoku& m);

protected:
    bool substituteValue(int pos, int value);

private:
    std::vector<int>mat = static_cast<std::vector<int>>(81);
    void solve1();
    void solve2();
    std::unordered_map<int, std::set<int>> dic;
};


#endif //LAB1EX_MATRIX_HPP
