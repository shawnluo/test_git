#include "test.hpp"

void myPrint(void *p, int N) {
    int (*mat)[N] = p;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d, ", mat[i][j]);
        }
        printf("\n");
    }
}

void rotate_matrix(void *p, int N) {
    int (*mat)[N] = p;
    
    myPrint(mat, N);

    for(int x = 0; x < N / 2; x++) {
        for(int y = 0; y < N / 2; y++) {
            int save = mat[x][y];
            mat[x][y]                       = mat[y][N - x - 1];
            mat[y][N - x - 1]             = mat[N - x - 1][N - y - 1];
            mat[N - x - 1][N - y - 1]   = mat[N - y - 1][x];
            mat[N - y - 1][x] = save;
        }
    }
    myPrint(mat, N);
}


int main(void) {
    int mat[3][3] = { { 1, 2, 3 },
                                { 4, 5, 6 },
                                { 7, 8, 9 } };
    rotate_matrix(mat, 3);
    // showMe(mat);

    return 0;
}