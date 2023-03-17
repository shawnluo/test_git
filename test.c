#include "common.h"
#include "test.h"

double myPow2(double x, int n) {
    long long N = n;
    if(n < 0) {
        x = 1 / x;
        N = -N;
    }
    double res = 1;
    for(long long i = N; i; i /= 2) {
        if((i % 2) == 1)    res = res * x;
        x = x * x;
    }
    return res;
}

int main(void) {
    printf("%f\n", myPow2(3, 3));

    return 0;
}