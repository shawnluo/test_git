


#include "test.hpp"
#include <thread>

using namespace std;
 
/* TODO
    1. 🔥   find island
    2. decimal to bin c/c++
    3. bin to decimal c/c++
 */

int str2Int(string s) {
    s = "101.011";
    int n = s.size();
    string intPart;
    string decPart;

    int pos = s.find('.');
    if(pos != string::npos) {
        // cout << pos << endl;
        intPart = s.substr(0, pos);
        decPart = s.substr(pos + 1);
        cout << intPart << endl;
        cout << decPart << endl;
    } else {
        intPart = s;
        decPart = "";
    }

    // int resInt = 0;
    // float resDec = 0.0;
    // for(int i = 0; i < intPart.size(); i++) {
    //     resInt <<= 1;
    //     resInt += (intPart[i] - '0');
    // }
    // cout << resInt << endl;

    // for(int i = 0; i < decPart.size(); i++) {
    //     int cur = decPart[i] - '0';
    //     if(cur == '1') {
    //         resDec += pow(2, -i);
    //     }
    //     // resDec += resDec;
    // }
    // cout << resDec << endl;

    return 0;
}


int countIsland = 0;  // island count

void sinkIsland(vector<vector<int>>& mat, int row, int col, int x, int y) {

    if(x < 0 || x >= row || y < 0 || y >= col) {
        return;
    }

    if(mat[x][y] == 0) return;

    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    mat[x][y] = 0;
    for(int i = 0; i < 4; i++) {
        // cout << dir[i][0] << " " << dir[i][1] << endl;
        sinkIsland(mat, row, col, x + dir[i][0], y + dir[i][1]);
    }
}


// 0: water
// 1: island
int Islands(vector<vector<int>>& mat) {
    int row = mat.size(), col = mat[0].size();
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) { 
            if(mat[i][j] == 1) {
                countIsland++;
                sinkIsland(mat, row, col, i, j);
            }
        }
    }
    return countIsland;
}

// fib
int fib(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main(void) {
    int res = 0;
    string s = "11.01";
    res = str2Int(s);

    // vector<vector<int>> mat = {
    //                             {0, 1, 1, 1, 0, 1},
    //                             {0, 0, 0, 0, 0, 0},
    //                             {0, 0, 0, 0, 0, 0},
    //                             {0, 0, 0, 0, 0, 0},
    //                             {0, 0, 0, 0, 0, 0},
    //                             {0, 0, 0, 1, 0, 0},
    //                             {0, 0, 0, 0, 0, 0}
    // };

    // res = Islands(mat);
    // cout << res << endl;
    // set all 1s mask from m to n


    return 0;
}