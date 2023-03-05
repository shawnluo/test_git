#include "common.h"
#include "test.h"

typedef struct Node {
    int num1;
    int num2;
} node;

int func(void *a, void *b) {
    node x = *(node *)a;
    node y = *(node *)b;

    return x.num1 - y.num1;
}

int main(void) {
    node data[5];
    data[0].num1 = 5;
    data[0].num2 = 50;
    data[1].num1 = 4;
    data[1].num2 = 40;
    data[2].num1 = 3;
    data[2].num2 = 30;
    data[3].num1 = 1;
    data[3].num2 = 10;
    data[4].num1 = 2;
    data[4].num2 = 20;

    qsort(data, 5, sizeof(struct Node), func);

    for(int i = 0; i < 5; i++) {
        printf("%d\n", data[i].num1);
    }

    return 0;
}