#include "common.h"
#include "test.h"

int bin_add(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int sum = 0;
    int sizeOutput = (len1 > len2 ? len1 : len2) + 1;
    char *output = (char *)malloc(sizeOutput + 1);

    while(len1 > 0 || len2 > 0 || sizeOutput > 0) {
        if(len1 > 0 ) {
            sum += s1[--len1] - '0';
        }
        if(len2 > 0) {
            sum += s2[--len2] - '0';
        }
        output[--sizeOutput] = sum % 2 + '0';
        sum /= 2;
    }
    return output + sizeOutput;
}

int main(void) {
    char s[] = "abc";
    string_reverse(s);
    printf("%s\n", s);

    return 0;
}