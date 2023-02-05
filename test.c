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
    int size1 = strlen(s1);
    int size2 = strlen(s2);
    if(size1 > size2) {
        return 0;
    }
    int i, j;
    int hash[256] = {0};
    for(i = 0; i < size1; i++) {
        hash[s1[i]]++;
    }

    for(i = 0; i < size2; i++) {
        hash[s2[i]]--;
        if(i >= size1) {
            hash[s2[i - size1]]++;
        }
        for(j = 0; j < size2; j++) {
            if(hash[j] != 0) {
                break;
            }
        }
        if(j == 256) {
            return true;
        }
    }
    return false;
}


int main(void) {
    checkInclusion("ab", "xabt");

    return 0;
}