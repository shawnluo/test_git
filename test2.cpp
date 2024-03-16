#include "test.hpp"




bool isValidSudoku(vector<vector<char>>& board) {
    vector<unordered_set<char>> rows(9);
    vector<unordered_set<char>> cols(9);
    vector<unordered_set<char>> boxs(9);

    auto exists = [](unordered_set<char>& s, int val) { 
        return s.insert(val).second;
    };

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            char num = board[i][j];
            if(num == '.') {
                continue;
            }
            if(!exists(rows[i], num) || !exists(cols[j], num) || !exists(boxs[(i / 3) * 3 + j / 3], num)) {
                return false; 
            }
        }
    }
    return true;
}

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

int main(void) {
    // cout << isValidSudoku(board1);

    vector<vector<int>> v = getSum(mat);

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}