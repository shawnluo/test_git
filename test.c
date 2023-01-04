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

void spiral_matrix_2(const int n) {
    int startx = 0, starty = 0;
    int mid = n / 2;
    int loop = n / 2;
    int count = 1;
    int offset = 1;
    int res[n][n];
    int i = startx, j = starty;
    while(loop--) {
        i = startx;
        j = starty;

        //up [left, right)
        for(; j < n - offset; j++) {
            res[startx][j] = count++;
        }
        //right [up, down)
        for(; i < n - offset; i++) {
            res[i][j] = count++;
        }
        //bottom [right, left)
        for(; j > starty; j--) {
            res[i][j] = count++;
        }
        //left [bottom, up)
        for(; i > startx; i--) {
            res[i][j] = count++;
        }
        startx++, starty++;
        offset++;
    }

    if(n % 2)   res[mid][mid] = count;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d\t", res[i][j]);
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

//[6] sorting the square of an array elements
void sort_square(int *res, int size) {

}

void insert_arr_1(int *res, int size, int pos, int key) {
    int i;
    for(i = size - 1; i >= pos; i--) {
        res[i + 1] = res[i];
    }
    res[i + 1] = key;
    for(i = 0; i <= size; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
}

//[12] rotate matrix new array
void rotate_matrix_newArray(int *res, int row, int col) {
    int x = row;
    int y = col;
    int (*arr)[y] = res;
    int i, j;
    
//    for() {
//        res[x][y] = res[y][];
//    }
}


/*
    设四个位置中，位于左上角区域的位置坐标为 (i,j)，
    则按顺时针顺序，四个位置分别为(i,j), (j, n-i-1), (n-i-1,n-j-1), (n-j-1,i)。
    其中 n 为 matrix.size(), i, j 分别为matrix的行列下标，从 0 开始。
*/

//matrix exercise
//1. right -> up
void matrix_test1(int matrix[5][5], int size) {
/*
    p[0][0] = p[0][4];
    p[0][1] = p[1][4];
    p[0][2] = p[2][4];
    p[0][3] = p[3][4];
    p[0][4] = p[4][4];

    //a + b + 1 = n ==> a = n - b - 1
    p[x][y] = p[y][size - x - 1];
    p[1][0] = p[0][3];
    p[1][1] = p[1][3];
    p[1][2] = p[2][3];
*/

    for(int layer = 0; layer < size / 2; layer++) {
        int first = layer;
        int last = size - 1 -layer;
        for(int i = first; i < last; i++) {
            int offset = i - first;
            int top = matrix[first][i]; //save top

            //left -> top
            matrix[first][i] = matrix[last - offset][first];

            //bottom -> left
            matrix[last - offset][first] = matrix[last][last - offset];

            //right -> bottom
            matrix[last][last - offset] = matrix[i][last];

            //top -> right
            matrix[i][last] = top;
        }
    }
}


#define N 5
// An Inplace function to
// rotate a N x N matrix
// by 90 degrees in
// anti-clockwise direction
void rotateMatrix(int mat[][N])
{
    // Consider all squares one by one
    for (int x = 0; x < N / 2; x++) {
        // Consider elements in group
        // of 4 in current square
        for (int y = x; y < N - x - 1; y++) {
            // Store current cell in
            // temp variable
            int temp = mat[x][y];
 
            // Move values from right to top
            mat[x][y] = mat[y][N - 1 - x];
 
            // Move values from bottom to right
            mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y];
 
            // Move values from left to bottom
            mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x];
 
            // Assign temp to left
            mat[N - 1 - y][x] = temp;
        }
    }
}

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

    int p_x[] = {1, 6, 76, 165, 235};
    int p_y[] = {-1, 2, 8, 98, 500};
    int size1 = sizeof(p_x) / sizeof(p_x[0]);
    int size2 = sizeof(p_y) / sizeof(p_y[0]);

    int resNew[100] = {0};
    //shortest_consective_arr_dp(p_x, 5, 6);
    //shortest_consective_arr_bruteforce(p_x, 5, 10);
    //shortest_consective_arr_dp(p_x, 5, 5);
    //spiral_matrix(3);
    //spiral_matrix_2(4);

    char *s = "kk1234567fdshowme";
    char *sub = "xdfdshowdow1234567rm";
    //int ret = isSub(s, sub);
    //printf("%d\n", ret);
    //longest_common_sub_bruteForce(s, sub);
    //longest_common_sub_dp(s, sub);

    //rm_element(p_x, 5, 3);
    //merge_2_arrays(p_x, size1, p_y, size2, resNew);
    
    insert_arr_1(p_x, size1, 5, 2000);
    matrix_test1(arr, 5);

    return 0;
}