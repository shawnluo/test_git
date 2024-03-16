#include "test.hpp"

bool isValidSudoku(vector<vector<char>>& board) {
    std::vector<unordered_set<char>> rows(9), cols(9), box(9);
    auto exists = [](unordered_set<char>& s, int val) { return s.insert(val).second; };

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            char num = board[i][j];
            if (num == '.') continue;
            if (!exists(rows[i], num) || !exists(cols[j], num) || !exists(box[(i / 3) * 3 + j / 3], num)) {
                return false;
            }
        }
    return true;
}

int main(void) { 
    unordered_set<char> v;
    
    return 0; 
}