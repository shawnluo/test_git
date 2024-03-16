
#include "test.hpp"

void rotate(vector<vector<int>>& mat) {
    int n = mat.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
}

int main() {
    vector<vector<int>> mat = {
                                {1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9},
                                };

    rotate(mat);

    for(auto x : mat) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}