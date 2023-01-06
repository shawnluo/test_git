#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>
#include <limits.h>
#include <math.h>



//[11] remove duplicated elements
//
void rm_dup_elements(char *str) {
    int hash[256] = {0};
    int size = strlen(str);
    int slow, fast;

    for(fast = 0, slow = 0; fast < size; ) {
        if(hash[str[fast]]++ == 0) {
            str[slow] = str[fast];
            ++slow, ++fast;
        } else {
            ++fast;
        }
    }
    str[slow] = '\0';
    printf("%s\n", str);
}

void rm_dup_elements_integer(int *arr, int size) {
    int hash[1000] = {0};
    int slow, fast;

    for(slow = 0, fast = 0; fast < size; ) {
        if(hash[arr[fast]]++ == 0) {
            arr[slow] = arr[fast];
            ++slow, ++fast;
        } else {
            ++fast;
        }
    }
    for(int i = 0; i < slow; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    char str[] = "abacaabn";
    rm_dup_elements(str);   

    int arr[] = {1, 7, 9, 1, 8, 1, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    rm_dup_elements_integer(arr, size); 

    return 0;
}