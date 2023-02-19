#include "common.h"
#include "test.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int inc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    int i;
    if (nums == NULL || numsSize < 3)
        return NULL;

    qsort(nums, numsSize, sizeof(int), inc);
    *returnColumnSizes = (int *)malloc(sizeof(int) * numsSize * numsSize);
    int **han = (int **)malloc(sizeof(int *) * numsSize * numsSize);
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] > 0)
            break;
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int L = i + 1, R = numsSize - 1;
        while (L < R)
        {
            int sum = nums[i] + nums[L] + nums[R];
            int n, m;
            if (sum == 0)
            {
                han[*returnSize] = (int *)malloc(sizeof(int) * 3);
                han[*returnSize][0] = nums[i];
                han[*returnSize][1] = nums[L];
                han[*returnSize][2] = nums[R];
                (*returnColumnSizes)[*returnSize] = 3;
                *returnSize += 1;
                //(*returnSize)++;

                /*非常不规范的写法，但是极其舒适！
                while(L < R && nums[L] == nums[++L]);
                while(L < R && nums[R] == nums[--R]);
                */
                do
                {
                    n = L++;
                } while (n < R && nums[L] == nums[n]);
                do
                {
                    m = R--;
                } while (L < m && nums[R] == nums[m]);
            }
            else if (sum < 0)
                L++;
            else if (sum > 0)
                R--;
        }
    }
    return han;
}