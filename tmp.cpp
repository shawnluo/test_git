
#include "test.hpp"

int getSum(vector<vector<int>>& tmp, int x, int y, int size) {
    x = x + size / 2;
    y = y + size / 2;
    int res = 0;
    for(int i = -size / 2; i < size / 2; i++) {
        for(int j = -size / 2; j < size / 2; j++) {
            res += tmp[i + x][j + y];
        }
    }
    return res;
}

void spiral(vector<vector<int>>& mat, vector<vector<int>>& newMat, int size) {
    int n = mat.size();
    int half = n / 2;
    int startX = 0;
    int startY = 0;
    int offset = 1;

    int newN = n + size / 2 * 2;    // 新的padding后的矩阵长度。如果size是3，则要加上 3 / 2 * 2 = 2。如果是5，则要加上 5 / 2 * 2 = 4
    newMat.resize(n, vector<int>(n));

    // copy mat to newN
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            newMat[i + size / 2][j + size / 2] = mat[i][j];
        }
    }

    vector<vector<int>> tmp(newN, vector<int>(newN, 0));
    // int count = 1;
    half = 1;
    while(half--) {
        int x = startX;
        int y = startY;
        for(; y < newN - offset; y++) tmp[x][y] = 0;
        for(; x < newN - offset; x++) tmp[x][y] = 0;
        for(; y > startY; y--) tmp[x][y] = 0;
        for(; x > startX; x--) tmp[x][y] = 0;

        startX++;
        startY++;
        offset++;
    }

    // blur
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            newMat[i][j] = getSum(tmp, i , j, size);
        }
    }
}


int main(void) {
    vector<vector<int>> mat = {{1, 2, 3, 4, 5},
                                {6, 7, 8, 9, 10},
                                {11, 12, 13, 14, 15},
                                {16, 17, 18, 19, 20},
                                {21, 22, 23, 24, 25}};
    vector<vector<int>> newMat; 
    spiral(mat, newMat, 5);

    showMeV(newMat);

    return 0;
}