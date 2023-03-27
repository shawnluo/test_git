#include "common.h"
#include "test.h"


int comp(const void *x, const void *y) {
    return *(int *)y - *(int *)x;
}

void test() {
    int nums[] = {21, 8, 1, 34};
    int len = sizeof(nums) / sizeof(nums[0]);
    qsort(nums, len, sizeof(nums[0]), comp);

    for(int i = 0; i < len; i++) {
        printf("%d\n", nums[i]);
    }
}

//longest increasing subarray
int LIS(int *nums, int size) {
    int dp[size + 1];
    for(int i = 0; i <= size; i++) {
        dp[i] = 1;
    }
    int res = 0;
    for(int i = 1; i < size; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] >= nums[j]){
                dp[i] = fmax(dp[i], dp[j] + 1);
            }
        }
        res = fmax(res, dp[i]);
    }
    return res;
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
    test();
    return 0;
}