#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    int i = 97;
    char res[100] = {'0'};
    sprintf(res, "%c", i);
    printf("%s\n", res);

    sprintf(res, "%d", i);
    printf("%s\n", res);

    return 0;
}