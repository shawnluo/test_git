#include "test.hpp"


typedef struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
} listNode, *pListNode;

void showMe(pListNode pHead) {
    while(pHead != nullptr) {
        cout << pHead->val << " ";
        pHead = pHead->next;
    }
    cout << endl;    
}

pListNode createLL(const vector<int> nums) {
    pListNode pHead = nullptr;
    pListNode p = nullptr;
    int index = nums.size() - 1;

    while(index >= 0) {
        p = new ListNode(nums[index--]);
        p->next = pHead;
        pHead = p;
    }
    return pHead;
}

int createLL_2(pListNode& pHead, const vector<int> nums) {
    // pListNode pHead = nullptr;
    pListNode p = nullptr;
    int index = nums.size() - 1;

    while(index >= 0) {
        p = new ListNode(nums[index--]);
        p->next = pHead;
        pHead = p;
    }
    return 0;
}

void delSingleNode(pListNode *ppHead, int data) {
    pListNode *pp = ppHead;
    while(*pp && (*pp)->val != data) {
        pp = &((*pp)->next);
    }
    if(*pp) {
        pListNode tmp = *pp;
        *pp = (*pp)->next;
        delete tmp;
    }
}

// delete all specified elements
void delNodes(pListNode *ppHead, int data) {
    pListNode *pp = ppHead;
    while(*pp) {
        if((*pp)->val == data) {
            pListNode tmp = *pp;
            *pp = (*pp)->next;
            delete tmp;
        } else {
            pp = &((*pp)->next);
        }
    }
}

// delete duplicated elements
void delDupNodes(pListNode *ppHead) {
    pListNode *pp = ppHead;
    while(*pp) {
        delNodes(&(*pp)->next, (*pp)->val);
        pp = &((*pp)->next);
    }
}

void insNodeInfront(pListNode *ppHead, int target, int newData) {
    // 1. find the target address (pp)
    // 2. new a node
    // 3. newNode->next = *pp;
    // 4. *pp = newNode;

    pListNode *pp = ppHead;
    while(*pp && (*pp)->val != target) {
        pListNode newNode = new ListNode(newData);
        newNode->next = *pp;
        *pp = newNode;
    }
}

void insNodeBehind(pListNode pHead, int target, int newData) {
    pListNode p = pHead;
    while(p && p->val != target) {
        pListNode newNode = new ListNode(newData);
        newNode->next = p->next;
        p->next = newNode;
    }
}

void insert(pListNode *ppHead, int val) {
    if(*ppHead == nullptr) {
        *ppHead = new ListNode(val);
        return;
    }
    insert(&((*ppHead)->next), val);
}

void insNodeBehind(pListNode& pHead, int target, int newData) {
    pListNode p = pHead;
    while(p && p->val != target) {
        p = p->next;
    }
    if(p == nullptr) {
        cout << "cannot find it" << endl;
        return;
    }
    pListNode pNew = new ListNode(newData);
    pNew->next = p->next;
    p->next = pNew;
}

int main(void) {
    // vector<int> nums{1, 116, 2, 3, 4, 5, 116, 6, 1, 2, 3, 116};
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8};

    pListNode pHead = nullptr;

    // createLL_2(pHead, nums);
    // showMe(pHead);

    // delNode(&pHead, 4);
    // delDupNodes(&pHead);
    // showMe(pHead);

    for(auto x : nums) {
        insert(&pHead, x);
    }
    showMe(pHead);

    return 0;
}