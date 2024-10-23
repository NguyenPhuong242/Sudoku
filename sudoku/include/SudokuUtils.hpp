#ifndef SUDOKUUTILS_HPP
#define SUDOKUUTILS_HPP

#include "SudokuGrid.hpp"

using namespace std;

bool validateGrid(const SudokuGrid &grid);
bool readInputFromFile(const string &filename, SudokuGrid &grid);

#endif // SUDOKUUTILS_HPP