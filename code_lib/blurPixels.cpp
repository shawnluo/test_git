
#include "test.hpp"


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