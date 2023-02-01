#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>


typedef struct NODE {
    int data;
    struct NODE *next;
} Node, *pNode;

#define LEN sizeof(struct NODE)




void two_num(int arr[], int size, int k) {
    int right;
    int left;
    int sum;
    for(right = 1; right < size; right++) {
        for(left = 0; left < right; left++) {
            sum = arr[left] + arr[right];
            if(sum == k) {
                printf("%d, %d\n", left, right);
                return;
            }
        }
    }
    printf("can not find it\n");
}

int tribonacci(int n){
    int x1 = 0;
    int x2 = 1;
    int x3 = 1;
    int res = 0;
    for(int i = 3; i <= n; i++) {
        res = x1 + x2 + x3;
        x1 = x2;
        x2 = x3;
        x3 = res;
    }
    printf("%d\n", res);
    //return dp[n];
    return 1;
}

int tribonacci2(int n){
    int ans[38];        // (1) 定义一个37的数组
    ans[0] = 0;         // (2) 定义前三个元素
    ans[1] = 1;
    ans[2] = 1;
    for (int i=3;i<=n;i++)
    {
        ans[i] = ans[i-1] + ans[i-2] + ans[i-3];    // (3) 将计算出的泰波那契数存进数组
    }
    printf("%d\n", ans[n]);
    return ans[n];
}

int main(void) {
    #if 0
    pNode pHead = NULL;
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    pHead = create_LL2(arr, size);
    showMe(pHead);
    #endif

    //int ret = isSub2("abcd", "axbc");
    //printf("%d\n", ret);
    //int ret = first_non_repeat2("abcdba");
    //int arr[] = {1, 2, 3, 4, 5};
    //two_num(arr, 5, 19);

    tribonacci(4);
    //tribonacci(5);
 
    return 0;
}