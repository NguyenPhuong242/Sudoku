#ifndef SUDOKUGUI_HPP
#define SUDOKUGUI_HPP

#include <SFML/Graphics.hpp>
#include "SudokuGrid.hpp"

class SudokuGUI {
public:
    SudokuGUI();
    void run(SudokuGrid &grid);  // Main method to run the GUI

private:
    void drawGrid(const SudokuGrid &grid);
    sf::RenderWindow window;
};

#endif
