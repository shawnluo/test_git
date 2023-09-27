#include "test.hpp"

typedef struct node {
    int data;
    struct node* next;
} Node, *pNode;

#define LEN sizeof(Node)


void showMe(pNode pHead) {
    while(pHead) {
        cout << pHead->data << endl;
        pHead = pHead->next;
    }
}

pNode createNode(const vector<int> nums) {
    pNode p = nullptr;
    pNode pHead = nullptr;
    for(int i = nums.size() - 1; i >= 0; i--) {
        p = (pNode)malloc(LEN);
        p->data = nums[i];
        p->next = pHead;
        pHead = p;
    }

    return pHead;
}

void createNode_2(pNode* ppHead, const vector<int> nums) {
    if(*ppHead == NULL) {
        *ppHead = (pNode)malloc(LEN);
    }
    (*ppHead)->data = nums[0];

    pNode pCur = *ppHead;
    pNode pNext = *ppHead;

    for(int i = 1; i < nums.size(); i++) {
        pNext = (pNode)malloc(LEN);
        pNext->data = nums[i];
        pCur->next = pNext;
        pCur = pNext;
    }
}


int main(void) {
    vector<int> nums = {1, 2, 3};
    pNode pHead = createNode(nums);

    showMe(pHead);

    return 0;
}