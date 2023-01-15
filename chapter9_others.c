#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>




/************************ 1 *************************************
    sizeof() returns unsigned long
    -1 forced transfer to unsigned long: 0xFFFFFFFFFFFFFFFF
*/
void case1() {
    if(sizeof(int) > -1)    printf("True\n");
    else                    printf("False\n");
}


/************************ 1 *************************************
 * double has 2x more precision than float
 * 1. float is a 32-bit IEEE 754 single precision Floating Point Number:
 *      1 bit for the sign
 *      8 bits for the exponent
 *      23* for the value
 *      float has 7 decimal digits of precision
 * 2. double is a 64-bit IEEE 754 double precision Floating Point Number:
 *      1 bit for the sign
 *      11 bits for the exponent
 *      52 bits for the value
 *      double has 15 decimal digits of precision
 */
void case2() {
    float f = 0.1;

    if(f == 0.1)    printf("True\n");
    else            printf("False\n");
}


int main(void) {


    return 0;
}

