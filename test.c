#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>
#include <limits.h>
#include <math.h>


//clock-wise
void rotate(int mat[4][4], int size) {
    /*
        top:        x,              y
        right:      y,              size - x - 1
        bottom:     size - x - 1,   size - y - 1
        left:       size - y - 1,   x
    */
   int x, y;
    for(x = 0; x < size / 2; x++) {
        for(y = 0; y < size / 2; y++) {
            int save = mat[x][y];
            mat[x][y] = mat[size - y - 1][x];
            mat[size - y - 1][x] = mat[size - x - 1][size - y - 1];
            mat[size - x - 1][size - y - 1] = mat[y][size - x - 1];
            mat[y][size - x - 1] = save;
        }
   }
    for(x = 0; x < size; x++) {
        for(y = 0; y < size; y++) {
            printf("%d\t", mat[x][y]);
        }
        printf("\n");
    }
}

void spiral matrix() {

}

int main(void) {
    char s1[] = "abxcy";
    char s2[] = "axabccx";

    int size1 = strlen(s1);
    int size2 = strlen(s2);

    int mat[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    rotate(mat, 4);

    return 0;
}