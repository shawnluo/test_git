#include "common.h"
#include "test.h"


#if 0
void rotate_matrix(void *arr, int row, int col) {
    int (*mat)[row] = (int (*)[])arr;

    for(int x = 0; x < col; x++) {
        for(int y = 0; y < row; y++) {
            printf("%d ", mat[x][y]);
        }
        printf("\n");
    }
    printf("\n");

    int save;
    for(int x = 0; x < row / 2; x++) {
        for(int y = 0; y < col / 2; y++) {
            save = mat[x][y];
            mat[x][y]                       = mat[y][col - x - 1];
            mat[y][col - x - 1]             = mat[col - x - 1][row - y - 1];
            mat[col - x - 1][row - y - 1]   = mat[row - y - 1][x];
            mat[row - y - 1][x] = save;
        }
    }
    for(int x = 0; x < col; x++) {
        for(int y = 0; y < row; y++) {
            printf("%d ", mat[x][y]);
        }
        printf("\n");
    }
}
#endif
void rotate(int mat[][3], int row, int col) {
    int x, y;
    int save;

    for(x = 0; x < row / 2; x++) {
        for(y = x; y < col - x - 1; y++) {
            save                            = mat[x][y];
            mat[x][y]                       = mat[y][row - x - 1];
            mat[y][row - x - 1]            = mat[row - x - 1][col - y - 1];
            mat[row - x - 1][col - y - 1] = mat[col - y - 1][x];
            mat[col - y - 1][x]            = save;
        }
    }

    for(x = 0; x < row; x++) {
        for(y = 0; y < col; y++) {
            printf("%d ", mat[x][y]);
        }
        printf("\n");
    }
}



void hanoi(int num, int start, int buf, int end) {
    
}


void permutation(char *s, int pos) {
    int len = strlen(s);
    if(pos >= len)  printf("%s\n", s);
    for(int i = pos; i < len; i++) {
        swap(&s[i], &s[pos]);
        permutation(s, pos + 1);
        swap(&s[i], &s[pos]);
    }
}


int main(void) {
    /*
    int **mat = (int **)malloc(3 * sizeof(int *));
    for(int i = 0; i < 3; i++) {
        mat[i] = (int *)malloc(5 * sizeof(int));
    }

    int **visited = (int **)malloc(3 * sizeof(int *));
    for(int i = 0; i < 3; i++) {
        visited[i] = (int *)malloc(5 * sizeof(int));
    }

    int arr[5][3] = {{0, 1, 2},
                    {3, 4, 5},
                    {6, 7, 8},
                    {9, 10, 11},
                    {12, 13, 14}};
*/

    int arr[][3] = {{0, 1, 2},
                    {3, 4, 5},
                    {6, 7, 8}};

    //rotate_matrix(arr, 3, 3);
    char s[3] = "abc";
    permutation(s, 0);

    //printf("%s\n", s);

    return 0;
}