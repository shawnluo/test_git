#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>
#include <limits.h>
#include <math.h>


int max(int x, int y) {
    return x > y ? x : y;
}

int integer_break(int n) {
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;

    memset(dp, 0, sizeof(int) * (n + 1));

    int i, j;
    for(i = 3; i <= n; i++) {
        for(j = 1; j <= i / 2; j++) {
            dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
        }
    }
    printf("%d\n", dp[n]);
    return dp[n];
}

int longest_common_subsequence(char *arr1, char *arr2) {
    int m = strlen(arr1);
    int n = strlen(arr2);
    int dp[m + 1][n + 1];
    int i, j;
    for(i = 0; i <= m; i++) {
        for(j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    for(i = 1; i <= m; i++) {
        for(j = 1; j <= n; j++) {
            if(arr1[i - 1] == arr2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    for(i = 0; i <= m; i++) {
        for(j = 0; j <= n; j++) {
            printf("%d\t", dp[i][j]);
        }
        printf("\n");
    }
    
    return dp[m][n];
}


int shortest_consective_bf(int *arr, int size, int key) {
    int len = 0, len_min = INT_MAX;
    int left, right;
    int sum = 0;
    for(left = 0; left < size; left++) {
        sum = 0;
        for(right = left; right < size; right++) {
            sum += arr[right];
            if(sum >= key) {
                len = right - left + 1;
                len_min = len < len_min ? len : len_min;
                break;
            }
        }
    }

    return len_min;
}

int shortest_consective_slideWindow(int *arr, int size, int key) {
    int left = 0, right;
    int len = 0, len_min = INT_MAX;
    int sum = 0;

    for(right = 0; right < size; right++) {
        sum += arr[right];
        while(sum >= key) {
            len = right - left + 1; 
            len_min = len < len_min ? len : len_min;
            sum -= arr[left];
        }
    }
    return len_min;
}

int ins_key(int *arr, int size, int pos, int key) {
    int save;
    for(int i = pos; i <= size; i++) {
        save = arr[pos];
        arr[pos] = key;
        key = save;
    }
    return 0;
}

int move_backwards(int *arr, int size, int pos) {
    int save;
    int last = arr[pos];
    for(int i = pos + 1; i <= size; i++) {
        save = arr[i];
        arr[i] = last;
        last = save;
    }

    return 0;
}

void merge_arrays(int *arr1, int size1, int *arr2, int size2) {
    int i = size1 - 1, j = size2 - 1;
    int count = size1 + size2;
    while(i >= 0 || j >= 0) {
        if(i < 0) {
            arr1[count] = arr2[j];
            i--, count--;
            continue;
        }
        if(j < 0) {
            arr1[count] = arr1[j];
            j--, count--;
            continue;
        }
        if(arr1[i] >= arr2[j]) {
            arr1[count] = arr1[i];
            i--;
        } else {
            arr1[count] = arr2[j];
            j--;
        }
        count--;
    }
}

void spiral_mat(int n) {
    int rep = n / 2;
    int startx = 0, starty = 0;
    int arr[n][n];
    int x, y;
    int index = 0;
    int count = 0;

    while(rep--) {
        for(y = 0; y < n - index; y++) {
            arr[index][y] = count++;
        }
        for(x = 0; x < n - index; x++) {
            arr[x][y] = count++;
        }
        for(; y > starty; y--) {
            arr[x][y] = count++;
        }
        for(; x > startx; x--) {
            arr[x][y] = count++;
        }
    }
    if(n % 2 == 1) {
        arr[n % 2][n % 2] = count;
    }
}


void rotate(int arr[5][5]) {
    /*
        arr[x][y]       
        arr[y][n - x - 1]
        arr[n - x - 1][n - y - 1]
        arr[n - y - 1][x]
    */
}



int main(void) {
    //int cost[5] = {6, 4, 7, 2, 1};
    //ladder_energy(5, cost);
    //integer_break(10);
    
    char arr1[] = "abcxd";
    char arr2[] = "xabcrpd";
    longest_common_subsequence(arr1, arr2);
    
    return 0;
}