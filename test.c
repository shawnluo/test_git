#include "common.h"
#include "test.h"

void move(char x, char y) {
    printf("%c --> %c\n", x, y);
}

//move n plates, from one to three, by using two as a buffer
//TODO
void hanoi(int n, char one, char two, char three) {
    if (n == 1) {
        move(one, three);
    } else {
        hanoi(n - 1, one, three, two);
        move(one, three);
        hanoi(n - 1, two, one, three);
    }
}


void rotate() {
    int arr[][4] = {{0, 1, 2, 3},
                {4, 5, 6, 7},
                {8, 9, 10, 11},
                {12, 13, 14, 15}};

    for(int i = 0; i < 4; i++) {
        for(int j = i; j < 4; j++) {
            int save = arr[j][i];
            arr[j][i] = arr[i][j];
            arr[i][j] = save;
        }
    }

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

//TODO rotate2()
//TODO spiral_matrix()


int reverse_int(int num) {
    int remainder;
    int sum = 0;
    while(num) {
        remainder = num % 10;
        num /= 10;
        sum = sum * 10 + remainder; 
    }
    printf("%d\n", sum);
    return sum;
}


//https://zhuanlan.zhihu.com/p/459055987


int tribonacci(int n){
    //int *dp = (int *)malloc(sizeof(int) * (n + 1));
    int dp[n];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i < n; i++) {
        dp[n] = dp[n - 1] + dp[n - 2] + dp[n - 3];
    }
    printf("%d\n", dp[n]);
    //return dp[n];
    return 1;
}

int main(void) {
    //int nums[] = {1, 1, 1, 8, 6, 0, 6 ,7};
    //int size = sizeof(nums) / sizeof(nums[0]);
    //int ret = removeDuplicates(nums, size);
    //longestPalindrome("xyxyz");
    //rotate();
    //hanoi(5, 'A', 'B', 'C'); //TODO
    //reverse_int(1234);
    tribonacci(4);
    //tribonacci(5);
    //printf("%d\n", res);

    return 0;
}