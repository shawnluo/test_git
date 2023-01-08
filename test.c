#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>
#include <limits.h>
#include <math.h>


int isSub(char *s, char *sub) {
    int i, j;
    int size_s = strlen(s);
    int size_sub = strlen(sub);
    for(i = 0; i < size_s; i++) {
        for(j = 0; j < size_sub; j++) {
            if(*(s + i + j) != *(sub + j)) {
                break;
            }
        }
    }
    if(j == size_sub) {
        return 1;
    }
    return 0;
}

int isSub2(char *s, char *sub) {
    char *ps, *psub;
    for(ps = s; *ps; ps++) {
        char *tmp = ps;
        for(psub = sub; *psub; psub++) {
            if(*tmp++ != *psub) {
                break;
            }
        }
    }
    if(*psub == '\0') {
        return 1;
    }
    return 0;
}

//abcba -> c
int first_nonrepeat(char *s) {
    int hash[256] = {0};
    char *p;
    for(p = s; *p; p++) {
        hash[*p]++;
    }

    for(p = s; *p; p++) {
        if(hash[*p] == 1) {
            return *p;
        }
    }
    printf("there is no non-repeat character!\n");
    return -1;
}

int common_sub_str(char *s1, char *s2) {
    
}

int main(void) {
    char str[] = "abacaabn";
    rm_dup_elements(str);   

    int arr[] = {1, 7, 9, 1, 8, 1, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    rm_dup_elements_integer(arr, size); 

    return 0;
}