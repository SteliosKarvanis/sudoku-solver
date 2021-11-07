//
// Created by stelios on 13/09/2021.
//

#include "Sudoku.hpp"

std::istream &operator>>(std::istream &is, Sudoku &m){
    int aux;
    std::vector<std::set<int>> line, col, square;
    line.resize(9);
    col.resize(9);
    square.resize(9);
    for (int i = 0; i < 81; i++){
        is >> aux;
        m.nums[i] = aux;
        if (aux != 0){
            line[i / 9].insert(aux);
            col[i % 9].insert(aux);
            square[3 * (i / 27) + (i % 9) / 3].insert(aux);
        }
        else{
            std::set<int> a;
            m.missing.insert(std::make_pair(i, std::move(a)));
        }
    }
    std::set<int> setAux;
    for (auto & it : m.missing){
        setAux.clear();
        int num = it.first;
        setAux.insert(line[num / 9].begin(), line[num / 9].end());
        setAux.insert(col[num % 9].begin(), col[num % 9].end());
        setAux.insert(square[3 * (num / 27) + (num % 9) / 3].begin(), square[3 * (num / 27) + (num % 9) / 3].end());
        for (int k = 1; k <= 9; k++)
            if (setAux.find(k) == setAux.end())
                it.second.insert(k);
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Sudoku &m){
    for (int i = 0; i < 81; i++){
        os << m.nums[i];
        if (i % 9 == 8)
            os << " \n";
        else
            os << " ";
    }
    return os;
}

bool Sudoku::solved(){
    if (missing.empty())
        return true;
    return false;
}

void Sudoku::solve1(){
    bool changed = true;
    std::set<int>::iterator itSet;
    while (changed){
        changed = false;
        for (auto it = missing.begin(); it != missing.end();){
            if (it->second.size() == 1){
                changed = true;
                auto it2 = it;
                it2++;
                putValue(it->first, *it->second.begin());
                it = it2;
            }
            else
                it++;
        }
    }
}

void Sudoku::solve(){
    solve1();
    if (!solved())
        solve2();
}

void Sudoku::solve2(){
    Sudoku aux;
    auto it = missing.begin();
    unsigned int minValue = 0;
    while(minValue != it->second.size()){
        it++;
        if(it == missing.end()){
            it = missing.begin();
            minValue++;
        }
    }
    for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++){
        aux = *this;
        if (aux.putValue(it->first, *it2)){
            aux.solve();
            if (aux.solved()){
                *this = aux;
                return;
            }
        }
    }
}

bool Sudoku::putValue(const int& pos, const int& value){
    int aux;
    std::set<int>::iterator itSet;
    this->nums[pos] = value;
    int indexCol = pos % 9;
    int indexLine = pos / 9;
    int indexSquare = 3 * (pos / 27) + (pos % 9) / 3;
    missing.erase(pos);
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 3; j++){
            if (j == 0)
                aux = 9 * indexLine + i;
            else if (j == 1)
                aux = 9 * i + indexCol;
            else
                aux = 27 * (indexSquare / 3) + 3 * (indexSquare % 3) + 9 * (i / 3) + i % 3;
            if (missing.find(aux) != missing.end()){
                itSet = missing.find(aux)->second.find(value);
                if (itSet != missing.find(aux)->second.end()) {
                    missing.find(aux)->second.erase(itSet);
                    if (missing.find(aux)->second.empty())
                        return false;
                }
            }
        }
    }
    return true;
}
