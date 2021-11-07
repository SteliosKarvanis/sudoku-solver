//
// Created by stelios on 15/09/2021.
//

#include "Sudoku.hpp"

int main(){
    Sudoku a;
    std::cin>>a;
    a.solve();
    if(a.solved())
        std::cout<<a;
    else
        std::cout<<"Not Solved\n";
    return 0;
}