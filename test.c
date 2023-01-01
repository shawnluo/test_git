#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>
#include <limits.h>
#include <math.h>


int bin_search(int *arr, int size, int key) {
    int left = 0;
    int right = size - 1;
    int mid;

    while(left <= right) {
        mid = (left + right) / 2;
        if(arr[mid] == key)         return mid;
        else if(arr[mid] > key)     right = mid - 1;
        else if(arr[mid] < key)     left = mid + 1;
    }
    return -1;
}

//TODO 3
int quick_sort(int *arr, int left, int right) {
    return 0;
}


//TODO 2
int mystrstr(char *haystack, char *needle) {
    return 0;
}

//8 shortest consective sum of elements >= key  DP
int shortest_consective_arr_dp(int *arr, int size, int key) {
    int left = 0;
    int right = 0;
    int len = 0;
    int sum = 0;
    int min = INT_MAX;
    for(int right = 0; right < size; right++) {
        sum += arr[right];
        while(sum >= key) {
            len = right - left + 1;
            if(len < min) min = len;
            sum -= arr[left++];
        }
    }
    printf("%d\n", min);
    return min;
}
    
//7 shortest consective sum of elements >= key  brute force
int shortest_consective_arr_bruteforce(int *arr, int size, int key) {
    int left = 0;
    int right = 0;
    int sum = 0;
    int len_min = INT_MAX;
    int len = 0;

    for(right = 0; right < size; right++) {
        //sum[right, left] are larger than key
        for(left = right; left >= 0; left--) {
            len = right - left + 1;
            for(int i = left; i <= right; i++) {
                sum += arr[i];
            }
            if(sum >= key) {
                if(len < len_min) {
                    len_min = len;
                }
            } else {
                break;
            }
        }
    }
    printf("min = %d\n", len_min);
    return len_min;
}

//pass array[][] as parameter
void showme(int *arr, int row, int col) {
    int (*p)[col] = (int (*)[col])arr;

    for(int i = 0; i < row; i++) {
        for(int j = 0;j < col; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}

//pass double pointer as parameter
void showme_2(int **arr, int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0;j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void spiral_matrix(int n) {
    int res[n][n];
    int startx = 0, starty = 0;
    int loop = n / 2;   //the loop times, if odd, then need to set the last element
    int count = 1;
    int i, j;
    int offset = 1; //set boundary
    int mid = n / 2;

    while(loop--) {
        //up [left, right)
        for(j = starty; j < n - offset; j++) {
            res[startx][j] = count++;
        }
        //right [up, down)
        for(i = startx; i < n - offset; i++) {
            res[i][j] = count++;
        }
        //bottom [right, left)
        for(; j > starty; j--) {
            res[i][j] = count++;
        }
        //left [down, up)
        for(; i > startx; i--) {
            res[i][j] = count++;
        }
        startx++;
        starty++;
        offset++;
    }
    if(n % 2) {
        res[mid][mid] = count;
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
}

#if 0
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0)); // 使用vector定义一个二维数组
        int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
        int loop = n / 2; // 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
        int mid = n / 2; // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
        int count = 1; // 用来给矩阵中每一个空格赋值
        int offset = 1; // 需要控制每一条边遍历的长度，每次循环右边界收缩一位
        int i,j;
        while (loop --) {
            i = startx;
            j = starty;

            // 下面开始的四个for就是模拟转了一圈
            // 模拟填充上行从左到右(左闭右开)
            for (j = starty; j < n - offset; j++) {
                res[startx][j] = count++;
            }
            // 模拟填充右列从上到下(左闭右开)
            for (i = startx; i < n - offset; i++) {
                res[i][j] = count++;
            }
            // 模拟填充下行从右到左(左闭右开)
            for (; j > starty; j--) {
                res[i][j] = count++;
            }
            // 模拟填充左列从下到上(左闭右开)
            for (; i > startx; i--) {
                res[i][j] = count++;
            }

            // 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
            startx++;
            starty++;

            // offset 控制每一圈里每一条边遍历的长度
            offset += 1;
        }

        // 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    }
};
#endif

int main(void) {
    int arr[5][5] = {   
                    {1, 2, 3, 4, 5},
                    {11, 22, 33, 44, 55},
                    {111, 222, 333, 444, 555},
                    {1111, 2222, 3333, 4444, 5555},
                    {11111, 22222, 33333, 44444, 55555}};

    //showme((int *)arr, 5, 5);

    int **arr_2 = (int **)malloc(5 * sizeof(int *));
    for(int i = 0; i < 5; i++) {
        arr_2[i] = (int *)malloc(5 * sizeof(int));
    }
    arr_2[0][0] = 100;
    //showme_2(arr_2, 5, 5);

#if 0
    char *s[] = {"show", "me", "the", "money", "!"};
    char *p_s[5];
    p_s[1] = s[1];
    printf("%s\n", p_s[1]);
#endif

#if 0
    int (*p_a)[5] = arr;
    printf("%d\n", p_a[0][4]);
    p_a++;
    printf("%d\n", p_a[0][4]);
#endif

    int p_x[] = {1, 2, 3, 4, 5};

    //shortest_consective_arr_dp(p_x, 5, 6);
    //shortest_consective_arr_bruteforce(p_x, 5, 6);
    spiral_matrix(3);

    return 0;
}