#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int index;
    int rep;
} Node, *pNode;

#define SIZE sizeof(Node)

void rotate(int mat[][4], int size) {
    int x, y;
    int save;

    for(x = 0; x < size / 2; x++) {
        for(y = 0; y < size / 2; y++) {
            save                            = mat[x][y];
            mat[x][y]                       = mat[y][size - x - 1];
            mat[y][size - x - 1]            = mat[size - x - 1][size - y - 1];
            mat[size - x - 1][size - y - 1] = mat[size - y - 1][x];
            mat[size - y - 1][x]            = save;
        }
    }

    for(x = 0; x < size; x++) {
        for(y = 0; y < size; y++) {
            printf("%d ", mat[x][y]);
        }
        printf("\n");
    }
}

int main(void) {
    int mat[][4] = {{1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 11, 12},
                    {13, 14, 15, 16}};

    rotate(mat, 4);

    return 0;
}