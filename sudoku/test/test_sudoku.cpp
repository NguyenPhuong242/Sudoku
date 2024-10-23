#include "SudokuSolver.hpp"
#include "SudokuGrid.hpp"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Create a test case
    SudokuGrid grid;
    if (!grid.loadFromFile("test/test_cases/test_sudoku.txt"))
    {
        cerr << "Error loading sample Sudoku puzzle." << endl;
        return 1;
    }
    grid.loadFromFile("test/test_cases/test_sudoku.txt");

    SudokuSolver solver;
    assert(solver.solve(grid));

    cout << "All tests passed!" << endl;
    return 0;
}
