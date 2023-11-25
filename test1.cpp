
#include "test.hpp"

#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;


#include <iostream>
#include <string>

typedef struct node {
    int val;
    node* next;
    node(int x) : val(x), next(nullptr) {}
} Node, *pNode;

class linkedList {
public:
    pNode createLL(const vector<int>& data) {
        int n = data.size();
        pNode pHead = new node(data[0]);
        pNode p = pHead;
        pNode pNext = nullptr;
        for(int i = 1; i < n; i++) {
            pNext = new node(data[i]);
            p->next = pNext;
            p = pNext;
        }

        return pHead;
    }

    void showMe(pNode pHead) {
        for(; pHead != nullptr; pHead = pHead->next) {
            cout << pHead->val << " ";
        }
        cout << endl;
    }

    pNode removeLL(pNode pHead, int val) {
        pNode dummy = new node(0);
        dummy->next = pHead;

        pNode p = dummy;
        for(; p->next != nullptr; ) {
            if(p->next->val == val) {
                pNode tmp = p->next;
                p->next = p->next->next;
                delete tmp;
            } else {
                p = p->next;
            }
        }
        pHead = dummy->next;
        delete dummy;

        return pHead;
    }

    pNode reverseLL(pNode pHead) {
        pNode pPre = nullptr;
        pNode pCur = pHead;
        pNode pNex = nullptr;

        for(; pCur; ) {
            pNex = pCur->next;
            pCur->next = pPre;
            pPre = pCur;
            pCur = pNex;
        }
        return pPre;
    }

    pNode swapAdj(pNode pHead) {
        pNode pDummy = new node(0);
        pDummy->next = pHead;
        pNode p1 = pHead;
        pNode p2 = pHead->next;
        pNode p3 = pHead->next->next;
        pNode p = pDummy;

        for(; p->next && p->next->next; ) {
            p->next = p2;
            p2->next = p1;
            p1->next = p3;

            p = p->next->next;
            p1 = p->next;
            p2 = p->next->next;
            p3 = p->next->next->next;
        }

        return pDummy->next;
    }
};

int main(void) {
    vector<int> nums = {20, 10, 50, 40, 30, 90, 70, 60, 80, 100};
    // pNode pHead = new node(nums[0]);
    
    linkedList LL;
    pNode pHead = LL.createLL(nums);
    LL.showMe(pHead);

    pHead = LL.removeLL(pHead, 40);
    LL.showMe(pHead);

    // cout << pHead->val << endl;
    // cout << pHead->next->val << endl;


    // _sort(nums);

    // int n = nums.size();

    // std::sort(nums.begin(), nums.end());
    // vector<int> res(std::begin(nums) + 0, begin(nums) + 3);
    // for(auto it : res) {
    //     cout << it << endl;
    // }



    return 0;
}