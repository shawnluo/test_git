#include "common.h"
#include "test.h"


/*  0 1 1 2 3 5
    i       : 
    dp[i]   : fib of i
*/
void fib(int num) {
    int dp[num];
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 0; i < num; i++) {
        dp[i] =  dp[i - 1] + dp[i - 2];
    }
}

void ladder(int num) {
    int dp[num + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= num; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

void ladder_with_cost(int num) {

}


int removeDuplicates_wrong(int *nums, int numsSize) {
    int slow = 0;
    int fast = 0;

    for(int i = 0; i < numsSize; i++) {
        if(nums[slow] != nums[fast]) {
            nums[++slow] = nums[fast];
        }
        fast++;
    }
    numsSize = slow + 1;

    for(int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return numsSize;
}

int removeDuplicates(int *nums, int numsSize) {
    int slow = 0;
    int fast = 1;
    int equal = 0;

    while(fast < numsSize) {
        equal = 0;
        //slow = 0;
        while(slow < fast) {
            if(nums[slow] == nums[fast]) {
                equal = 1;
                //fast++;
                break;
            }
            slow++;
        }
        if(equal == 0) {
            nums[slow - 1] = nums[fast++];
        }
    }
    for(int i = 0; i < slow; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int removeDupStr(char *s) {
    int fast, slow;
    int hash[256] = {0};
    for(slow = 0, fast = 0; fast < strlen(s); ) {
        if(hash[s[fast]]++ == 0) {
            s[slow] = s[fast];
            ++slow, ++fast;
        } else {
            ++fast;
        }
    }
}

int main(void) {
    int nums[] = {1, 1, 1, 8, 6, 0, 6 ,7};
    int size = sizeof(nums) / sizeof(nums[0]);
    int ret = removeDuplicates(nums, size);
    printf("%d\n", ret);

    return 0;
}