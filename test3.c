#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    int i = -1;
    char *s = "show";

    int bigger = i > strlen(s) ? i : 100;

    printf("%d\n", bigger);
    return 0;
}