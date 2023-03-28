#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>



 
int main(){
    int a[4][3] = {{1,2,3},
                   {4,5,6},
                   {7,8,9},
                   {10,11,12}};
    int b[3][4];
    int m = 4, n = 3;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
           b[i][j] = a[j][n - 1 - i];
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
 
  return 0;
}