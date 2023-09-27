// spiral mat
void spiralMat(int n, vector<vector<int>>& mat) {
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
        mat[half][half] = count;
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