
#include <stdio.h> 
#include <pthread.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


/*
	if arr was defined as a 2d array, then this way works!!!
*/
void showme(void *p, int row, int col) {
    int (*pArr)[col] = p;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", pArr[i][j]);
        }
        printf("\n");
    }
}


/*
	1. if arr was defined as a 2d pointer, then here can use "int **arr" to receive, 
	and using "arr[i][j]" to print.
	2. if arr was defined as a 2d array, then this way here will fail.
*/
void showme_2(int **arr, int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
    }
}


int main() {
    int m = 5;
    int n = 5;
 
    // dynamically create an array of pointers of size `m`
    int **arr = (int **)malloc(m * sizeof(int *));
 
    // dynamically allocate memory of size `n` for each row
    for (int r = 0; r < m; r++) {
        arr[r] = (int *)calloc(n, sizeof(int));
    }
    showme_2(arr, 5, 5);

    return 0;
}