//
// Created by stelios on 13/09/2021.
//

#include "Sudoku.h"

std::istream &operator>>(std::istream &is, Sudoku &m){
    int aux;
    std::vector<std::set<int>> line;
    std::vector<std::set<int>> col;
    std::vector<std::set<int>> square;
    line.resize(9);
    col.resize(9);
    square.resize(9);
    for (int i = 0; i < 81; i++){
        is >> aux;
        m.mat[i] = aux;
        if (aux != 0){
            line[i / 9].insert(aux);
            col[i % 9].insert(aux);
            square[3 * (i / 27) + (i % 9) / 3].insert(aux);
        }
        else{
            std::set<int> a;
            m.dic.insert(std::make_pair(i, a));
        }
    }
    std::set<int> setAux;
    for (auto & it : m.dic){
        setAux.clear();
        int num = it.first;
        setAux.insert(line[num / 9].begin(), line[num / 9].end());
        setAux.insert(col[num % 9].begin(), col[num % 9].end());
        setAux.insert(square[3 * (num / 27) + (num % 9) / 3].begin(), square[3 * (num / 27) + (num % 9) / 3].end());
        for (int k = 1; k <= 9; k++){
            if (setAux.find(k) == setAux.end()){
                it.second.insert(k);
            }
        }
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, Sudoku &m){
    for (int i = 0; i < 81; i++){
        os << m.mat[i];
        if (i % 9 == 8)
            os << " \n";
        else
            os << " ";
    }
    return os;
}

bool Sudoku::solved(){
    if (dic.empty())
        return true;
    return false;
}

void Sudoku::solve1(){
    bool changed = true;
    std::set<int>::iterator itSet;
    while (changed){
        changed = false;
        for (auto it = dic.begin(); it != dic.end();){
            if (it->second.size() == 1){
                changed = true;
                auto it2 = it;
                it2++;
                substituteValue(it->first, *it->second.begin());
                it = it2;
            }
            else{
                it++;
            }
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
    bool valid, finded = false;
    auto it = dic.begin();
    unsigned int minValue = 0;
    while(!finded){
        while(it != dic.end() && !finded){
            if(minValue == it->second.size())
                finded = true;
            else
                it++;
        }
        if(!finded) {
            it = dic.begin();
            minValue++;
        }
    }
    for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++){
        aux = *this;
        valid = aux.substituteValue(it->first, *it2);
        if (valid){
            aux.solve();
            if (aux.solved()){
                *this = aux;
                return;
            }
        }
    }
}

bool Sudoku::substituteValue(int pos, int value){
    int aux;
    bool valid = true;
    std::set<int>::iterator itSet;
    this->mat[pos] = value;
    int indexCol = pos % 9;
    int indexLine = pos / 9;
    int indexSquare = 3 * (pos / 27) + (pos % 9) / 3;
    dic.erase(pos);
    for (int i = 0; i < 9 && valid; i++){
        for (int j = 0; j < 3 && valid; j++){
            if (j == 0)
                aux = 9 * indexLine + i;
            else if (j == 1)
                aux = 9 * i + indexCol;
            else
                aux = 27 * (indexSquare / 3) + 3 * (indexSquare % 3) + 9 * (i / 3) + i % 3;
            if (dic.find(aux) != dic.end()){
                itSet = dic.find(aux)->second.find(value);
                if (itSet != dic.find(aux)->second.end()) {
                    dic.find(aux)->second.erase(itSet);
                    if (dic.find(aux)->second.empty())
                        valid = false;
                }
            }
        }
    }
    return valid;
}
