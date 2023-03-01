#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int index;
    int rep;
} Node, *pNode;

#define SIZE sizeof(Node)


//[01]
void test(int **nums, int row, int col) {
    int count = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++) {
            nums[i][j] =  count++;
        }
    }
}

void myprintt(int **nums, int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", nums[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int row = 4;
    int col = 3;

    int **nums = (int **)malloc(sizeof(int *) * row);
    for(int i = 0; i < 4; i++) {
        nums[i] = (int *)malloc(sizeof(int *) * col);
    }

    //{{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 10, 11}};
    test(nums, 4, 3);
    myprintt(nums, 4, 3);

    return 0;
}

//=================================================================

/*
    rotate 1/4 part of matrix
*/
void rotate(int mat[][4], int size) {
    int x, y;
    int save;

    for(x = 0; x < size / 2; x++) {
        for(y = 0; y < size / 2; y++) {
            save                            = mat[x][y];
            mat[x][y]                       = mat[y][size - x - 1];
            mat[y][size - x - 1]            = mat[size - x - 1][size - y - 1];
            mat[size - x - 1][size - y - 1] = mat[size - y - 1][x];
            mat[size - y - 1][x]            = save;
        }
    }

    for(x = 0; x < size; x++) {
        for(y = 0; y < size; y++) {
            printf("%d ", mat[x][y]);
        }
        printf("\n");
    }
}


/*
    rotate by layers
    设四个位置中，位于左上角区域的位置坐标为 (i,j)，
    则按顺时针顺序，四个位置分别为(i,j), (j, n-i-1), (n-i-1,n-j-1), (n-j-1,i)。
    其中 n 为 matrix.size(), i, j 分别为matrix的行列下标，从 0 开始。
*/
void matrix_test1(int matrix[5][5], int size) {
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
void rotateMatrix(int mat[][N]) {
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


void insert_arr(int *arr, int size, int pos, int val_ins) {
    int i;
    int save;

    for(i = pos; i <= size; i++) {
        save = arr[i];
        arr[i] = val_ins;
        val_ins = save;
    }
    for(i = 0; i <= size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void move_arr(int *arr, int size, int pos) {
    int i;
    int val_ins = arr[pos];
    int save = arr[pos];

    for(i = pos; i <= size; i++) {
        save = arr[i];
        arr[i] = val_ins;
        val_ins = save;
    }
    for(i = 0; i <= size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//[6] sorting the square of an array sorted elements,
void sort_square(int *arr, int size) {
    //find the negtive and positive num

    int left, right;
    int result[size];
    int pos = size - 1;

    for(left = 0, right = size - 1; left <= right; ) {
        if(arr[left] * arr[left] > arr[right] * arr[right]) {
            result[pos] = arr[left] * arr[left];
            --pos, ++left;
        } else {
            result[pos] = arr[right] * arr[right];
            --pos, --right;
        }
    }

    for(left = 0; left < size; left++) {
        printf("%d ", result[left]);
    }
    printf("\n");
}


//[09]
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

//[10]
int shortest_consective_slideWindow(int *arr, int size, int key) {
    int left = 0, right;
    int len = 0, len_min = INT_MAX;
    int sum = 0;

    for(right = 0; right < size; right++) {
        sum += arr[right];
        while(sum >= key) {
            len = right - left + 1; 
            len_min = len < len_min ? len : len_min;
            sum -= arr[++];
        }
    }

    return len_min == INT_MAX ? -1 : len_min;
}


/* [12]
  Given an array containing n integers.
  The problem is to find the sum of the elements of the contiguous subarray
   having the smallest(minimum) sum
  */
// function to find the smallest sum contiguous subarray
int smallestSumSubarr(int arr[], int n) {
    // to store the minimum value that is ending
    // up to the current index
    int min = INT_MAX;
     
    // to store the minimum value encountered so far
    int sum = INT_MAX;
     
    // traverse the array elements
    for (int i=0; i<n; i++) {
        // if sum > 0, then it could not possibly
        // contribute to the minimum sum further
        if (sum > 0)
            sum = arr[i];
         
        // else add the value arr[i] to min   
        else
            sum += arr[i];
         
        // update min_so_far
        min = sum < min ? sum : min;
    }
     
    // required smallest sum contiguous subarray value
    return min_so_far;
}


//[13] - 1 remove duplicated elements
//
void rm_dup_elements(char *str) {
    int hash[256] = {0};
    int size = strlen(str);
    int slow, fast;

    for(fast = 0, slow = 0; fast < size; ) {
        if(hash[str[fast]]++ == 0) {
            str[slow] = str[fast];
            ++slow, ++fast;
        } else {
            ++fast;
        }
    }
    str[slow] = '\0';
    printf("%s\n", str);
}


void rm_dup_elements_integer(int *arr, int size) {
    int hash[1000] = {0};
    int slow, fast;

    for(slow = 0, fast = 0; fast < size; ) {
        if(hash[arr[fast]]++ == 0) {
            arr[slow] = arr[fast];
            ++slow, ++fast;
        } else {
            ++fast;
        }
    }
    for(int i = 0; i < slow; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


//[13] - double pointers
int rm_dup(int arr[], int size, int target) {
    int fast = 0, slow = 0;
    for(fast = 0; fast < size; ) {
        if(arr[fast] == target) {
            fast++;
        } else {
            arr[slow++] = arr[fast++];
        }
    }
    return slow;
}

void rm_dup(int arr[], int size) {
    int pos;
    int newSize;
    for(pos = 1; pos < size; pos++) {
        newSize = pos + rm_dup(arr + pos, size - pos, arr[pos - 1]);
        size = newSize;
    }
}


//[7]
void spiral_matrix(int n) {
    int res[n][n];
    int startx = 0, starty = 0;
    int loop = n / 2;   //the loop times, if odd, then need to set the last element
    int count = 1;
    int x, y;
    int offset = 1; //set boundary
    int mid = n / 2;

    while(loop--) {
        x = startx;
        y = starty;
        //up [left, right)
        for(y = starty; y < n - offset; y++) {
            res[startx][y] = count++;
        }
        //right [up, down)
        for(x = startx; x < n - offset; x++) {
            res[x][y] = count++;
        }
        //bottom [right, left)
        for(; y > starty; y--) {
            res[x][y] = count++;
        }
        //left [down, up)
        for(; x > startx; x--) {
            res[x][y] = count++;
        }
        startx++;
        starty++;
        offset++;
    }
    if(n % 2) {
        res[mid][mid] = count;
    }

    for(x = 0; x < n; x++) {
        for(y = 0; y < n; y++) {
            printf("%d ", res[x][y]);
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


//[16]
unsigned int reverse_interger(unsigned int num) {
    if(num < 10) {
        return num;
    }

    int sum = 0;
    int remainder = 0;

    while(num) {
        remainder = num % 10;
        num /= 10;
        sum = sum * 10 + remainder;
    }

    return sum;
}



void move(char x, char y) {
    printf("%c --> %c\n", x, y);
}
//move n plates, from one to three, by using two as a buffer
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


void romanToInt() {
    char s[] = "MDC";
    int t['X' + 1] = {
        ['I'] = 1,
        ['V'] = 5,
        ['X'] = 10,
        ['L'] = 50,
        ['C'] = 100,
        ['D'] = 500,
        ['M'] = 1000,
    };
    int res = 0;
    for (int i = 0; s[i]; i++) {
        if (t[s[i]] < t[s[i+1]])
            res -= t[s[i]];
        else
            res += t[s[i]];
    }
    printf("%d\n", res);
}


int main(void) {
    int mat[][4] = {{1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 11, 12},
                    {13, 14, 15, 16}};

    rotate(mat, 4);

    char str[] = "abacaabn";
    rm_dup_elements(str);   

    int arr[] = {1, 7, 9, 1, 8, 1, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    rm_dup_elements_integer(arr, size); 

    int arr2[] = {3, -4, 2, -3, -1, 7, -5};
    smallestSumSubarr(arr2, sizeof(arr) / sizeof(arr[0]));

    return 0;
}