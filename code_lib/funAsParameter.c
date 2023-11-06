
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void showMe() {
    printf("hello\n");
}

void run(void* fun) {
    ((pF)(fun))();
}


int main() {
    run(showMe);

    return 0;
}