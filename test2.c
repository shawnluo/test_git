#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
typedef struct node {
    int index;
    struct node *next;
} Node, *pNode;

#define SIZE sizeof(Node)

int myStrcpy(char *src, char *des) {
    if(!src || !des) {
        printf("src or des is null!\n");
        return -1;
    }
    //char *tmp_des = des;

    while(*src != '\0') {
        *des++ = *src++;
    }
    *des = '\0';

    return 0;
}

//TODO 1: 
int isSub(char *str, char *subStr) {
    if(!str || !subStr) {
        printf("empty str\n");
        return -1;
    }

    char *p_str = NULL;
    char *p_substr = NULL;
    char *p_tmp = NULL;

    for(p_str = str; *p_str; p_str++) {
        p_tmp = p_str;
        for(p_substr = subStr; *p_substr; p_substr++) {
            if(*p_tmp++ != *p_substr) {
                break;
            }
        }
        if(!*p_substr) {
            return 1;
        }
    }

    return 0;
}

//TODO 2: 01
int common_uniq_str() {
    int pos = -1;
}

int main(void) {
    char src[] = "good";
    //char *des = (char *)malloc(100);
    //memset(des, 0, 100);
    char des[20] = {0};
    if(myStrcpy(src, des) == -1) {
        printf("wrong des or src!\n");
    }
    printf("%s\n", des);

    int ret = isSub(src, "oqd");
    printf("ret = %d\n", ret);

    return 0;
}