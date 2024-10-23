#ifndef SUDOKUGRID_HPP
#define SUDOKUGRID_HPP

#include <vector>
#include <string>

using namespace std;

class SudokuGrid {
    public:
        SudokuGrid();
        bool loadFromFile(const string& filename);
        void printGrid() const;
        bool setCell(int row, int col, int value);
        int getCell(int row, int col) const; 
    private:
        vector<vector<int>> grid;

};

#endif // SUDOKUGRID_HPP