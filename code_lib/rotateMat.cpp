// rotate mat
void rotateMat(vector<vector<int>>& mat) {
    int row = mat.size();
    int col = mat[0].size();

    /*
        1  2  3  4  5
        6  7  8  9  10
        11 12 13 14 15
        16 17 18 19 20
        21 22 23 24 25

        旋转4个三角形区域
        1  2  3  4  5
           7  8  9
              13
    */
    for(int i = 0; i < row / 2; i++) {
        for(int j = i; j < col - i - 1; j++) {  //注意起始点和终止点！！！
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