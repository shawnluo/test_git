#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef struct NODE{
    int key;
    struct NODE *next;
} node, *pNode;

#define SIZE sizeof(node)

void showme(pNode pHead) {
    while(pHead) {
        printf("%d ", pHead->key);
        pHead = pHead->next;
    }
    printf("\n");
}

void showme_ext(pNode pHead, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", pHead->key);
        pHead = pHead->next;
    }
    printf("\n");
}

int create_LL(int *arr, int size, pNode pHead) {
    assert(arr);
    if(!pHead) return -1;
    
    pHead->key = arr[0];
    pHead->next = NULL;
    pNode p = pHead;
    pNode pNew = pHead;

    for(int i = 1; i < size; i++) {
        pNew = (pNode)malloc(SIZE);
        pNew->key = arr[i];
        pNew->next = NULL;
        p->next = pNew;
        p = pNew;
    }

    return 0;
}

pNode create_LL_2(int *arr, int size) {
    pNode pHead     = NULL;
    pNode p         = NULL;
    pNode pNew      = NULL;
    for(int i = 0; i < size; i++) {
        if(!pHead) {
            pHead = (pNode)malloc(SIZE);
            pHead->key = arr[0];
            pHead->next = NULL;
            p = pHead;
            continue;
        }
        pNew = (pNode)malloc(SIZE);
        pNew->key = arr[i];
        pNew->next = NULL;
        p->next = pNew;
        p = pNew;
    }
    return pHead;
}

pNode create_LL_3(int *arr, int size) {
    pNode pHead = NULL;
    pNode p = NULL;

    for(int i = size - 1; i >= 0; i--) {
        p = (pNode)malloc(SIZE);
        p->key = arr[i];
        p->next = pHead;
        pHead = p;
    }
    return pHead;
}

void Destroy_LL(pNode pHead) {
    pNode p = pHead;
    if(!hasCircular(pHead)) {
        while(pHead) {
            p = pHead->next;
            free(pHead);
            pHead = p;
        }
    } else {

    }
}

pNode reverse_LL(pNode pHead) {
    pNode pPrev = NULL;
    pNode pNext = pHead;
    pNode p = pHead;

    while(pNext) {
        pNext = p->next;
        p->next = pPrev;
        pPrev = p;
        p = pNext;
    }
    return pPrev;
}

pNode reverse_LL_2(pNode pHead) {
    pNode pPrev = NULL;
    pNode pNext = pHead;
    pNode p = pHead;

    while(pNext) {  //! pNext must NOT initilze to NULL. otherwise no loop
        pNext = p->next;
        p->next = pPrev;
        pPrev = p;
        p = pNext;
    }
    return pPrev;
}

pNode del_LL(pNode pHead, int target) {
    pNode p = pHead;
    //pNode pTmp = pHead;
    if(target == pHead->key) {
        pHead = pHead->next;
        free(p);
        return pHead;
    }
    while(p->next && p->next->key != target) {
        p = p->next;
    }
    if(!p) {
        printf("can not find the target!\n");
        return pHead;
    }

    pNode pTmp = p->next;
    p->next = p->next->next;
    free(pTmp);
    return pHead;
}

int del_LL_2(pNode *ppHead, int target) {
    pNode *pp = ppHead;
    while((*pp) && (*pp)->key != target) {
        pp = &((*pp)->next);
    }
    if(!*pp) {
        printf("can NOT find the target!\n");
        return -1;
    }
    pNode pTmp = *pp;
    *pp = (*pp)->next;
    free(pTmp);

    return 0;
}

int ins_LL_behind(pNode pHead, int key, int newKey) {
    pNode p = pHead;
    //find the key
    //save the next
    //malloc a newkey
    //key->next = newKey
    //newKey->next = save;

    while(p && p->key != key) {
        p = p->next;
    }
    if(!p) {
        printf("can NOT find the target!\n");
        return -1;
    }

    pNode save = p->next;
    pNode pNew = (pNode)malloc(SIZE);
    pNew->key = newKey;
    pNew->next = save;
    p->next = pNew;

    return 0;
}

pNode ins_LL_front(pNode pHead, int key, int newKey) {
    assert(pHead);
    pNode p = pHead;
    pNode pSave;
    pNode pNew;
    if(pHead->key == key) {
        p = (pNode)malloc(SIZE);
        p->key = newKey;
        p->next = pHead;

        return p;
    }
    while(p->next && p->next->key != key) {
        p = p->next;
    }
    pSave = p->next;
    pNew = (pNode)malloc(SIZE);
    pNew->key = newKey;
    p->next = pNew;
    pNew->next = pSave;

    return pHead;
}

int ins_LL_front_2(pNode *ppHead, int key, int newKey) {
    assert(*ppHead);
    pNode *pp = ppHead;
    while(*pp && (*pp)->key != key) {
        pp = &((*pp)->next);
    }
    pNode pNew = (pNode)malloc(SIZE);
    pNew->key = newKey;
    pNew->next = *pp;
    *pp = pNew;

    return 0;
}

//make LL tail points to key
pNode create_circular(pNode pHead, int key) {
    pNode pEnd = pHead;
    pNode pKey = pHead;
    while(pEnd->next) {
        pEnd = pEnd->next;
    }
    while(pKey->key != key) {
        pKey = pKey->next;
    }
    pEnd->next = pKey;
    return pHead;
}

//using 2 pointers, p1 move 1 steps, p2 move 2 steps
//if p2 meets p1 && p2 != NULL, then has circular
int hasCircular(pNode pHead) {
    pNode p1 = pHead->next;
    if(p1 == NULL) return 0;
    pNode p2 = pHead->next->next;
    if(p1 == NULL || p2 == NULL) {
        return 0;
    }
    
    while(p1 != NULL && p2 != NULL) {
        if(p1->key == p2->key) return 1;
        p1 = p1->next;
        if(!p1) return 0;

        p2 = p2->next;
        if(!p2) return 0;       //check p2->next
        p2 = p2->next;
        if(!p2) return 0;       //check next p2->next
    }

    return 0;
}

//p1 from 2nd element forwards to the end, 
//  p2 from pHead forwards to the p1.
// if p1->next == p2 then 
int hasCircular_2(pNode pHead) {
    assert(pHead);
    pNode p1 = pHead->next;
    pNode p2 = pHead;
    while(p1 != NULL) {
        p2 = pHead;
        while(p2 != p1) {
            if(p1->next == p2) {
                return 1;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return 0;
}


/*  fast forwards 2 steps everytime
    slow forwards 1 step everytime
    when they meet, fast go back to head, forward 1 step and meet with slow.
    the meet point is the entry
*/
int find_entry_circular(pNode pHead) {
    pNode pFast = pHead->next->next;
    //if(pFast->key == pHead->key)  return pHead->key;
    pNode pSlow = pHead->next;

    while(pFast->key != pSlow->key) {
        pFast = pFast->next->next;
        pSlow = pSlow->next;
    }
    printf("%d\n", pFast->key);
    printf("%d\n", pSlow->key);
    pFast = pHead;
    while(pFast->key != pSlow->key) {
        pFast = pFast->next;
        pSlow = pSlow->next;
    }
    printf("%d\n", pFast->key);

    return 0;
}

pNode append_LL(pNode pHead, int sum) {
    if(pHead == NULL) {
        pHead = (pNode)malloc(SIZE);
        pHead->key = sum;
        pHead->next = NULL;
        return pHead;
    }
    //find the tail, and add it to tail
    pNode p = pHead;
    while(p->next != NULL) {
        p = p->next;
    }
    pNode pNew = (pNode)malloc(SIZE);
    pNew->key= sum;
    pNew->next = NULL;
    p->next = pNew;

    return pHead;
}

pNode add_2_LL(pNode pHead1, pNode pHead2) {
    assert(pHead1);
    assert(pHead2);

    pNode p1 = pHead1;
    pNode p2 = pHead2;
    pNode pNew = NULL;
    int carry = 0;
    int sum = 0;
    while(p1 != NULL || p2 != NULL) {
        if(p1 && p2) {
            sum = p1->key + p2->key + carry;
            if(sum >= 10) {
                sum = sum - 10;
                carry = 1;
            } else {
                carry = 0;
            }
            pNew = append_LL(pNew, sum);
            p1 = p1->next;
            p2 = p2->next;
        } else if(p1) {
            sum = p1->key  + carry;
            if(sum >= 10) {
                sum = sum - 10;
                carry = 1;
            } else {
                carry = 0;
            }
            pNew = append_LL(pNew, sum);
            p1 = p1->next;
        } else {
            sum = p2->key  + carry;
            if(sum >= 10) {
                sum = sum - 10;
                carry = 1;
            } else {
                carry = 0;
            }
            pNew = append_LL(pNew, sum);
            p2 = p2->next;
        }
    }
    if(carry == 1) {
        pNew = append_LL(pNew, 1);
    }

    return pNew;
}

pNode swap_adjacent_LL_value(pNode pHead) {
    //do NOT have circular
    assert(pHead);
    pNode p = pHead;
    while(p->next) {
        int tmp = p->key;
        p->key= p->next->key;
        p->next->key = tmp;
        p = p->next->next;
        if(p == NULL) return pHead;
    }

    return pHead;
    //has circular
    //1. find the entry of circular
    //2. while loop untile entry
    //3. do as without circular
}

int swap_adjacent_LL_memory(pNode *ppHead) {
    assert(*ppHead);
    //without circular
    pNode *pp = ppHead;
    while((*pp)->next) {
        pNode pSave1 = (*pp)->next;
        pNode pSave2 = (*pp)->next->next;
        *pp = pSave2;
        (*pp)->next->next = pSave1;
        pSave1->next = pSave2;
        *pp = pSave1;
    }
    return 0;
}

pNode rm_node_2(pNode pHead, int n) {
    //using 2 pointers, p1 advanced n, then p2 start to move
    pNode p1 = pHead;
    pNode p2 = pHead;
    while(n-- > 0) {
        p1 = p1->next;
    }
    p1 = p1->next;
    while(p1) {
        p2 = p2->next;
        p1 = p1->next;
    }
    pNode pSave = p2->next;
    p2->next = p2->next->next;
    free(pSave);

    return pHead;
}

int isConnected(pNode pHead1, pNode pHead2) {
    pNode pLong = NULL;
    pNode pShort = NULL;
    //1. find which one is longer
    int len1 = len_LL(pHead1);
    int len2 = len_LL(pHead2);
    int delta;

    if(len1 >= len2) {
        pLong = pHead1;
        pShort = pHead2;
        delta = len1 - len2;
    } else {
        pLong = pHead2;
        pShort = pHead1;
        delta = len2 - len1;
    }

    while(delta > 0) {
        pLong = pLong->next;
    }
    while(pLong != NULL && pLong->key != pShort->key) {
        pLong = pLong->next;
    }
    if(pLong) return 1;
    else        return 0;
}

void merge_ll(pNode *ppHead1, pNode *ppHead2) {
    if() {
        return;
    }
    pNode *pp1 = ppHead1;
    pNode *pp2 = ppHead2;

    while(*pp1 || *pp2) {
        if((*pp2)->data <= (*pp1)->data) {
            ins_ll_front(ppHead1, *pp1, *pp2);    //ins *pp2 to *pp1
            pp2 = &((*pp2)->next);
        } else {
            pp1 = &((*pp1)->next);
        }
    }
}

int main(void) {
    int arr1[] = {1, 2, 3, 4, 5};
    size_t size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {9, 8, 6, 1, 8};
    size_t size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    pNode pHead1 = create_LL_3(arr1, size1);
    showme(pHead1);
    //del_LL_2(&pHead, 2);
    //pHead = reverse_LL_2(pHead);
    //ins_LL_front_2(&pHead, 1, 100);
    //pHead = create_circular(pHead, 2);
    //showme(pHead);
    //showme_ext(pHead, 20);
    //int ret = hasCircular_2(pHead);
    //printf("has circular: %d\n", ret);
    //ret = find_entry_circular(pHead);

    pNode pHead2 = NULL;
    pHead2 = create_LL_3(arr2, size2);
    showme(pHead2);

    pNode pHead3 = add_2_LL(pHead1, pHead2);
    showme(pHead3);

    //pNode pHead3 = append_LL(pHead2, 12);
    //showme(pHead3);

    Destroy_LL(pHead1);
    Destroy_LL(pHead2);
    Destroy_LL(pHead3);

    return 0;
}