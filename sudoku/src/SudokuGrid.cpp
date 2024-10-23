#include "SudokuGrid.hpp"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

SudokuGrid::SudokuGrid() : grid(9, vector<int>(9, 0)) {}

bool SudokuGrid::loadFromFile(const std::string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return false;
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (!(file >> grid[i][j])) {
                cerr << "Error: Not enough numbers in the file" << endl;
                return false;
            }
        }
    }
    return true;
}


void SudokuGrid::printGrid() const {
    for (const auto &row : grid) {
        for (const auto &cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

bool SudokuGrid::setCell(int row, int col, int value) {
    grid[row][col] = value;
    return true;
}

int SudokuGrid::getCell(int row, int col) const {
    return grid[row][col];
}






