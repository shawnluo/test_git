#include "common.h"
#include "test.h"

//Given a string, return true if the s can be palindrom after deleting at most one character from it.
int palindrom_ext(char *s) {
    int size = strlen(s);
    char *left = s;
    char *right = s + size - 1;
    int count = 0;
    while(left < right) {
        if(*left == *right) {
            left++, right--;
        } else {
            count++;
            left++;
        }
    }
    if(count <= 1) return true;
    count = 0;
    while(left < right) {
        if(*left == *right) left++, right--;
        else    count++, right--;
    }
    if(count <= 1) return true;
    return false;
}

double myPow(double x, int n) {
    int N = n;
    double res = 1.0;
    if(n < 0) {
        x = 1 / x;
        N = -N;
    }
    for(int i = n; i != 0; i = i / 2) {
        if(i % 2)   res = res * x;
        x = x * x;
    }
    return res;
}

int main(void) {
    // break_int(8);
    int res = myPow(3, 2);
    printf("%d\n", res);

    return 0;
}