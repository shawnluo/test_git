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
    output = popen("ls -l", "r");
    // output = popen("ls -l", "w");
    if (output == NULL) {
        perror("Error opening file");
        return (-1);
    }

    while (fgets(buf, size, output) != NULL) { // 每次读取size大小的字节数据(自动加上结尾的'\0')，直到遇到文件结尾符号，返回NULL
        printf("%s\n", buf);
    }

    return 0;
}

// 2. pclose

int main(void) {
    int size = 5;
    FILE* output;
    char buf[size];
    memset(buf, 0, size);

    output = popen("sleep 5", "r");
    if (output == NULL) {
        perror("Error opening file");
        return (-1);
    }

    // popen不会阻塞，这一句会被立刻执行
    printf("---1--\n");

    // pclose会阻塞到这里，直到popen执行完毕
    int status = pclose(output);

    printf("---2--\n");


    return 0;
}