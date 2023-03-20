#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>
#include <limits.h>
#include <math.h>


/*
    delete duplicats from an unsorted linked list
*/
void del_dups(pNode pHead) {
    pNode pPrev = pHead;
    pNode pCur = pPrev->pHead;

    while(pCur) {
        pNode pRunner = pHead;
        while(pRunner != pCur) {
            if(pRunner->data == pCur->data) {
                pPrev->next = pCur->next;
                pCur = pCur->next;
                break;
            }
            pRunner = pRunner->next;
        }

        if(pRunner == pCur) {
            pRev = pCur;
            pCur = Pcur->next;
        }
    }
}

/*
    find the nth to last element of a singly linked list
*/
pNode nth_to_Last(pNode pHead, int n) {
    if(pHead == NULL || n < 1) {
        return NULL;
    }

    pNode p1 = pHead;
    pNode p2 = pHead;

    for(int i = 0; i < n - 1; i++) {
        if(p2 == NULL) {
            return NULL;
        }
        p2 = p2->next;
    }
    while(p2->next) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}


/*
    delete a node in the middle of a single linked list, given only access to that node
*/
int deleteNode(pNode p) {
    if(p == NULL || p->next == NULL) {
        return -1;
    }

    p->data = p->Next->data;
    p->next = p->next->next;

    return 0;
}


/*
    TODO: add 2 linkedlist - recusion
*/
pNode addLists_recusion(pNode pHead1, pNode pHead2, int carry) {
    if(pHead1 == NULL && pHead2 == NULL) {
        return NULL;
    }

    pNode result = (pNode)malloc(LEN);
    int value = carry;
    if(pHead1 != NULL) {
        value += pHead1->data;
    }
    if(pHead2 != NULL) {
        value += pHead2->data;
    }

    result->data = value % 10;

}


/*
    add 2 linkedlist - loop
*/
int append_LL(pHead pNew, int data) {
    if(pNew == NULL) {
        pNew->data = data;
        pNew->next = NULL;
        return 0;
    }

    while(pNew->next) {
        pNew = pNew->next;
    }
    ptmp = (pNode)malloc(LEN);
    ptmp->data = data;
    ptmp->next = NULL;
    pNew->next = ptmp;

    return 0;
}

pNode addLists(pNode pHead1, pNode pHead2) {
    if(!pHead1 && !pHead2) {
        return NULL;
    }

    pNode pNew = NULL;
    int carry = 0;

    while(pHead1 != NULL || pHead2 != NULL) {
        if(pHead1 == NULL) {
            data = pHead2->data + carry;
            if(data >= 10) {
                data = data - 10;
                carry = 1;
            }
            append_LL(pNew, data);
            pHead2 = pHead2->next;
            continue;
        }
        if(pHead2 == NULL) {
            data = pHead1->data + carry;
            if(data >= 10) {
                data = data - 10;
                carry = 1;
            }
            append_LL(pNew, data);
            pHead1 = pHead1->next;
            continue;
        }
        data = pHead1->data + pHead2->data + carry;
        if(data >= 10) {
            data = data - 10;
            carry = 1;
        }
        append_LL(pNew, data);
        pHead1 = pHead1->next;
        pHead2 = pHead2->next;        
    }
    return pNew;
}


pNode Find_Entry_circular(pNode pHead) {
    pNode pFast = pHead->next->next;
    pNode pSlow = pHead->next;

    while(pFast != NULL && pFast != pSlow) {
        pFast = pFast->next->next;
        pSlow = pSlow->next;
    }
    if(pFast == NULL) {
        return NULL;
    }

    pFast = pHead;
    while(pFast != pSlow) {
        pFast = pFast->next;
        pSlow = pSlow->next;
    }
    return pFast;
}


//stack
int stackSize = 100;
int stack[stackSize];
int sp = 0;
void push(int stack, int value) {

}

int pop(int stack) {

}

int peek(int stack) {

}

//[100] add binary, and return string
//  "101" "1001" -> "1110"
char *addBinary(char *a, char *b) {
    if(a == NULL || b == NULL) {
        return NULL;
    }
    int sizeA = strlen(a);
    int sizeB = strlen(b);
    int sum = 0;
    int sizeOutput = (sizeA > sizeB ? sizeA : sizeB) + 1;
    char *output = (char *)malloc(sizeOutput + 1);

    while(sizeA > 0 || sizeB > 0 || sizeOutput > 0) {
        if(sizeA > 0) {
            sum += a[--sizeA] - '0';
        }
        if(sizeB > 0) {
            sum += b[--sizeB] - '0';
        }
        output[--sizeOutput] = sum % 2 + '0';
        sum /= 2;
    }
    return output + sizeOutput;
}


int main(void) {    
    char arr1[] = "abcxd";
    char arr2[] = "xabcrpd";
    longest_common_subsequence(arr1, arr2);
    
    return 0;
}