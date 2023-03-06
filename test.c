#include "common.h"
#include "test.h"

int *find_anagrams(char *s, char *sub) {
    int len_s = strlen(s);
    int len_sub = strlen(sub);
    int hash[256] = {0};

    for(int i = 0; i < len_sub; i++) {
        hash[sub[i]]++;
    }
    int count = len_sub;
    int left = 0, right = 0;
    static int res[10];

    count = 0;
    while(right < len_s) {
        if(hash[s[right++]]-- >= 1) {
            count--;
        }
        if(count == 0) {
            res[count++] = left;
        }

        if(right - left == len_sub && hash[s[left++]]++ >= 0) {
            count ++;
        }
    }
}

bool check_inclusion(char *s, char *sub) {
    int len_s = strlen(s);
    int len_sub = strlen(sub);
    int hash[256] = {0};
    for(int i = 0; i < len_sub; i++) {
        hash[sub[i]]++;
    }

#if 1
    for(int i = 0; i < len_s; i++) {
        hash[s[i]]--;
        if(i >= len_sub) {
            hash[s[i - len_sub]]++;
        }
        int j;
        for(j = 0; j < 256; j++) {
            if(hash[j] != 0)   break;
        }
        if(j == 256)    return true;
    }
    #endif
    return false;
}

int main(void) {
    char *s = "xabcy";
    char *sub = "bauc";
    bool res = check_inclusion(s, sub);
    printf("%d\n", res);

    return 0;
}