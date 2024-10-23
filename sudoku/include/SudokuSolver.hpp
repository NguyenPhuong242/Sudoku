#ifndef SUDOKUSOLVER_HPP
#define SUDOKUSOLVER_HPP

#include "SudokuGrid.hpp"

class SudokuSolver {
  public:
    SudokuSolver();
    bool solve(SudokuGrid& grid);
  private:
    bool isSafe(SudokuGrid& grid, int row, int col, int num);
    bool findEmptyLocation(SudokuGrid& grid, int& row, int& col);
    bool isSafeCol(SudokuGrid& grid, int col, int num);
    bool isSafeRow(SudokuGrid& grid, int row, int num);
    bool isSafeSubgrid(SudokuGrid& grid, int row, int col, int num);
};

#endif // SUDOKUSOLVER_HPP
