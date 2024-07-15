#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>
#include <limits.h>
#include <math.h>

#define REG *(volatile unsigned long *)0x00008000

//set n bits from startBit for REG
void setBits(int startBit, int n) {
    int i;
    for(i = 0; i < n; i++) {
        REG |= (1 << (startBit + i));
    }
}

int bitmask(int n, int m, int i, int j) {
    // int left = (1 << (m + 1)) - 1;
    // int right = ()
    int max = ~0;
    int left = max - ((1 << j) - 1);
    int right = ((1 << i) - 1);

    int mask = left | right;

    return (n & mask) | (m << i);
}

int bitmask2(int n, int m, int i, int j) {
    int left = (1 << (j + 1)) - 1;
    int right = (1 << i) - 1;
    int mask = left - right;    // mask is all 1s
    n = n & (~mask);    // for n, mask area all 0s

    return n | (m << i);
}


int main(void) {
    return 0;
}