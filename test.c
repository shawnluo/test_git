#include "common.h"
#include "test.h"


void myPrint(void *p, int x, int y) {
    int (*mat)[y] = p;
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            printf("%d, ", mat[i][j]);
        }
        printf("\n");
    }
}

void rotate(void *p, int x, int y) {
    int (*mat)[y] = p;
    myPrint(p, x, y);

    int mat2[y][x];
    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) {
        }
    }
    myPrint(mat2, y, x);
}

int main(void) {
    int mat[4][4] = {{0, 1, 2, 3}, 
                    {4, 5, 6, 7}, 
                    {8, 9, 10, 11},
                    {12, 13, 14, 15}};

    rotate(mat, 3, 4);

    return 0;
}