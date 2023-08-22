#include "test.hpp"



typedef struct BTree {
    int val;
    BTree* left;
    BTree* right;

    BTree(int data) : val(data), left(nullptr), right(nullptr) {}
} bTree;

typedef struct Node {
    int val;
    Node *next;

    Node(int data) : val(data), next(nullptr) {}
} node, *pNode;


pNode swapPairs(pNode pHead) {
    pNode pVHead = new node(0); //set a virtual head
    pVHead->next = pHead;
    pNode pCur = pVHead;

    while(pCur->next) {
        pNode save1 = pCur->next;
        pNode save2 = pCur->next->next->next;

        pCur->next = pCur->next->next;
        pCur->next->next = save1;
        save1->next = save2;

        pCur = pCur->next->next;
    }
    return pVHead->next;
}

void insert(pNode& pHead, int val) {
    if(!pHead) {
        pHead = new Node(val);
        return;
    }
    insert(pHead->next, val);
}

void showMe(pNode pHead) {
    while(pHead) {
        cout << pHead->val << " ";
        pHead = pHead->next;
    }
    cout << endl;
}

int main(void) {
    // vector<int> nums{1, 116, 2, 3, 4, 5, 116, 6, 1, 2, 3, 116};
    vector<int> nums{1, 2, 3, 4, 5, 6};
    int size = nums.size();

    pNode pHead = nullptr;

    for(int i = 0; i < size; i++) {
        insert(pHead, nums[i]);
    }

    showMe(pHead);

    pHead = swapPairs(pHead);
    showMe(pHead);

    return 0;
}