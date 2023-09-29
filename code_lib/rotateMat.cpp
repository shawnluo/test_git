// rotate mat
void rotateMat(vector<vector<int>>& mat) {
    int size = mat.size();

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
    for(int i = 0; i < size / 2; i++) {
        for(int j = i; j < size - i - 1; j++) {  //注意起始点和终止点！！！
            int save = mat[i][j];
            // [l, R) - top
            mat[i][j] = mat[j][size - i - 1];
            // [U, D) - right
            mat[j][size - i - 1] = mat[size - i - 1][size - j - 1];
            // [R, L) - bottom
            mat[size - i - 1][size - j - 1] = mat[size - j - 1][i];
            // [D, U) - left
            mat[size - j - 1][i] = save;
        }
    }
}