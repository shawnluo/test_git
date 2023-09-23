


void showMe(const vector<vector<int>> mat) {
    for (auto x : mat) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}

void rotate(vector<vector<int>>& mat) {
    int len = mat.size();

    for (int i = 0; i < len / 2; i++) {
        for (int j = i; j < len - i - 1; j++) {
            int save                      = mat[i][j];
            mat[i][j]                     = mat[j][len - 1 - i];
            mat[j][len - 1 - i]           = mat[len - 1 - i][len - 1 - j];
            mat[len - 1 - i][len - 1 - j] = mat[len - 1 - j][i];
            mat[len - 1 - j][i]           = save;

            // mat[i][j] = mat[len - 1 - j][i];
        }
    }
}

// This only works for even length of mat
void rotateMatrix(vector<vector<int>>& mat) {
    int len = mat.size();
    int tmp;
    for(int i = 0; i < len / 2; i++) {
        for(int j = 0; j < len / 2; j++) {
            tmp = mat[i][j];
            mat[i][j] = mat[j][len - 1 - i]; // anti-clockwise
            mat[j][len - 1 - j] = mat[len - 1 - i][len - 1 - j];
            mat[len - 1 - i][len - 1 - j] = mat[len - 1 - j][i];
            mat[len - 1 - j][i] = tmp;
        }
    }
}


int main(void) {
    vector<vector<int>> mat = { { 1, 2, 3 },
                                { 4, 5, 6 },
                                { 7, 8, 9 } };
    rotateMatrix(mat);
    showMe(mat);

    return 0;
}