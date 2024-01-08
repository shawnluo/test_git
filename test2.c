#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to initialize the game grid with random values
void initializeGrid(int rows, int cols, int grid[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to print the current state of the game grid
void printGrid(int rows, int cols, int grid[rows][cols]) {
    system("clear"); // Clear the console (UNIX/Linux)
    // Use "cls" for Windows, if you are using a Windows compiler

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                printf(" * ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

// Function to update the game grid based on the rules of the Game of Life
void updateGrid(int rows, int cols, int grid[rows][cols]) {
    int newGrid[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = 0;

            // Count live neighbors
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (i + x >= 0 && i + x < rows && j + y >= 0 && j + y < cols) {
                        neighbors += grid[i + x][j + y];
                    }
                }
            }

            // Exclude the current cell
            neighbors -= grid[i][j];

            // Apply rules
            if ((grid[i][j] == 1) && (neighbors < 2 || neighbors > 3)) {
                newGrid[i][j] = 0; // Cell dies
            } else if ((grid[i][j] == 0) && (neighbors == 3)) {
                newGrid[i][j] = 1; // Cell becomes alive
            } else {
                newGrid[i][j] = grid[i][j]; // Cell remains unchanged
            }
        }
    }

    // Copy the new grid back to the original grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    int rows = 10; // Number of rows in the grid
    int cols = 10; // Number of columns in the grid
    int grid[rows][cols];

    initializeGrid(rows, cols, grid);

    // Run the game for a certain number of iterations
    // for (int iteration = 0; iteration < 50; iteration++) {
    while(1) {
        printGrid(rows, cols, grid);
        updateGrid(rows, cols, grid);
        usleep(100000); // Sleep for 100,000 microseconds (0.1 seconds)
        // sleep(1);
    }

    return 0;
}
