#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<stdio.h>  
#include<stdlib.h>  
  
  
int main()  
{  
    int **a;  //用二级指针动态申请二维数组  
    int i,j;  
    int m,n;  

    m = 3;
    n = 5;

    a=(int**)malloc(sizeof(int*)*m);  
    for(i=0;i<m;i++) {
        a[i]=(int*)malloc(sizeof(int)*n);  
    }

    for(i=0;i<m;i++) {
        for(j=0;j<n;j++) {
            printf("%p \t",&a[i][j]);     //输出每个元素地址，每行的列与列之间的地址时连续的，行与行之间的地址不连续
        }
        printf("\n");
    }
    for(i=0;i<m;i++)  
    free(a[i]);
 
    free(a);  
    return 0;  
} 