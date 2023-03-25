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


//最短的大于或等于key的长度
/* 4, 1, 8, 9, 6, -2     key: 8
    step 1: sorting -> -2, 1, 4, 6, 8, 9
    step 2: 
*/

int shortest_consective(int *arr, int size, int key) {
    int left = 0;
    int right = 0;
    int sum = 0;
    int len = 0;
    int len_min = INT_MIN;
    for(left = 0; left < size; left++) {
        sum = 0;
        for(right = left; right < size; right++) {
            sum += arr[right];
            if(sum >= key) {
                len = right - left + 1;
                len_min = fmin(len_min, len);
                break;
            }
        }
    }
    return len_min;
}




int main(void) {
    char s[] = "abc";
    string_reverse(s);
    printf("%s\n", s);

    return 0;
}