//
// Created by stelios on 13/09/2021.
//

#include "Sudoku.hpp"

Sudoku::Sudoku() {
    memset(table, 0, sizeof(table));
    createAllPossibilities();
}

Sudoku::Sudoku(const std::string& filename) {
    if(!getFromFile(filename)){
        memset(table, 0, sizeof(table));
        createAllPossibilities();
    }
}

bool Sudoku::getFromFile(const std::string& filename) {
    std::ifstream file(("../" + filename).c_str());
    if(file.bad())
        return false;
    std::string text_line;
    for (auto& line : table) {
        std::getline(file, text_line);
        std::stringstream ss(text_line);
        for (int& num : line) {
            ss >> num;
        }
    }
    file.close();
    this->createAllPossibilities();
    return true;
}

void Sudoku::saveInFile(const std::string& filename) const{
    std::string outputFolder = "../output";
    if (!std::filesystem::is_directory(outputFolder))
        system(("mkdir " + outputFolder).c_str());
    std::ofstream file(outputFolder + "/" + filename);
    for (const auto & line : this->table){
        for (const int& num : line)
            file << num << " ";
        file << "\n";
    }
    file.close();
}

int Sudoku::getSquare(int line, int col){
    int squareRow = line / 3;
    int squareCol = col / 3;
    return 3 * squareRow + squareCol;
}

int Sudoku::getSquare(int pos){
    return Sudoku::getSquare(pos / 9, pos % 9);
}

int Sudoku::getPos(int line, int col){
    return 9 * line + col;
}

int Sudoku::getLine(int pos){
    return pos / 9;
}

int Sudoku::getCol(int pos){
    return pos % 9;
}

std::istream &operator>>(std::istream &is, Sudoku &sudoku){
    for(auto& line : sudoku.table)
        for(int& num : line)
            is >> num;
    sudoku.createAllPossibilities();
    return is;
}

std::ostream &operator<<(std::ostream &os, const Sudoku &sudoku){
    for (const auto& line : sudoku.table){
        for (const int& num : line)
            os << num << " ";
        os << "\n";
    }
    return os;
}

std::set<int> Sudoku::getPossibilities(int pos){
    return possibilities[pos];
}

std::set<int> Sudoku::getPossibilities(int line, int col){
    return getPossibilities(getPos(line, col));
}

bool Sudoku::putValue(int line, int col, int value){
    if(line < 0 || line >= 9 || col < 0 || col >= 9 || value <= 0 || value > 9 || getValue(line, col) != 0
       || possibilities[getPos(line, col)].find(value) == possibilities[getPos(line, col)].end())
        return false;
    this->table[line][col] = value;
    this->updatePossibilities(line, col);
    return true;
}

bool Sudoku::putValue(int pos, int value) {
    return putValue(getLine(pos), getCol(pos), value);
}

bool Sudoku::isSolved() const{
    return possibilities.empty();
}

void Sudoku::updatePossibilities(int line, int col){
    return updatePossibilities(getPos(line, col));
}

void Sudoku::updatePossibilities(int pos) {
    possibilities.erase(pos);
    int value = getValue(pos);
    std::set<int> positions = getInfluentPositions(pos);
    for (const int& position : positions)
        if(possibilities.find(position) != possibilities.end() && possibilities[position].find(value) != possibilities[position].end())
            possibilities[position].erase(value);
}

std::set<int> Sudoku::getInfluentPositions(int line, int col){
    std::set<int> positions;
    int pos = getPos(line, col);
    int square = getSquare(line, col);
    for (int index = 0; index < 9; ++index) {
        positions.insert(getPos(line, index));
        positions.insert(getPos(index, col));
        positions.insert(getPos(3*(square / 3) + index / 3, 3*(square % 3) + index % 3));
    }
    positions.erase(pos);
    return positions;
}

std::set<int> Sudoku::getInfluentPositions(int pos){
    return getInfluentPositions(getLine(pos), getCol(pos));
}

int Sudoku::getValue(int line, int col) const{
    return table[line][col];
}

int Sudoku::getValue(int pos) const{
    return getValue(getLine(pos), getCol(pos));
}

void Sudoku::createPossibilities(int pos) {
    std::set<int> allPossibilities = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::set<int> positions = getInfluentPositions(pos);
    for (int position : positions)
        allPossibilities.erase(getValue(position));
    possibilities[pos] = allPossibilities;
}

void Sudoku::createAllPossibilities() {
    for (int pos = 0; pos < 81; pos++)
        if(getValue(pos) == 0)
            createPossibilities(pos);
}

bool operator==(const Sudoku& sudoku1, const Sudoku& sudoku2) {
    for(int line = 0; line < 9; line++){
        for (int col = 0; col < 9; ++col) {
            if(sudoku1.getValue(line, col) != sudoku2.getValue(line, col))
                return false;
        }
    }
    return true;
}

std::unordered_map<int, std::set<int>> Sudoku::getAllPossibilities() const{
    return possibilities;
}