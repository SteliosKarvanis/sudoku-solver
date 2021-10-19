
#include "Sudoku.h"

std::istream& operator>>(std::istream& is, Matrix& m) {
    int aux;
    std::vector<std::set<int>>line = static_cast<std::vector<std::set<int>>>(9);
    std::vector<std::set<int>>col = static_cast<std::vector<std::set<int>>>(9);
    std::vector<std::set<int>>square = static_cast<std::vector<std::set<int>>>(9);
    for (int i = 0; i < 81; i++) {
        std::cin >> aux;
        m.mat[i] = aux;
        if(aux != 0) {
            line[i / 9].insert(aux);
            col[i % 9].insert(aux);
            square[3 * (i / 27) + (i % 9) / 3].insert(aux);
        }
        else {
            std::set<int> a;
            m.dic.insert(std::make_pair(i, a));
        }
    }
    std::set<int> setAux;
    for(auto it = m.dic.begin(); it != m.dic.end(); it++) {
        setAux.clear();
        int num = it->first;
        setAux.insert(line[num / 9].begin(), line[num / 9].end());
        setAux.insert(col[num % 9].begin(), col[num % 9].end());
        setAux.insert(square[3 * (num / 27) + (num % 9) / 3].begin(), square[3 * (num / 27) + (num % 9) / 3].end());
        for(int k = 1; k <= 9; k++){
            if(setAux.find(k) == setAux.end()){
                it->second.insert(k);
            }
        }
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, Matrix& m) {
    for (int i = 0; i < 81; i++) {
        std::cout<<m.mat[i];
        if(i % 9 == 8)
            std::cout<<"\n";
        else
            std::cout<<" ";
    }
    return os;
}

bool Matrix::solved() {
    if(dic.empty()){
        return true;
    }
    return false;
}

void Matrix::solve1() {
    bool changed = true;
    while(changed) {
        changed = false;
        for (auto it = dic.begin(); it != dic.end();) {
            if (it->second.size() == 1) {
                int key = *it->second.begin();
                this->mat[it->first] = key;
                changed = true;
                int indexCol = it->first % 9;
                int indexLine = it->first / 9;
                int indexSquare = 3 * (it->first / 27) + (it->first % 9) / 3;
                int aux;
                std::set<int>::iterator itSet, itAux;
                for(int i = 0; i < 9; i++){
                    aux = 9 * indexLine + i;
                    if(dic.find(aux) != dic.end()) { // se achar o ponto no dic
                        itSet = dic.find(aux)->second.find(key); // cria um iterator para o elemento no set
                        if(itSet != dic.find(aux)->second.end()) // se encotrar o elemento no set
                            dic.find(aux)->second.erase(itSet);
                    }
                    aux = 9 * i + indexCol;
                    if(dic.find(aux) != dic.end()) {
                        itSet = dic.find(aux)->second.find(key);
                        if(itSet != dic.find(aux)->second.end())
                            dic.find(9 * i + indexCol)->second.erase(itSet);
                    }
                    aux = 27 * (indexSquare / 3) + 3 * (indexSquare % 3) + 9 * (i / 3) + i % 3;
                    if(dic.find(aux) != dic.end()) {
                        itSet = dic.find(aux)->second.find(key);
                        if (itSet != dic.find(aux)->second.end())
                            dic.find(aux)->second.erase(itSet);
                    }
                }
                auto it2 = it;
                it2++;
                this->dic.erase(it);
                it = it2;
            }
            else {
                it++;
            }
        }
    }
}



void Matrix::solve(){
    while(!solved()){
        solve1();
    }
}