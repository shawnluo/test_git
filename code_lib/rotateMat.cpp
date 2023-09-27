// rotate mat
void rotateMat(vector<vector<int>>& mat) {
    int row = mat.size();
    int col = mat[0].size();

    for(int i = 0; i < row / 2; i++) {
        for(int j = i; j < col - i - 1; j++) {
            int save = mat[i][j];
            // [l, R) - top
            mat[i][j] = mat[j][row - i - 1];
            // [U, D) - right
            mat[j][row - i - 1] = mat[row - i - 1][row - j - 1];
            // [R, L) - bottom
            mat[row - i - 1][row - j - 1] = mat[row - j - 1][i];
            // [D, U) - left
            mat[row - j - 1][i] = save;
        }
    }
}