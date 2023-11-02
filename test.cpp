#include "test.hpp"

typedef struct node {
    int data;
    struct node* left;
    struct node* right;

    node(int val) : data(val), left(nullptr), right(nullptr) {}
} Node;

void appendLL(pNode& pHead, int data) {
    if(pHead == nullptr) {
        pHead = (pNOde)malloc(SIZE);
        pHead->data = data;
        return;
    }
    while(pHead->next) {
        pHead = pHead->next;
    }
    pNew = (pNode)malloc(SIZE);
    pNew->data = data;
    pHead->next = pNew;
}

void createLL(pNode& pHead, void* data, int size) {
    if(!pHead) {
        pHead = (pNode)malloc(SIZE);
        pHead=>data = data[0];
    }

    pNode pCur = pHead;
    pNode pNext = nullptr;
    int *arr = (int*)data;
    
    for(int i = 1; i < size; i++) {
        pNext = (pNode)malloc(SIZE);
        pNext->data = data[i];
        pNext->next = nullptr;

        pCur->next = pNext;
        pCur = pNext;
    }
}

void createLLExt(pNode& pHead, int* data, int size) {
    
}

pNode AddLL(pNode a, pNode b) {
    int carry = 0;
    pNode p = nullptr;

    while(a || b) {
        int data = carry;
        if(a) {
            data += a->data;
        }
        if(b) {
            data += b->data;
        }
        carry = (data >= 10 ? 1 : 0);
        data = data % 10;
        appendLL(p, data);

        if(a) a = a->next;
        if(b) b = b->next;
    }
    if(carry) appendLL(p, carry);

    return p;
}

int main(void) {
    rmDump();

    return 0;
}