#include "SudokuSolver.hpp"
#include <iostream>
#include <cassert>

SudokuSolver::SudokuSolver() {}

bool SudokuSolver::solve(SudokuGrid &grid)
{
    int row, col;

    if (!findEmptyLocation(grid, row, col))
        return true;

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid.setCell(row, col, num);
            if (solve(grid))
                return true;
            grid.setCell(row, col, 0); // backtrack
        }
    }

    return false;
}

bool SudokuSolver::isSafe(SudokuGrid &grid, int row, int col, int num)
{
    assert(row >= 0 && row < 9);  // Ensure row is within bounds
    assert(col >= 0 && col < 9);  // Ensure column is within bounds
    // Implement safety checks (row, column, and subgrid)
    // Return true if it's safe to place the number
    // Otherwise, return false
    if (!isSafeRow(grid, row, num) || !isSafeCol(grid, col, num) || !isSafeSubgrid(grid, row - row % 3, col - col % 3, num))
    {
        return false;
    }

    return true;
}

bool SudokuSolver::findEmptyLocation(SudokuGrid &grid, int &row, int &col) {
    for (row = 0; row < 9; ++row) {
        for (col = 0; col < 9; ++col) {
            if (grid.getCell(row, col) == 0) {
                return true;  // Found an empty location
            }
        }
    }
    return false;  // No empty location found
}


bool SudokuSolver::isSafeCol(SudokuGrid &grid, int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (grid.getCell(i, col) == num)
        {
            return false;
        }
    }
    return true;
}

bool SudokuSolver::isSafeRow(SudokuGrid &grid, int row, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (grid.getCell(row, i) == num)
        {
            return false;
        }
    }
    return true;
}

bool SudokuSolver::isSafeSubgrid(SudokuGrid &grid, int row, int col, int num)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid.getCell(i + row, j + col) == num)
            {
                return false;
            }
        }
    }
    return true;
}
