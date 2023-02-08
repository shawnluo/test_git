#include "common.h"
#include "test.h"



#define swap(a, b) (a) = (b) - (a), (b) = (b) - (a), (a) = (b) + (a)

void permutation(char *pStr, char *pBegin) {
    assert(pStr && pBegin);

    if(*pBegin == '\0') {
        printf("%s\n", pStr);
    } else {
        for(char *pCh = pBegin; *pCh != '\0'; pCh++) {
            swap(*pBegin, *pCh);
            permutation(pStr, pBegin + 1);
            swap(*pBegin, *pCh);
        }
    }
}


void test(char *x, char *y) {
    char tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}


int main(void) {
    char s[] = "abc";
    printf("%s\n", s);
    test(&s[0], &s[2]);
    printf("%s\n", s);
    
    return 0;
}