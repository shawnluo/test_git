#include "common.h"
#include "test.h"



//TODO chapter 5
create() {
    pNode pHead = NULL;
    while(size--) {
        p = (pNode)malloc(LEN);
        p->data = nums[size];
        p->next = pHead;
        pHead = p;
    }
}

create2() {
    if(pHead == NULL) {
        p = (pNode)malloc(LEN);
        p->data = nums[0];
        p->next = NULL:
        pNext = pHead;
    }
    pNew = pHead;
    for(i = 1; i < size; i++) {
        p = (pNode)malloc(LEN);
        p->data = nums[i];
        p->next = NULL;
        pNext->next = p;
        pNext = p;
    }
}

//TODO chapter 6

#define REG *(volatile unsigned int *)0x55000000
REG | 0x1
for(i = 0; i < 8; i++) {
    REG |= (1 << i);
    REG &= ~(1 << i);
}

int main(void) {
    //char s[] = "abc";
    //find_anagrams("xvabc", "av");
    
    return 0;
}