#include "SudokuGUI.hpp"
#include "SudokuGrid.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

SudokuGUI::SudokuGUI() : window(VideoMode(600, 600), "Sudoku Solver") {}

void SudokuGUI::run(SudokuGrid &grid) {
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::White);
        drawGrid(grid);
        window.display();
    }
}

void SudokuGUI::drawGrid(const SudokuGrid &grid) {
    const float cellSize = 600.0f / 9.0f;
    
    Font font;
    font.loadFromFile("arial.ttf");

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            RectangleShape cell(Vector2f(cellSize, cellSize));
            cell.setPosition(j * cellSize, i * cellSize);
            cell.setOutlineThickness(2);
            cell.setOutlineColor(Color::Black);
            window.draw(cell);

            int number = grid.getCell(i, j);
            if (number != 0) {
                Text text;
                text.setFont(font);
                text.setString(std::to_string(number));
                text.setCharacterSize(32);
                text.setFillColor(Color::Black);
                text.setPosition(j * cellSize + 20, i * cellSize + 10);
                window.draw(text);
            }
        }
    }
}
