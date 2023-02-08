#include "common.h"
#include "test.h"


void test(int **nums, int row, int col) {
    int count = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++) {
            nums[i][j] =  count++;
        }
    }
}


void myprintt(int **nums, int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", nums[i][j]);
        }
        printf("\n");
    }
}

/*
void swap(char *x, char *y) {
    char tmp = *x;
    *x = *y;
    *y = tmp;
}
*/

#define swap(a, b) (a) = (b) - (a), (b) = (b) - (a), (a) = (b) + (a)

void permutation(char *pStr, char *pBegin) {
    assert(pStr && pBegin);

    if(*pBegin == '\0') {
        printf("%s\n", pStr);
    } else {
        for(char *pCh = pBegin; *pCh != '\0'; pCh++) {
            swap(*pBegin, *pCh);
            permutation(pStr, pBegin + 1);
            swap(*pBegin, *pCh);
        }
    }
}


int main(void) {
    int row = 4;
    int col = 3;

    //int **nums = (int **)malloc(sizeof(int *) * row);
    for(int i = 0; i < 4; i++) {
        //nums[i] = (int *)malloc(sizeof(int *) * col);
    }

    //{{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 10, 11}};
    //test(nums, 4, 3);
    //myprintt(nums, 4, 3);
    permutation("abc", "abc");

    return 0;
}