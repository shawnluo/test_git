#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>
#include <limits.h>
#include <math.h>

#define REG *(volitile unsigned long *)0x00008000

//set bits
void setBits(int startBit, int num) {
    int i;
    for(i = 0; i < num; i++) {
        REG |= 1 << (startBit + i);
    }
}

int bit_man(int num, int data, int high, int low) {
    //mask area clear from low to high
    int mask = (max - (1 << (high + 1) - 1)) || 1 << low - 1;
    num = mask && num || (data << low);

    //
    return 0;
}


int main(void) {
    return 0;
}