#include "common.h"
#include "test.h"


/*
*/
int bin_add(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int sum = 0;
    int sizeOutput = (len1 > len2 ? len1 : len2) + 1;
    char *output = (char *)malloc(sizeOutput + 1);

    while(len1 > 0 || len2 > 0 || sizeOutput > 0) {
        if(len1 > 0 ) {
            sum += s1[--len1] - '0';
        }
        if(len2 > 0) {
            sum += s2[--len2] - '0';
        }
        output[--sizeOutput] = sum % 2 + '0';
        sum /= 2;
    }
    return output + sizeOutput;
}


/*
    0 0 1
    0 1 0
    0 1 0
*/
int find_path(int **mat, int x, int y, int posx, int posy) {
    if(mat == NULL) return false;
    if(posx < 0 || posx >= x)   return false;
    if(posy < 0 || posy >= y)   return false;

    if(mat[posx][posy] == 0) {
        if(posx == x && posy == y){
            mat[posx][posy] = 1;
            return 1;
        }
        if((posx >= 0) && (posx < x) && (posy > 0) && (posy < y - 1)) {
            find_path(mat, );
        }
    } 
    if(mat[posx][posy] == 1)  return false;

    if(mat[posx][posy] == 0){
        find_path(mat, x, y, posx + 1, posy);
    }
}


/*  [123] - merge intervals
    [1, 8] [2, 9]   -> [1, 9]
    [1, 8] [9, 17]  -> [1, 8] [9, 17]
    1. sortint: 
        1). by first element
        2). if first elements are equal. then by send elements
    2. travel from second paire. L and R point to first and second
    3. the core concept: how to get L and R?
        1). L and R are set to the first pair array
        2). the conditions of updating L and R?
*/
int merge_intervals(int **nums, int row, int col) {
    int **res = (int **)malloc(row * sizeof(int *));
    for(int i = 0; i < col; i++) {
        res[i] = (int *)malloc(col * sizeof(int));
    }

    int L = nums[0][0];
    int R = nums[0][1];
    int idx = 0;

    for(int i = 1; i < row; i++) {
        if(nums[i][0] <= R && nums[i][1] >= R) {
            R = nums[i][1];
        } else if(nums[i][0] > R) {
            res[idx][0] = L;
            res[idx][1] = R;
            L = res[idx][0];
            R = res[idx][1];
            idx++;
        }
    }
    res[idx][0] = L;
    res[idx][1] = R;
    return res;
}


int main(void) {
    char s[] = "abc";
    string_reverse(s);
    printf("%s\n", s);

    return 0;
}