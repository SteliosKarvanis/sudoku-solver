//
// Created by stelios on 15/09/2021.
//

#include "Sudoku.h"

int main(){
    Matrix a;
    std::cin>>a;
    a.solve();
    if(a.solved())
        std::cout<<a;
    else
        std::cout<<"Nao\n";
    return 0;
}