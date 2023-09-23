
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
// (you may want to display this pattern in a fixed font for better legibility)

/*
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
*/

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        int col = 0;
        int index = 0;
        string res;
        vector<vector<char>> mat(numRows, vector<char> (1000, ' '));

        while(index < len) {
            for(int i = 0; i < numRows && index < len; i++) {
                mat[i][col] = s[index++];
            }
            col++;
            for(int i = numRows - 2; i > 0 && index < len; i--) {
                mat[i][col++] = s[index++];
            }
        }
        for(int i = 0; i < numRows; i++) {
            for(int j = 0; j < col; j++) {
                if(mat[i][j] != ' ') {
                    res.push_back(mat[i][j]);
                }
            }
        }
        return res;
    }
};

int main(void){
    string s = "s";
    int row = 4;

    Solution sol;
    cout << sol.convert(s, row) << endl;

    return 0;
}