#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define ROWS 8
#define COLS 8

enum { MODE_0, MODE_1, MODE_2, MODE_3 };

static int flag             = 0;

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

void pattern_base(int grid[ROWS][COLS], int start, int end) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (flag == 0) {
                if (i >= start && i <= end) grid[i][4] = 1;
                flag = 1;
            } else {
                if (j >= 3 && j <= 5) grid[4][j] = 1;
                flag = 0;
            }
        }
    }
}

void initializeGrid_random(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void gen_pattern_0(int grid[ROWS][COLS]) {
    // for (int i = 0; i < ROWS; i++) {
    //     for (int j = 0; j < COLS; j++) {
    //         pattern_0[i][j] = rand() % 2;
    //     }
    // }

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

void pattern_1(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (flag == 0) {
                if (i >= 3 && i <= 5) grid[i][4] = 1;
                flag = 1;
            } else {
                if (j >= 3 && j <= 5) grid[4][j] = 1;
                flag = 0;
            }
        }
    }
}

void pattern_2(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (flag == 0) {
                if (j >= 3 && j <= 5) grid[3][j] = 1;
                if (j >= 2 && j <= 4) grid[4][j] = 1;
            } else {
                if (i == 2) grid[i][4] = 1;
                if (i == 3) {
                    grid[i][2] = 1;
                    grid[i][5] = 1;
                }
            }
        }
    }

    flag = ~flag;
}

void pattern_3() {}


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

// void setGrid(int grid[ROWS][COLS], int mode) {
//     if (mode == MODE_0) { // random
//         for (int i = 0; i < ROWS; i++) {
//             for (int j = 0; j < COLS; j++) {
//                 grid[i][j] = rand() % 2;
//             }
//         }
//     } else if (mode == MODE_1) {
//         for (int i = 0; i < ROWS; i++) {
//             for (int j = 0; j < COLS; j++) {
//                 if (flag == 0) {
//                     if (i >= 3 && i <= 5) grid[i][4] = 1;
//                     flag = 1;
//                 } else {
//                     if (j >= 3 && j <= 5) grid[4][j] = 1;
//                     flag = 0;
//                 }
//             }
//         }
//     }
// }

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

#if 0
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = 0;

            // 计算邻居的数量
            for (int ni = i - 1; ni <= i + 1; ni++) {
                for (int nj = j - 1; nj <= j + 1; nj++) {
                    if (ni >= 0 && ni < ROWS && nj >= 0 && nj < COLS && !(ni == i && nj == j)) {
                        neighbors += grid[ni][nj];
                    }
                }
            }

            // 根据规则更新状态
            if (grid[i][j] == 1) {
                newGrid[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            } else {
                newGrid[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }
    }

#else
    static int flag = 0;
    // for (int i = 0; i < ROWS; i++) {
    //     for (int j = 0; j < COLS; j++) {
    //         if (mode == MODE_0) {
    //             grid[i][j] = rand() % 2;
    //         } else if (mode == MODE_1) {
    //             if (flag == 0) {
    //                 // setGrid(newGrid, MODE_0);
    //                 if (i >= 3 && i <= 5) grid[i][4] = 1;
    //             } else {
    //                 if (j >= 3 && j <= 5) grid[4][j] = 1;
    //             }
    //         } else if (mode == MODE_2) {
    //             if (flag == 0) {
    //                 if (i >= 3 && i <= 4) {
    //                     grid[][]
    //                 }
    //             }
    //         }
    //     }
    // }
    if(mode == MODE_0) {
        // printf("xxxxxx\n");
        gen_pattern_0(pattern_0);
        copyArray(8, 8, pattern_0, grid);
    } else if(mode == MODE_1) { 
        if(flag == 0) {
            copyArray(8, 8, pattern_1_0, grid);
        } else {
            copyArray(8, 8, pattern_1_1, grid);
        }
    } else if(mode == MODE_2) {
        if(flag == 0) {
            copyArray(8, 8, pattern_2_0, grid);
        } else {
            copyArray(8, 8, pattern_2_1, grid);
        }
    } else if(mode == MODE_3) {
        if(flag == 0) {
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

#endif
    // copy
    // for (int i = 0; i < ROWS; i++) {
    //     for (int j = 0; j < COLS; j++) {
    //         // printf("%d ", grid[i][j]);
    //         // grid[i][j] = newGrid[i][j];
    //     }
    //     // printf("\n");
    //     // printf("mode = %d\n", mode);
    // }
}

int main(int argc, char** argv) {
    int grid[ROWS][COLS];

    int mode = MODE_0;
    printf("argc = %d\n", argc);

    // initlize grid
    initializeGrid(grid);

    if(argc == 1) {
        mode = MODE_0;
        initializeGrid_random(grid);
        printf("RANDOM\n");
    } else if(strcmp(argv[1], "bLiNkEr") == 0) {
        mode = MODE_1;
        printf("bLiNkEr\n");
    } else if(strcmp(argv[1], "toad") == 0) {
        mode = MODE_2;
        printf("toad\n");
    } else if(strcmp(argv[1], "BEACON") == 0) {
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