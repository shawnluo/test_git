#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// 1. basic

int main(void) {
    int size = 5;
    FILE* output;
    char buf[size];
    memset(buf, 0, size);

    // "r": 将命令得到的结果存在output
    // "w": 将命令结果直接输出，output不会得到结果
    output = popen("sleep 5", "r");
    // output = popen("ls -l", "w");
    if (output == NULL) {
        perror("Error opening file");
        return (-1);
    }

    printf("-----\n");
    int status = pclose(output);

    printf("---3--\n");

    // while (fgets(buf, size, output) != NULL) { // 每次读取size大小的字节数据(自动加上结尾的'\0')，直到遇到文件结尾符号，返回NULL
    //     printf("%s\n", buf);
    // }

    return 0;
}