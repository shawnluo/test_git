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

int longest_common_uniq_str(char *s1, char *s2) {
    int pos = -1;
    int size1 = strlen(s1);
    int size2 = strlen(s2);
    int dp[size1][size2];
    int i, j;
    int max = 0;

    for(i = 0; i < size1; i++) {
        for(j = 0; j < size2; j++) {
            dp[i][j] = 0;
            if(s1[i] == s2[j]) {
                dp[i][j] = 1;
            }
        }
    }

    for(i = 1; i < size1; i++) {
        for(j = 1; j < size2; j++) {
            if(s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
    }

    for(i = 0; i < size1; i++) {
        for(j = 0; j < size2; j++) {
            int tmp = dp[i][j];
            max = tmp > max ? tmp : max; 
        }
    }

    printf("%d\n", max);
}

int main(void) {
    #if 0
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
    #endif

    char *s1 = "showme";
    char *s2 = "gowod";

    longest_common_uniq_str(s1, s2);

    return 0;
}