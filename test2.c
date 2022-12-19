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
    myData = (pNode)malloc(SIZE);   //TODO wrong!!!
    for(int i = 0; i < 4; i++) {
        myData[i].index = i;
    }
    for(int i = 0; i < 4; i++) {
        printf("%d\n", myData[i].index);
    }
    free(myData);
    return 0;
}