#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(void) {
    int size = 5;
    FILE* fp;
    char buf[size];
    memset(buf, 0, size);

    fp = fopen("test.tmp", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return (-1);
    }

    // 每次读取size大小的字节数据(自动加上结尾的'\0')，
    // 直到遇到文件结尾符号，返回NULL
    while (fgets(buf, size, fp) != NULL) {
        printf("%s\n", buf);
    }

    return 0;
}

/*
test.tmp:
1234567890

输出：
1234
5678
90
*/