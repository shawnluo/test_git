#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int index;
    int rep;
} Node, *pNode;

#define SIZE sizeof(Node)

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


//[11] remove duplicated elements
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

    return 0;
}