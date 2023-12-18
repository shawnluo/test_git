


#include "test.hpp"
#include <thread>

using namespace std;
 
/* TODO
    1. 🔥   find island
    2. 🔥   decimal to bin c/c++
    3. bin to decimal c/c++
    4. blur
 */

#if 1
int getSum(vector<vector<int>>& mat, int x, int y, int m, int n) {
    int sum = 0;
    for(int i = x; i < x + m; i++) {
        for(int j = y; j < y + n; j++) {
            sum += mat[i][j];
        }
    }
    return sum / (m * n);
}

void blur(vector<vector<int>> mat, int m, int n, int new_row, int new_col, vector<vector<int>>& newMat) {
    // vector<vector<int>> newMat(new_row, vector<int>(new_col, 0));
    for(int i = 0; i < new_row; i++) {
        for(int j = 0; j < new_col; j++) {
            newMat[i][j] = getSum(mat, i, j, m, n);
        }
    }
}

int main(void) {
    vector<vector<int>> mat = {{1, 5, 2, 3, 5, 6, 1},
                                {2, 1, 1, 9, 4, 8, 3},
                                {1, 1, 2, 3, 5, 2, 9},
                                {1, 1, 2, 3, 5, 2, 9}};
                                // {1, 1, 2, 3, 5, 2, 9}};

    int row = mat.size();
    int col = mat[0].size();
    int m = 2;
    int n = 5;
    int new_row = row - m + 1;
    int new_col = col - n + 1;

    vector<vector<int>> newMat(new_row, vector<int>(new_col, n));
    blur(mat, m, n, new_row, new_col, newMat);
    for(auto x : newMat) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}
#else 

int getSum(const vector<vector<int>>& mat, int newX, int newY, const int m, const int n) {
    int sum = 0;
    // 4. x 和 y 分别从0 + newX的偏移开始计算新mat的成员值。
    for(int i = newX; i < newX + m; i++) {
        for(int j = newY; j < newY + n; j++) {
            sum += mat[i][j];
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
#endif