#include "SudokuSolver.hpp"
#include "SudokuGrid.hpp"
#include "SudokuGUI.hpp"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <sudoku_file>" << endl;
        return 1;
    }

    SudokuGrid grid;
    if (!grid.loadFromFile(argv[1])) {
        cerr << "Error loading Sudoku puzzle." << endl;
        return 1;
    }

    SudokuSolver solver;
    if (solver.solve(grid)) {
        cout << "Solved Sudoku!" << endl;
        SudokuGUI gui;
        gui.run(grid);  // Display the solved Sudoku grid using the GUI
    } else {
        cout << "No solution exists for this Sudoku puzzle." << endl;
    }

    return 0;
}
