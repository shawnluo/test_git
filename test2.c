#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int index;
    int rep;
} Node, *pNode;

#define SIZE sizeof(Node)

pNode myData;


int main(void) {
    char p[100] = {0};
    char s[] = "good";
    strcpy(p, s);
    printf("%s\n", p);

    return 0;
}