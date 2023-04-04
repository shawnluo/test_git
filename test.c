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
}


int main(void) {
    int mat[3][4] = {{1, 4, 2, 9}, 
                    {0, 4, 9, 6}, 
                    {4, 1, 4, 2}};
    shortest_path(mat, 3, 4);
    return 0;
}