#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>
#include <limits.h>
#include <math.h>


void bin_print(int n) {
    unsigned char *p = (unsigned char *)&n;
    p = p + 3;

    for(int j = 0; j < 4; j++) {
        for(int i = 7; i >= 0; i--) {
            if((*p) & (1 << i)) {
                printf("1");
            } else {
                printf("0");
            }
        }
        p--;
        printf("\n");
    }
}

void print_bin_ext(int num)
{
    int i, j, data = 0;
    unsigned char *p = (unsigned char *)&num + 3;     //point to the top memory address of num. (integer uses 4 bytes)
    for(i = 0; i < 4; i++)
    {
        data = *(p - i); //取每个字节的首地址，从高位字节到低位字节，即p p-1 p-2 p-3地址处
        for(j = 7; j >= 0; j--) //处理每个字节的8个位，注意字节内部的二进制数是按照人的习惯存储！
        {
            if(data & (1 << j))//1左移k位，与单前的字节内容j进行或运算，如k=7时，00000000&10000000=0 ->该字节的最高位为0
            {
                printf("1");
            }
            else
            {
               printf("0");
            }
        }
        printf(" ");
    }
    printf("\r\n");
}

#if 0
pNode reverse_ll(pNode pHead) {
    pNode pNext = NULL;
    pNode pCur = pHead;
    pNode pPrev = NULL;

    while(pCur) {
        pNext = pCur->next;
        pCur->next = pPrev;
        pPrev = pCur;
        pCur = pNext;
    }
    return pPrev;
}
#endif


void print_matrix(void *_matrix, int n) {
    int (*matrix)[n] = _matrix;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void rotate_matrix(void *_matrix, int n) {
    int (*matrix)[n] = (int (*)[n])_matrix;
    //print_matrix(matrix, n);

    for(int x = 0; x < n / 2; x++) {
        for(int y = 0; y < n / 2; y++) {
            int save = matrix[x][y];
            matrix[x][y] = matrix[y][n - x - 1];
            matrix[y][n - x - 1] = matrix[n - x - 1][n - y - 1];
            matrix[n - x - 1][n - y - 1] = matrix[n - y - 1][x];
            matrix[n - y - 1][x] = save;
        }
    }

    print_matrix(matrix, n);
    /*
        matrix[x]        [y]         = matrix[y]        [n - x - 1]
        matrix[y]        [n - x - 1] = matrix[n - x - 1][n - y - 1]
        matrix[n - x - 1][n - y - 1] = matrix[n - y - 1][y]
    */
}

void spiral_matrix_x(int n) {
    int startx = 0, starty = 0;
    int count = 0;
    int x = 0, y = 0;
    int matrix[n][n];
    int offset = 1;

    int num = n / 2;
    while(num--) {
        x = startx;
        y = starty;
        for(y = starty; y < n - offset; y++) {
            matrix[x][y] = count++;
        }
        for(x = startx; x < n - offset; x++) {
            matrix[x][y] = count++;
        }
        for(; y > starty; y--) {
            matrix[x][y] = count++;
        }
        for(; x > startx; x--) {
            matrix[x][y] = count++;
        }
        startx++, starty++;
        offset++;
    }
    if(n % 2) {
        matrix[n / 2][n / 2] = count;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


void spiral_matrix(int n) {
    int mid = n / 2;
    int offset = 1;
    int startx = 0, starty = 0;
    int x, y;
    int count = 0;
    int matrix[n][n];

    while(mid--) {
        x = startx;
        y = starty;
        for(y = starty; y < n - offset; y++) {
            matrix[x][y] = count++;
        }
        for(x = startx; x < n - offset; x++) {
            matrix[x][y] = count++;
        }
        for(; y > starty; y--) {
            matrix[x][y] = count++;
        }
        for(; x > startx; x--) {
            matrix[x][y] = count++;
        }

        startx++, starty++;
        offset++;
    }
}

int main(void) {    
    char arr1[] = "abcxd";
    char arr2[] = "xabcrpd";
    longest_common_subsequence(arr1, arr2);
    
    return 0;
}