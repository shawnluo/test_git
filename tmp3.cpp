
#include "test.hpp"

void spiralMat(vector<vector<int>>& mat) {
    int n = mat.size();
    int half = n / 2;
    int startX = 0;
    int startY = 0;
    int count = 1;
    int offset = 1;

    while(half--) {
        int x = startX;
        int y = startY;
        
        for( ; y < n - offset; y++) {
            mat[x][y] = count++;
        }
        for( ; x < n - offset; x++) {
            mat[x][y] = count++;
        }
        for( ; y > startY; y--) {
            mat[x][y] = count++;
        }
        for( ; x > startX; x--) {
            mat[x][y] = count++;
        }
        startX++;
        startY++;
        offset++;
    }

    if(n % 2) {
        mat[n / 2][n / 2] = count;  // 注意不要用half，之前已经自减过了！
    }

    // for(auto x : mat) {
    //     for(auto y : x) {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
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

    spiralMat(mat);

    // for_each(mat.begin(), mat.end(), [](auto x){
    //     for_each(x.begin(), x.end(), [](auto y){cout << y << " ";});
    //     cout << endl;
    // });
    return 0;
}