//
// Created by stelios on 13/09/2021.
//

#ifndef LAB1EX_MATRIX_HPP
#define LAB1EX_MATRIX_HPP

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>

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
/*
for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++){ // substitui um valor do dic
        aux = *this;
        int value = *it2;
        aux.substituteValue(it->first, *it2);
        aux.mat[it->first] = value;
        int indexCol = it->first % 9;
        int indexLine = it->first / 9;
        int indexSquare = 3 * (it->first / 27) + (it->first % 9) / 3;
        int aux2;
        std::set<int>::iterator itSet;
        bool valid = true;
        aux.dic.erase(it->first);
        for (int i = 0; i < 9 && valid; i++){
            for (int j = 0; j < 3 && valid; j++){
                if (j == 0)
                    aux2 = 9 * indexLine + i;
                else if (j == 1)
                    aux2 = 9 * i + indexCol;
                else
                    aux2 = 27 * (indexSquare / 3) + 3 * (indexSquare % 3) + 9 * (i / 3) + i % 3;
                if (aux.dic.find(aux2) != aux.dic.end()){
                    itSet = aux.dic.find(aux2)->second.find(value);
                    if (itSet != aux.dic.find(aux2)->second.end()){
                        aux.dic.find(aux2)->second.erase(itSet);
                        if (aux.dic.find(aux2)->second.empty())
                            valid = false;
                    }
                }
            }
            */