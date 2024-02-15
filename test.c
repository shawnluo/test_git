#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>



typedef void (*pF)(void);

void showMe() {
    printf("hello\n");
}

void run1(void* fun) {
    ((pF)(fun))();
}

void run2(pF fun) {
    fun();
}

int main() {
    run1(showMe);

    run2(showMe);

    return 0;
}