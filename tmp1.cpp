#include "test.hpp"

#include <functional>
#include <semaphore.h>
#include <thread>
using namespace std;


// string s combination

int minSum = INT_MAX;
vector<int> path;
vector<vector<int>> res;
void dfs(string s, int pos) {
    int n = s.size();
    if(pos == n) {
        cout << s << endl;
        // return;
    }
    for(int i = pos; i < n; i++) {
        swap(s[i], s[pos]);
        dfs(s, i + 1);
        swap(s[i], s[pos]);
    }
}

void permutation(string s, int pos) {
    int size = s.size();
    if(pos == size){
        cout << s << endl;
    }
    for(int i = pos; i < size; i++) {
        swap(s[i], s[pos]);
        permutation(s, pos + 1);
        swap(s[i], s[pos]);
    }
}


int findMinFallingPathSum(vector<vector<int>>& matrix, int row, int col) {
    if(col < 0 || col > matrix.size()) {
        return INT_MAX;
    }
    if(row == matrix.size() - 1) {
        return matrix[row][col];
    }
    int left = findMinFallingPathSum(matrix, row + 1, col - 1);
    int mid = findMinFallingPathSum(matrix, row + 1, col);
    int right = findMinFallingPathSum(matrix, row + 1, col + 1);

    return min({left, mid, right}) + matrix[row][col];
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    int minFallingSum = INT_MAX;

    for(int startCol = 0; startCol < matrix.size(); startCol++) {
        minFallingSum = min(minFallingSum, findMinFallingPathSum(matrix, 0, startCol));
    }
    return minFallingSum;
}

int main(void) {
    string s = "abc";
    dfs(s, 0);

    return 0;
}