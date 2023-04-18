#include "common.h"
#include "test.h"


int shortest_path(int grid[][], int n, int m) {
    if(grid == NULL || n) return 0;
    //int n = grid.length;
    //int m = grid[0].length;        
    int dp[][] = new int[n][m];
    for(int j=0;j<m;j++){
        dp[0][j] = (j==0?grid[0][0]:dp[0][j-1]+grid[0][j]);
    }
    for(int i=1;i<n;i++){
        dp[i][0] = dp[i-1][0]+grid[i][0];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j] = Math.min(dp[i-1][j],dp[i][j-1])+grid[i][j];
        }
    }
    return dp[n-1][m-1];
    for(int x = 0; x < col; x++) {
        for(int y = 0; y < row; y++) {
            printf("%d ", mat[x][y]);
        }
        printf("\n");
    }
}

void rotate(int mat[][3], int row, int col) {
    int x, y;
    int save;

    for(x = 0; x < row / 2; x++) {
        for(y = x; y < col - x - 1; y++) {
            save                            = mat[x][y];
            mat[x][y]                       = mat[y][row - x - 1];
            mat[y][row - x - 1]            = mat[row - x - 1][col - y - 1];
            mat[row - x - 1][col - y - 1] = mat[col - y - 1][x];
            mat[col - y - 1][x]            = save;
        }
    }

    for(x = 0; x < row; x++) {
        for(y = 0; y < col; y++) {
            printf("%d ", mat[x][y]);
        }
        printf("\n");
    }
}



void hanoi(int num, int start, int buf, int end) {
    
}

int comp(void **x, void **y) {
    int *a = (int **)x;
    int *b = (int **)y;
    if(a[0] == b[0]) return a[1] - b[1];
    
    return a[0] - b[0];
}

void permutation(char *s, int pos) {
    int len = strlen(s);
    if(pos == len)  printf("%s\n", s);
    for(int i = pos; i < len; i++) {
        swap(s + i, s + pos);
        permutation(s, pos + 1);
        swap(s + i, s + pos);
    }
}


int find_data(int row, int col, int arr[row][col], int target) {
    int x = 0;
    int y = col - 1;
    while(x < row && y >= 0) {
        if(arr[x][y] == target) {
            printf("%d, %d\n", x, y);
            return 0;
        }
        if(target < arr[x][y])  y--;
        else    x++;
    }

    return -1;
}

void circus() {
    int nums[][6] = {{65, 100}, {70, 150}, {56, 90}, {75, 190}, {60, 95}, {68, 110}};

    printf("%d, %d\n", sizeof(nums) / sizeof(nums[0]), sizeof(nums[0]));
    qsort(nums, 6, sizeof(nums[0]), comp);

    for(int i = 0; i < 6; i++) {
        printf("%d, %d\n", nums[i][0], nums[i][1]);
    }
    printf("\n");
}


int main(void) {
    int mat[3][4] = {{1, 4, 2, 9}, 
                    {0, 4, 9, 6}, 
                    {4, 1, 4, 2}};
    shortest_path(mat, 3, 4);
    int arr[][3] = {{0, 1, 2},
                    {3, 4, 5},
                    {6, 7, 8}};

    //rotate_matrix(arr, 3, 3);
    //char s[3] = "abc";
    //permutation(s, 0);
    find_data(3, 3, arr, 6);

    //printf("%s\n", s);
    circus();

    return 0;
}