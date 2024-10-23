CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -g

LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = src/main.cpp src/SudokuSolver.cpp src/SudokuGrid.cpp src/SudokuUtils.cpp src/SudokuGUI.cpp
OBJ = $(SRC:.cpp=.o)

TARGET = SudokuSolver

TEST_SRC = test/test_sudoku.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)
TEST_TARGET = test_sudoku

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

test: $(TEST_TARGET)

$(TEST_TARGET): src/SudokuSolver.o src/SudokuGrid.o src/SudokuUtils.o src/SudokuGUI.o $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) src/SudokuSolver.o src/SudokuGrid.o src/SudokuUtils.o src/SudokuGUI.o $(TEST_OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ) $(TARGET) $(TEST_OBJ) $(TEST_TARGET)
