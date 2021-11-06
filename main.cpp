//
// Created by stelios on 15/09/2021.
//

#include "Sudoku.h"

int main(){
    Sudoku a;
    std::cin>>a;
    a.solve();
    if(a.solved())
        std::cout<<a;
    return 0;
}