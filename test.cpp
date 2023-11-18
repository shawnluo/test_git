


#include "test.hpp"

/*
    如果是int型的数据，优先队列内部已经帮我们写好了
    priority_queue<int, vector<int>, less<int>> pq;  // 最大堆
    priority_queue<int, vector<int>, greater<int>> pq;  // 最小堆
*/

/* TODO 
    1. blur
    2. 
        1). priority_queue<int, vector<int>, less<int>>     pq;
        2). priority_queue<int, vector<int>, greater<int>>  pq;
*/

int getSum(const vector<vector<int>>& mat, int newX, int newY, const int m, const int n) {
    int sum = 0;

    for(int i = newX; i < newX + m; i++) {
        for(int j = newY; j < newY + n; j++) {
            sum += mat[i][j];
        }
    }
    return sum / (m * n);
}

vector<vector<int>> blur(const vector<vector<int>>& mat, const int m, const int n) {
    int row = mat.size();
    int col = mat[0].size();
    
    if(m > row || n > col) {
        return {};
    }

    // calculate the new mat size
    int newRow = row - m + 1;
    int newCol = col - n + 1;

    cout << newRow << " ";
    cout << newCol << endl;

    vector<vector<int>> newMat(newRow, vector<int>(newCol, 0));

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

    vector<vector<int>> res = blur(mat, 20, 2);
    for(auto x : res) {
        for(auto y : x) {
            cout << y << "\t";
        }
        cout << endl;
    }

    return 0;
}
