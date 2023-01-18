#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>
#include <limits.h>
#include <math.h>


static inline int max(int x, int y) {
    return x > y ? x : y;
}

int bin_search(int *arr, int start, int end, int key) {
    int mid;

    while(start <= end) {
        mid = (start + end) / 2;
        if(arr[mid] == key) {
            return mid;
        } else if(arr[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    if(start > end) {
        return -1;
    }
}

int shortest_consective_sum(int *arr, int size, int key) {
    int sum;
    int len, len_min = INT_MAX;
    int start = 0, end = 0;

    for(int end = 0; end < size; end++) {
        sum += arr[end];
        while(sum >= key) {
            len = end - start + 1;
            len_min = len < len_min ? len : len_min;
            sum -= arr[start];
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


int longest_common_subsequence(char *s1, char *s2) {
    int size1 = strlen(s1);
    int size2 = strlen(s2);

    int hash[size1][size2];
    for(int i = 0; i <= size1; i++) {
        for(int j = 0; j <= size2; j++) {
            if(i == 0 || j == 0) {
                hash[i][j] = 0;
            }
            if(s1[i] == s2[j]) {
                hash[i][j] = hash[i - 1][j - 1] + 1;
            }
        }
    }

    //find the biggest one

    return 0;
}


/* [12]
  Given an array containing n integers.
  The problem is to find the sum of the elements of the contiguous subarray
   having the smallest(minimum) sum
  */
// function to find the smallest sum contiguous subarray
int smallestSumSubarr(int arr[], int n) {
    int min = INT_MAX;
    int sum = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(sum > 0) {
            sum = arr[i];
        } else {
            sum += arr[i];
        }

        min = sum < min ? sum : min;
    }
    printf("%d\n", min);

    return 0;
}


void bin_print(int n) {
    
}


int main(void) {
    //int cost[5] = {6, 4, 7, 2, 1};
    //ladder_energy(5, cost);
    //integer_break(10);
    
    char s1[] = "abcxd";
    char s2[] = "xabcrpd";
    longest_common_subsequence(s1, s2);
    int arr[] = {-3, -4, 10, -3, -1, 7, -5};
    smallestSumSubarr(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}