#include "common.h"
#include "test.h"


//TODO
int dfs(int **mat, int x, int y, int **visited) {

}


int dfs_matrix(int **mat, int x, int y, int **visited) {
    if(x < 0 || x >= m || y < 0 || y >= n || mat[x][y] == 1 )
    dfs(mat, x - 1, y, visited);
}


int main(void) {
    int **mat = (int **)malloc(3 * sizeof(int *));
    for(int i = 0; i < 3; i++) {
        mat[i] = (int *)malloc(5 * sizeof(int));
    }

    int **visited = (int **)malloc(3 * sizeof(int *));
    for(int i = 0; i < 3; i++) {
        visited[i] = (int *)malloc(5 * sizeof(int));
    }

    dfs_matrix(mat, 3, 5, visited);
    //printf("%s\n", s);

    return 0;
}