#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>
#include <limits.h>
#include <math.h>

int mystrstr(char *haystack, char *needle) {
    int size1 = strlen(haystack);
    int size2 = strlen(needle);
    int i, j;

    for(i = 0; i < size1 - size2; i++) {
        for(j = 0; j < size2; j++) {
            if(haystack[i + j] != needle[j]) {
                break;
            }
        }
        if(j == size2) {
            return i;
        }
    }
    
    return -1;
}

//[4] first non-repeat char
int first_non_repeat2(char *s) {
    int size = strlen(s);
    int hash[256] = {0};
    int i;

    for(i = 0; i < size; i++) {
        if(hash[s[i]]) {
            return i;
        }
        hash[s[i]] = i;
    }
    return -1;
}


#if 0
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
#endif

//[8] shortest
int shortest_consective_arr_dp(int *res, int size, int key) {
    int left = 0, right = 0;
    int len, len_min = INT_MAX;
    int sum = 0;

    for(right = 0; right < size; right++) {
        sum += res[right];
        while(left <= right && sum >= key) {
            len = right - left + 1;
            len_min = len < len_min ? len : len_min;
            sum -= res[left++];
        }
    }
    printf("%d\n", len_min);
    return len_min;
}

    
//7 shortest consective sum of elements >= key  brute force
#if 0
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
#endif

int shortest_consective_arr_bruteforce2(int *res, int size, int key) {
    //for loop [i:second element, i:end]
    int left, right;
    int sum = 0;
    int x;
    int len = 0;
    int len_min = 1000;

    for(right = 0; right < size; right++) {
        //for loop [j:i-1, j:0]
        for(left = right; left >= 0; left--) {
            //if sum[i, j] >= key
            sum = 0;
            for(x = left; x <= right; x++) {
                sum += res[x];
            }
            //calculate len, if len < min, min = len
            if(sum >= key) {
                len = right - left + 1;
                if(len < len_min) {
                    len_min = len;
                }
                break;
            }
        }
    }
    printf("%d\n", len_min);

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

int longest_uniq_sub(char *s) {
    return 0;
}

int isSub(char *s, char *sub) {
    char *p_s = s;
    char *p_sub = sub;
    for(p_s = s; *p_s != '\0'; p_s++) {
        char *tmp = p_s;
        for(p_sub = sub; *p_sub != '\0'; p_sub++, tmp++) {
            if(*p_sub != *tmp) {
                break;
            }
        }
        if(*p_sub == '\0') {
            return 1;
        }
    }
    return 0;
}

int longest_common_sub_bruteForce(char *s1, char *s2) {
    int size1 = strlen(s1);
    int size2 = strlen(s2);
    int left, right;
    int ret = -1;
    char sub[100] = {0};
    char tmp[100] = {0};
    int len = 0;
    int len_max = 0;
    
    //for loop s1
    for(left = 0; left < size1; left++) {
        for(right = left; right < size1; right++) {
            len = right - left + 1;
            strncpy(tmp, s1 + left, len);
            ret = isSub(s2, tmp);
            if(ret) {
                len_max = len > len_max ? len : len_max;
                strcpy(sub, tmp);
            }
        }
    }
    printf("%s\n", sub);

    return 0;
}

int longest_common_sub_dp(char *s1, char *s2) {
    int size1 = strlen(s1);
    int size2 = strlen(s2);
    int i, j;
    int val = 0, max = 0;
    char res[100] = {0};

    int dp[size1][size2];
    for(i = 0; i < size1; i++) {
        for(j = 0; j < size2; j++) {
            if((i == 0 || j == 0) && s1[i] == s2[j]) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }

    for(i = 1; i < size1; i++) {
        for(j = 1; j < size2; j++) {
            if(s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
    }

    for(i = 1; i < size1; i++) {
        for(j = 1; j < size2; j++) {
            if(dp[i][j] > max) {
                max = dp[i][j];
                strncpy(res, s1 + i - max + 1, max);
            }
        }
    }

    printf("%d, %s\n", max, res);

    return max;
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

//[5] remove specific element
void rm_element(int *res, int size, int key) {
    int left = 0, right = 0;
    for(right = 0; right < size; right++) {
        if(res[right] != key) {
            res[left++] = res[right];
        }
    }

    for(int i = 0; i < left; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
}


int isSub(char *s, char *sub) {
    int i, j;
    int size_s = strlen(s);
    int size_sub = strlen(sub);
    for(i = 0; i < size_s; i++) {
        for(j = 0; j < size_sub; j++) {
            if(*(s + i + j) != *(sub + j)) {
                break;
            }
        }
    }
    if(j == size_sub) {
        return 1;
    }
    return 0;
}

int isSub2(char *s, char *sub) {
    char *ps, *psub;
    for(ps = s; *ps; ps++) {
        char *tmp = ps;
        for(psub = sub; *psub; psub++) {
            if(*tmp++ != *psub) {
                break;
            }
        }
    }
    if(*psub == '\0') {
        return 1;
    }
    return 0;
}

//abcba -> c
int is_repeat(char *s) {
    int hash[256] = {0};
    char *p;
    for(p = s; *p; p++) {
        hash[*p]++;
    }

    for(p = s; *p; p++) {
        if(hash[*p] == 1) {
            return *p;
        }
    }
    printf("there is no non-repeat character!\n");
    return -1;
}

/*
    - 04. first non-repeat char
*/
int firs_non_repeat(char *s) {
    if(!s) {
        return -1;
    }
    int hash[256] = {0};
    int size = strlen(s);
    for(int i = 0; i < size; i++) {
        if(hash[s[i]]) {
            return i;
        }
        hash[s[i]]++;
    }
    return -2;
}


void common_sub_str(char *s1, char *s2, int size1, int size2) {
    //int size1 = strlen(s1);
    //int size2 = strlen(s2);
    int dp[size1][size2];

    for(int i = 0; i < size1; i++) {
        for(int j = 0; j < size2; j++) {
            dp[i][j] = 0;
            if((i == 0 || j == 0) && (s1[i] == s2[j])) {
                dp[i][j] = 1;
            }
        }
    }
#if 1
    for(int i = 1; i < size1; i++) {
        for(int j = 1; j < size2; j++) {
            if(s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
    }
#endif

    for(int i = 0; i < size1; i++) {
        for(int j = 0; j < size2; j++) {
            printf("%d\t", dp[i][j]);
        }
        printf("\n");
    }

    int max = 0;
    int pos = -1;
    char s_return[size1];
    //find the largest dp
    for(int i = 0; i < size1; i++) {
        for(int j = 0; j < size2; j++) {
            if(dp[i][j] > max){
                max = dp[i][j];
                pos = i;
                strncpy(s_return, s1 + pos - 1, max);
            }
        }
    }
    printf("%d, %s\n", max, s_return);
}

void common_sub_subsequnce(char *s1, char *s2, int size1, int size2) {
    int dp[size1][size2];

    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++) {
            dp[i][j] = 0;
            if((i == 0 || j == 0) && (s1[i] == s2[j])) {
                dp[i][j] = 1;
            }
            if(i == 0 && j > 0 && dp[i][j - 1] == 1) {
                dp[i][j] = 1;
            }
            if(j == 0 && i > 0 && dp[i - 1][j] == 1) {
                dp[i][j] = 1;
            }
        }
    }

    for(int i = 1; i < size1; i++) {
        for(int j = 1; j < size2; j++) {
            if(s1[i] == s2[j]) {
                dp[i][j]= dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    for(int i = 1; i < size1; i++) {
        for(int j = 1; j < size2; j++) {
            printf("%d\t", dp[i][j]);
        }
        printf("\n");
    }
}

void longest_uniq_substr(char *s, int size) {
    int pos = -1;
    int hash[size];
    int len = 0;
    int longest = 0;
    for(int i = 0; i < size; i++) {
        hash[s[i]] = -1;
    }

    for(int i = 0; i < size; i++) {
        pos = pos > hash[s[i]] ? pos : hash[s[i]];
        len = i - pos;
        longest = len > longest ? len : longest;
        hash[s[i]] = i;
    }

    printf("%d\n", longest);
}

//[10] merge 2 arrays
void merge_2_arrays(int *res1, int size1, int *res2, int size2, int *resNew) {
    //merge res1 and res2 to newres
    int i = 0, j = 0;   //for res1 and res2 index
    int k = 0;  //for resNew index

    while(i < size1 || j < size2) {
        if(i == size1) {
            resNew[k++] = res2[j++];
            continue;
        }
        if(j == size1) {
            resNew[k++] = res2[i++];
            continue;
        }
        if(res1[i] <= res2[j]) {
            resNew[k++] = res1[i++];
        }
        if(res1[i] > res2[j]) {
            resNew[k++] = res2[j++];
        }
    }

    for(i = 0; i < k; i++) {
        printf("%d ", resNew[i]);
    }
    printf("\n");
}

/*
a       e
b   d   f   h
c       g

->aebdfhcg
*/
//TODO [09]
void z_transform(char *s, int n) {
    int x = 0, y = 0;
    int count = 0;
    int size = strlen(s);
    int row = n;
    int col = 2 * size / (n + n - 2);
    int arr[row][col];

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            arr[i][j] = '\0';
        }
    }

    while(count < size) {
        for(int i = 0; i < n; i++) {
            printf("%d, %d\n", x, y);
            arr[x++][y] = s[count++];
        }
        x -= 2;
        ++y;
        

        for(int i = 0; i < n - 2; i++) {
            printf("%d, %d\n", x, y);
            arr[x--][y++] = s[count++];
        }
    }

    for(x = 0; x < row; x++) {
        for(y = 0; y < col; y++) {
            printf("%c ", arr[x][y]);
        }
        printf("\n");
    }
}