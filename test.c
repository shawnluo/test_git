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


int main(void) {
    test();

    return 0;
}