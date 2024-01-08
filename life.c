#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ROWS 8
#define COLS 8

enum { MODE_0, MODE_1, MODE_2, MODE_3 };

static int flag = 0;

int pattern_0[ROWS][COLS] = {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};

int pattern_1_0[ROWS][COLS] = {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 1, 0, 0, 0 },
    { 0, 0, 0, 0, 1, 0, 0, 0 },
    { 0, 0, 0, 0, 1, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};

int pattern_1_1[ROWS][COLS] = {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 1, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};

int pattern_2_0[ROWS][COLS] = {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 1, 1, 0, 0 },
    { 0, 0, 1, 1, 1, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};

int pattern_2_1[ROWS][COLS] = {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 1, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0, 1, 0, 0 },
    { 0, 0, 0, 1, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};

int pattern_3_0[ROWS][COLS] = {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 1, 1, 0 },
    { 0, 0, 0, 0, 0, 1, 1, 0 },
    { 0, 0, 0, 1, 1, 0, 0, 0 },
    { 0, 0, 0, 1, 1, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};

int pattern_3_1[ROWS][COLS] = {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 1, 1, 0 },
    { 0, 0, 0, 0, 0, 0, 1, 0 },
    { 0, 0, 0, 1, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 1, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};

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

void copyArray(int rows, int cols, int (*source)[cols], int (*destination)[cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            destination[i][j] = source[i][j];
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
        copyArray(8, 8, pattern_0, grid);
    } else if (mode == MODE_1) {
        if (flag == 0) {
            copyArray(8, 8, pattern_1_0, grid);
        } else {
            copyArray(8, 8, pattern_1_1, grid);
        }
    } else if (mode == MODE_2) {
        if (flag == 0) {
            copyArray(8, 8, pattern_2_0, grid);
        } else {
            copyArray(8, 8, pattern_2_1, grid);
        }
    } else if (mode == MODE_3) {
        if (flag == 0) {
            copyArray(8, 8, pattern_3_0, grid);
        } else {
            copyArray(8, 8, pattern_3_1, grid);
        }
    }

    flag = ~flag;
    // printf("%d ", flag);;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // printf("%d ", grid[i][j]);;
        }
        // printf("\n");
    }
}

int main(int argc, char** argv) {
    int grid[ROWS][COLS];

    int mode = MODE_0;
    printf("argc = %d\n", argc);

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
        system("clear"); // clear the screen，Windows uses "cls"
        printGrid(grid);
        updateGrid(grid, mode);
        usleep(100000); // sleep 1 second
        // sleep(1);
    }

    return 0;
}