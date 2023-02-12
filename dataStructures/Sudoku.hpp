//
// Created by stelios on 13/09/2021.
//

#ifndef LAB1EX_MATRIX_HPP
#define LAB1EX_MATRIX_HPP

#include <iostream>
#include <set>
#include <unordered_map>
#include <fstream>
#include <cstring>
#include <filesystem>

#define shp std::shared_ptr
#define mshp std::make_shared

struct Sudoku{
public:
    Sudoku();
    explicit Sudoku(const std::string& filename);
    ~Sudoku() = default;
    bool getFromFile(const std::string& filename);
    void saveInFile(const std::string& filename) const;
    friend std::istream& operator>>(std::istream& is, Sudoku& sudoku);
    friend std::ostream& operator<<(std::ostream& os, const Sudoku& sudoku);
    friend bool operator==(const Sudoku& sudoku1, const Sudoku& sudoku2);
    std::unordered_map<int, std::set<int>> getAllPossibilities() const;
    std::set<int> getPossibilities(int pos);
    std::set<int> getPossibilities(int line, int col);
    bool putValue(int pos, int value);
    bool putValue(int line, int col, int value);
    bool isSolved() const;
    int getValue(int pos) const;
    int getValue(int line, int col) const;
protected:
    static int getSquare(int line, int col) ;
    static int getSquare(int pos) ;
    static int getLine(int pos) ;
    static int getCol(int pos) ;
    static int getPos(int line, int col) ;
    static std::set<int> getInfluentPositions(int line, int col) ;
    static std::set<int> getInfluentPositions(int pos) ;

    void updatePossibilities(int pos);
    void updatePossibilities(int line, int col);

private:
    void createAllPossibilities();
    void createPossibilities(int pos);
    int table[9][9];
    std::unordered_map<int, std::set<int>> possibilities;
};

#endif //LAB1EX_MATRIX_HPP
