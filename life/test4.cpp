#include <iostream>
#include <vector>
#include <unistd.h>
#include <ncurses.h>

const int rows = 20;
const int cols = 20;

void initialize(std::vector<std::vector<bool>>& grid) {
    // Initialize the grid with zeros
    grid.resize(rows, std::vector<bool>(cols, false));

    // Glider pattern
    grid[1][2] = true;
    grid[2][3] = true;
    grid[3][1] = true;
    grid[3][2] = true;
    grid[3][3] = true;
}

void printGrid(const std::vector<std::vector<bool>>& grid) {
    clear(); // Clear the screen

    int startRow = (LINES - rows) / 2;
    int startCol = (COLS - cols * 2) / 2;

    for (int i = 0; i < rows; ++i) {
        mvprintw(startRow + i, startCol, ""); // Move cursor
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j])
                printw("* ");
            else
                printw(". ");
        }
    }
    refresh();
}

int countNeighbors(const std::vector<std::vector<bool>>& grid, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue; // Skip the current cell
            int newX = x + i;
            int newY = y + j;
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                count += grid[newX][newY] ? 1 : 0;
            }
        }
    }
    return count;
}

void update(std::vector<std::vector<bool>>& grid) {
    std::vector<std::vector<bool>> newGrid = grid;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int neighbors = countNeighbors(grid, i, j);
            if (grid[i][j]) {
                if (neighbors < 2 || neighbors > 3)
                    newGrid[i][j] = false; // Cell dies
            } else {
                if (neighbors == 3)
                    newGrid[i][j] = true; // Cell becomes alive
            }
        }
    }

    grid = newGrid;
}

int main() {
    std::vector<std::vector<bool>> grid;
    initialize(grid);

    initscr(); // Initialize ncurses
    cbreak();
    noecho();
    keypad(stdscr, true);

    while (true) {
        printGrid(grid);
        refresh();
        int ch = getch(); // Get user input
        if (ch == ' ') {
            update(grid);
        } else if (ch == 'q') {
            break;
        }
    }

    endwin(); // End ncurses

    return 0;
}
