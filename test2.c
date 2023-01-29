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
    int arr[] = {1, 2, 3, 4, 5};
    two_num(arr, 5, 19);
    return 0;
}