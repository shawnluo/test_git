#include "common.h"
#include "test.h"


void test() {
    int scores[]    = {10,  80, 60, 50, 10};
    int ages[]      = {1,   8,  6,  5,  1};

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5 - i - 1; j++) {
            if(ages[j] > ages[j + 1]) {
                int tmp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = tmp;
            }
        }
    }

    for(int i = 0; i < 5; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n");
}


bool checkInclusion(char * s1, char * s2){
#if 0
    int size1 = strlen(s1);
    int size2 = strlen(s2);
    if(size1 > size2) {
        return 0;
    }

    int hash[256] = {0};
    for(int i = 0; i < size1; i++) {
        hash[s1[i]]++;
    }

    for(int i = 0; i < size2; i++) {
        hash[s2[i]]--;
    }
    for(int i = 0; i < size1; i++) {
        if(hash[s1[i]] > 0) {
            return 0;
        }
    }
    return 1;
#endif
int len1 = strlen(s1);
    int len2 = strlen(s2);
    if(len1 > len2) {
        return false;
    }

    int count[26] = {0};
    for(int i = 0; i < len1; i++){
        count[s1[i] - 'a']++;
    }
    for(int i = 0; i < len2; i++){
        count[s2[i] - 'a']--;
        if(i >= len1){
            count[s2[i - len1] - 'a']++;
        }
        int j;
        for(j = 0; j < 26; j++){
            if(count[j] != 0) {
                break;
            }
        }
        if(j == 26) {
            return true;
        }
    }
    return false;
}


int main(void) {
    test();

    return 0;
}