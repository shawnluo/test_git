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

int main(void) {
    //int cost[5] = {6, 4, 7, 2, 1};
    //ladder_energy(5, cost);
    //integer_break(10);
    
    //char s1[] = "abcxd";
    //char s2[] = "xabcrpd";
    //longest_common_subsequence(s1, s2);
    //int arr[] = {-3, -4, 10, -3, -1, 7, -5};
    //smallestSumSubarr(arr, sizeof(arr) / sizeof(arr[0]));

    //print_bin_ext(14);
    bin_print(14);

    return 0;
}