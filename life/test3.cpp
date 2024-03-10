#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/ioctl.h>

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
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    int terminalRows = size.ws_row;
    int terminalCols = size.ws_col;

    int startRow = (terminalRows - rows) / 2;
    int startCol = (terminalCols - cols * 2) / 2;

    // Clear the screen
    std::cout << "\033[2J";
    std::cout.flush();

    // Move the cursor to the top-left corner
    std::cout << "\033[H";
    std::cout.flush();

    for (int i = 0; i < rows; ++i) {
        std::cout << "\033[" << startRow + i << ";" << startCol << "H"; // Move cursor
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j])
                std::cout << "* ";
            else
                std::cout << ". ";
        }
        std::cout << std::endl;
    }
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

    while (true) {
        printGrid(grid);
        update(grid);
        usleep(200000); // Sleep for 200ms
    }

    return 0;
}
