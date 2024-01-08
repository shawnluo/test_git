#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif

#include "life.h"

static int flag = 0;

void initializeGrid_random(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void gen_pattern_0(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = 0;

            // Count live neighbors
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (i + x >= 0 && i + x < ROWS && j + y >= 0 && j + y < COLS) {
                        neighbors += grid[i + x][j + y];
                    }
                }
            }

            // Exclude the current cell
            neighbors -= grid[i][j];

            // Apply rules
            if ((grid[i][j] == 1) && (neighbors < 2 || neighbors > 3)) {
                pattern_0[i][j] = 0; // Cell dies
            } else if ((grid[i][j] == 0) && (neighbors == 3)) {
                pattern_0[i][j] = 1; // Cell becomes alive
            } else {
                pattern_0[i][j] = grid[i][j]; // Cell remains unchanged
            }
            // printf("%d ", grid[i][j]);
        }
    }
}

// initlize grid, set to all 0
void initializeGrid(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = 0;
        }
    }
}

// print grid
void printGrid(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("* ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void copyArray(int src[ROWS][COLS], int dst[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            dst[i][j] = src[i][j];
        }
    }
}

// update grid
void updateGrid(int grid[ROWS][COLS], int mode) {
    // int newGrid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // grid[i][j] = 0;
        }
    }

    static int flag = 0;
    if (mode == MODE_0) {
        // printf("xxxxxx\n");
        gen_pattern_0(grid);
        copyArray(pattern_0, grid);
    }
    else if (mode == MODE_1) {
        if (flag == 0) {
            copyArray(pattern_1_0, grid);
        }
        else {
            copyArray(pattern_1_1, grid);
        }
    }
    else if (mode == MODE_2) {
        if (flag == 0) {
            copyArray(pattern_2_0, grid);
        }
        else {
            copyArray(pattern_2_1, grid);
        }
    }
    else if (mode == MODE_3) {
        if (flag == 0) {
            copyArray(pattern_3_0, grid);
        }
        else {
            copyArray(pattern_3_1, grid);
        }
    }

    flag = ~flag;
}

int main(int argc, char** argv) {
    int grid[ROWS][COLS];

    int mode = MODE_0;

    // initlize grid
    initializeGrid(grid);

    if (argc == 1) {
        mode = MODE_0;
        initializeGrid_random(grid);
        printf("RANDOM\n");
    } else if (strcmp(argv[1], "bLiNkEr") == 0) {
        mode = MODE_1;
        printf("bLiNkEr\n");
    } else if (strcmp(argv[1], "toad") == 0) {
        mode = MODE_2;
        printf("toad\n");
    } else if (strcmp(argv[1], "BEACON") == 0) {
        mode = MODE_3;
        printf("BEACON\n");
    }

    // loop
    while (1) {
        sleep(1);
        #ifdef __unix__
        system("clear");
        #elif defined _WIN32
        system("cls");
        #endif

        printGrid(grid);
        updateGrid(grid, mode);
        //usleep(100000); // sleep 1 second
        sleep(1);
    }

    return 0;
}