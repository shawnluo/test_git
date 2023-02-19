#include "common.h"
#include "test.h"

//Given a string, return true if the s can be palindrom after deleting at most one character from it.
int palindrom_ext(char *s) {
    //left and right pointers.
    //step1. compare *left with *right, if don't match then skip 1 on left. 
    //    if skip <= 1, then return true
    //step2. do the same thing on right.
    //  if skip <= 1, then return true;
    int size = strlen(s);
    int left = s;
    int right = s + size - 1;
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
    if count <= 1 return true;

    return false;
}

int main(void) {
    // break_int(8);
    int res = myPow(-0.3, -3);
    printf("%d\n", res);

    return 0;
}