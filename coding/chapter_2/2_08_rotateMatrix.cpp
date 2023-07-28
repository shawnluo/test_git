


void rotateMat2(vector<vector<int>>& mat) {
    int len = mat.size();
    for (int layer = 0; layer < len / 2; layer++) {
        int first = layer;
        int last  = len - 1 - first;
        for (int i = first; i < last; i++) {
            int offset = i - first;
            int top    = matrix[first][i];                            // save top

            mat[first][i]             = matrix[last - offset][first]; // left -> top
            mat[last - offset][first] = mat[last][last - offset];     // bottom -> left
            mat[last][last - offset]  = mat[i][last];                 // right -> bottom
            mat[i][last]              = top;                          // saved top -> right// top -> right
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
            mat[len - 1 - j][len - 1 - i] = mat[len - 1 - j][i];
            mat[len - 1 - j][i] = tmp;
        }
    }
}

void showMe(vector<vector<int>>& mat) {
    for(auto x : mat) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
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