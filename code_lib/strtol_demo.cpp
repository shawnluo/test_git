#include "test.hpp"

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_set>

/* strtol example */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* strtol */

int main() {
    char szNumbers[] = "2001 60c0c0 -1101110100110100100000 0x6fffff";
    char* pEnd;
    long int li1, li2, li3, li4;
    
    // long int strtol(const char* str, char** endptr, int base)
    // convert a string to a long interger,
    // 1. fist, discards as many whitespace charaters as necessary until the first non-whitespace character is found.
    // 2. then, starting from this character, takes as many as possible that are valid following a syntax that depens
    //      on the base parameter, and interprets them as a numerical value.
    // 3. finally, a pointer to the first character following the integer representation in str is stored in the
    //      object pointed by endprt.
    // 4. if the first sequence of non-whitespace characters in str is not a valid integral number as defined above,
    //      or if no such sequence exists because either str is empty or it contains only whitespace characters,
    //      no conversion is performed.

    li1 = strtol(szNumbers, &pEnd, 10);
    li2 = strtol(pEnd, &pEnd, 16);
    li3 = strtol(pEnd, &pEnd, 2);
    li4 = strtol(pEnd, NULL, 0);

    printf("The decimal equivalents are: %ld, %ld, %ld and %ld.\n", li1, li2, li3, li4);

    return 0;
}