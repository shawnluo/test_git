#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



int main(void) {
    char *s = (char *)malloc(15);
    strcpy(s, "gooday");
    int len = strlen(s);

    printf("len = %d\n", len);

    return 0;
}