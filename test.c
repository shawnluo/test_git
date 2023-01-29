#include "common.h"
#include "test.h"

void move(char x, char y) {
    printf("%c --> %c\n", x, y);
}

<<<<<<< HEAD
char * longestPalindrome(char * s){
    if(!*s) {
        return NULL;
=======
//move n plates, from one to three, by using two as a buffer
void hanoi(int n, char one, char two, char three) {
    if (n == 1) {
        move(one, three);
    } else {
        hanoi(n - 1, one, three, two);
        move(one, three);
        hanoi(n - 1, two, one, three);
>>>>>>> 15f52cf3834fda24056e83f7abac370d41da3bfa
    }
    //reverse it
    int i, j;
    int size = strlen(s);
    char sr[size];
    sr[size] = '\0';
    char *p = s;
    char *pr = sr + size - 1;
    while(*pr = *p) {
        pr--, p++;
    }
    //printf("%s, %s\n", s, sr);

    int dp[size][size];

#if 0
    for(i = 0; i < size; i++) {
        if(s[i] == sr[0]) {
            dp[i][0] = 1;
        }
    }
    for(j = 0; j < size; j++) {
        if(s[0] == sr[j]) {
            dp[0][j] = 1;
        }
    }
#endif
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            if((i == 0 || j == 0) && s[i] == sr[j]) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }

    for(i = 1; i < size; i++) {
        for(j = 1; j < size; j++) {
            if(s[i] == sr[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }

    int pos = 0;
    int max = 0;

    //printf("%s, %s\n", s, sr);
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            if(dp[i][j] > max) {
                max = dp[i][j];
                pos = i;
            }
        }
    }
    printf("%d\n", max);
    char *res = (char *)malloc(max + 1);
    strncpy(res, s + pos - 1, max);
    printf("%s\n", res);

    return res;
}

<<<<<<< HEAD
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
=======
//https://zhuanlan.zhihu.com/p/459055987
int main(void) {
    #if 0
    int nums[] = {1, 1, 1, 8, 6, 0, 6 ,7};
    int size = sizeof(nums) / sizeof(nums[0]);
    int ret = removeDuplicates(nums, size);
    printf("%d\n", ret);
    #endif

    hanoi(5, 'A', 'B', 'C');

char * longestPalindrome(char * s){
    if(!*s) {
        return NULL;
    }
    //reverse it
    int i, j;
    int size = strlen(s);
    char sr[size];
    sr[size] = '\0';
    char *p = s;
    char *pr = sr + size - 1;
    while(*pr = *p) {
        pr--, p++;
    }
    //printf("%s, %s\n", s, sr);

    int dp[size][size];

#if 0
    for(i = 0; i < size; i++) {
        if(s[i] == sr[0]) {
            dp[i][0] = 1;
        }
    }
    for(j = 0; j < size; j++) {
        if(s[0] == sr[j]) {
            dp[0][j] = 1;
        }
>>>>>>> 15f52cf3834fda24056e83f7abac370d41da3bfa
    }
#endif
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            if((i == 0 || j == 0) && s[i] == sr[j]) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }

    for(i = 1; i < size; i++) {
        for(j = 1; j < size; j++) {
            if(s[i] == sr[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }

    int pos = 0;
    int max = 0;

    //printf("%s, %s\n", s, sr);
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            if(dp[i][j] > max) {
                max = dp[i][j];
                pos = i;
            }
        }
    }
    printf("%d\n", max);
    char *res = (char *)malloc(max + 1);
    strncpy(res, s + pos - 1, max);
    printf("%s\n", res);

    return res;
}

<<<<<<< HEAD

=======
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


>>>>>>> 15f52cf3834fda24056e83f7abac370d41da3bfa
int reverse_int(int num) {
    int n;
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


int main(void) {
    //longestPalindrome("xyxyz");
    //rotate();
    reverse_int(1234);
    return 0;
}