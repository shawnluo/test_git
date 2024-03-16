#include "../test.hpp"

vector<vector<int>> mat = {
    {1,  2,  3,  4,  5},
    {6,  7,  8,  9,  10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
};

// 1. counter clockwise
void rotateMat_counterClockWise(vector<vector<int>>& mat) {
    int n = mat.size();

    /*
        1  2  3  4  5
        6  7  8  9  10
        11 12 13 14 15
        16 17 18 19 20
        21 22 23 24 25

        旋转4个三角形区域 - 不包括括号里的元素
        1  2  3  4  （5）
           7  8  （9）
              （13）
    */
    for(int i = 0; i < n / 2; i++) {
        for(int j = i; j < n - i - 1; j++) {  //注意起始点和终止点！！！ 最右边的点不能被
            int save = mat[i][j];
            // [l, R) - top
            mat[i][j] = mat[j][n - i - 1];
            // [U, D) - right
            mat[j][n - i - 1] = mat[n - i - 1][n - j - 1];
            // [R, L) - bottom
            mat[n - i - 1][n - j - 1] = mat[n - j - 1][i];
            // [D, U) - left
            mat[n - j - 1][i] = save;
        }
    }
}

// 2. clock wise
void rotate_clockWise(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int half = n / 2;
    
    for(int i = 0; i < half; i++) {
        for(int j = i; j < n - i - 1; j++) {
            int save = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = save;
        }
    }
}

// 3. Transpose the matrix and Swap the column
void rotate(vector<vector<int>>& matrix) {
    int row = matrix.size();
    for(int i = 0; i < row; i++) {
        for(int j = 0; j <= i;j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i = 0; i < row; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}