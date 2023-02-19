#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>


int partition(int *nums, int L, int R) {
    int save = nums[L];
    while(L < R) {
        while(L < R && nums[R] >= save) {
            R--;
        }
        if(L < R){
            nums[L++] = nums[R];
        }
        while(L < R && nums[L] <= save) {
            L++;
        }
        if(L < R) {
            nums[R--] = nums[L];
        }
    }
    nums[L] = save;
    return L;
}

void quick_sort(int *nums, int L, int R) {
    if(L >= R) {
        return;
    }
    int mid = partition(nums, L, R);    //return mid, split the numbers
    quick_sort(nums, L, mid - 1);
    quick_sort(nums, mid + 1, R);

}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    int base_alloc_size = 16;
    int **res = (int **)malloc(sizeof(int *) * base_alloc_size);
    int L, R, i;
    int sum = 0;

    quick_sort(nums, 0, numsSize - 1);
    for(i = 0; i < numsSize - 2; i++) {
        L = i + 1;
        R = numsSize - 1;
        //
        if(nums[i] > 0) {
            break;
        }
        if(i > 0 && nums[i - 1] == nums[i]) {
            continue;
        }
        while(L < R) {
            sum = nums[i] + nums[L] + nums[R];
            if(sum > 0) {
                R--;
            } else if(sum < 0) {
                L++;
            } else {
                res[*returnSize] = (int *)calloc(3, sizeof(int));
                res[*returnSize][0] = nums[i];
                res[*returnSize][1] = nums[L];
                res[*returnSize][2] = nums[R];

                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                while(L < R && nums[L] == nums[L + 1]) {
                    L++;
                }
                while(L < R && nums[R] == nums[R - 1]) {
                    R--;
                }
                L++, R--;
            }

            if(*returnSize == base_alloc_size) {
                base_alloc_size = base_alloc_size * 2;
                res = (int **)realloc(res, base_alloc_size * sizeof(int *));
                (*returnColumnSizes) = (int *)realloc((*returnColumnSizes), base_alloc_size * sizeof(int));
            }
        }
    }
    return res;
} 

int main() {
    int nums[] = {-21, -21, -34, 98, 0, 65, 5};
    int size = sizeof(nums) / sizeof(nums[0]);
    int returnSize[] = 
    threeSum(nums, size, );
    return 0;
}