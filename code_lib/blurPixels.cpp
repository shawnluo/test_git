
#include "test.hpp"

// padding then blur the pix:
/* 
    5 X 5, size = 3
    1. padding 0, get 6 X 6
    2. 原始3 x 3个点，blur成一个新点。对每个点都进行blur处理。输出5 X 5
 */

int getSum(vector<vector<int>>& tmp, int x, int y, int size) {
    int res = 0;
    int index = 0;

    for(int i = x; i <= x + size; i++) {
        for(int j = y; j <= y + size; j++) {
            // cout << ++index << endl;
            res += tmp[i][j];
        }
    }
    return res;
}

void blur(vector<vector<int>>& mat, vector<vector<int>>& newMat, int size) {
    int n = mat.size();
    int half = n / 2;
    int startX = 0;
    int startY = 0;
    int offset = 1;

    int newN = n + size / 2 * 2;    // 新的padding后的矩阵长度。如果size是3，则要加上 3 / 2 * 2 = 2。如果是5，则要加上 5 / 2 * 2 = 4
    newMat.resize(n, vector<int>(n));

    // copy mat to tmp
    vector<vector<int>> tmp(newN, vector<int>(newN, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            tmp[i + size / 2][j + size / 2] = mat[i][j];
        }
    }

    // no need to padding. default value are all zeroes.
    // int count = 1;
    // half = 1;
    // while(half--) {
    //     int x = startX;
    //     int y = startY;
    //     for(; y < newN - offset; y++) tmp[x][y] = 0;
    //     for(; x < newN - offset; x++) tmp[x][y] = 0;
    //     for(; y > startY; y--) tmp[x][y] = 0;
    //     for(; x > startX; x--) tmp[x][y] = 0;

    //     startX++;
    //     startY++;
    //     offset++;
    // }

    // blur
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            newMat[i][j] = getSum(tmp, i , j, size);
        }
    }
}

int main() {
    vector<vector<int>> mat = { {1, 2, 3, 4, 5},
                                {6, 7, 8, 9, 10},
                                {11, 12, 13, 14, 15},
                                {16, 17, 18, 19, 20},
                                {21, 22, 23, 24, 25}};
    
    vector<vector<int>> newMat(mat.size(), vector<int>(mat.size(), 0));

    int size = 3;
    vector<vector<int>> core = {{1, 0, -1},
                                {-1, 0, 1},
                                {0, 1, -1}};

    blur(mat, newMat, size);

    // for_each(mat.begin(), mat.end(), [](auto x){
    //     for_each(x.begin(), x.end(), [](auto y){cout << y << " ";});
    //     cout << endl;
    // });
    return 0;
}

// 9 x 9 矩阵，被blur成 3 x 3
vector<vector<int>> getSum(vector<vector<int>>& board) {
    vector<vector<int>> mat(3, vector<int>(3, 0));

    for(int i = 0; i < 9; i ++) {
        for(int j = 0; j < 9; j++) {
            // mat[(i / 3) * 3 + j / 3] += board[i][j]; 一维表达
            mat[i / 3][j / 3] += board[i][j];
        }
    }
    return mat;
}



// 9 x 9 矩阵，被blur成 7 x 7
int getSum(const vector<vector<int>>& mat, int newX, int newY, const int m, const int n) {
    int sum = 0;
    // 4. x 和 y 分别从0 + newX的偏移开始计算新mat的成员值。
    for(int i = newX; i < newX + m; i++) {
        for(int j = newY; j < newY + n; j++) {
            if(i < mat.size() && j < mat[0].size()) {
                sum += mat[i][j];
            }
        }
    }
    return sum / (m * n);
}

vector<vector<int>> blur_odd(const vector<vector<int>>& mat, const int m, const int n) {
    int row = mat.size();
    int col = mat[0].size();

    // 1. calculate the new mat size - 算出新mat的长和宽，分别是多少个点
    if(m > row || n > col) {
        return {};
    }
    int newRow = row - m + 1;
    int newCol = col - n + 1;

    cout << newRow << " ";
    cout << newCol << endl;

    // 2. 新建一个mat来存放新mat
    vector<vector<int>> newMat(newRow, vector<int>(newCol, 0));

    // 3. 计算新mat的每个成员的值
    for(int newX = 0; newX < newRow; newX++) {
        for(int newY = 0; newY < newCol; newY++) {
            newMat[newX][newY] = getSum(mat, newX, newY, m, n);
        }
    }
    return newMat;
}

int main(void) {
    vector<vector<int>> mat = {{1, 5, 2, 3, 5, 6, 1},
                                {2, 1, 1, 9, 4, 8, 3},
                                {1, 1, 2, 3, 5, 2, 9},
                                {1, 1, 2, 3, 5, 2, 9}};
                                // {1, 1, 2, 3, 5, 2, 9}};

    vector<vector<int>> res = blur_odd(mat, 2, 5);
    for(auto x : res) {
        for(auto y : x) {
            cout << y << "\t";
        }
        cout << endl;
    }

    return 0;
}