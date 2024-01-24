#include "test.hpp"

#include <functional>
#include <semaphore.h>
#include <thread>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* p = dummy;
        for(; p->next != nullptr; ) {
            if(p->next->val == val) {
                ListNode* tmp = p->next;
                p->next = p->next->next;
                delete tmp;
            } else {
                p = p->next;
            }
        }
        this->head = dummy->next;
        return dummy->next;
    }

    void showMe();
    int get(int index);
    ListNode* addAtHead(int val);
    ListNode* addAtTail(int val);
    ListNode* addAtIndex(ListNode* index, int val);
    ListNode* deleteAtHead(int val);

private:
    ListNode* head;
};

void Solution::showMe() {
    ListNode* p = this->head;
    while(p) {
        cout << p->val << endl;
        p = p->next;
    }
}

int Solution::get(int index) {
    
    return 0;
}

int main(void) {
    ListNode* p4 =  new ListNode(4);
    ListNode* p3 =  new ListNode(3, p4);
    ListNode* p2 =  new ListNode(2, p3);
    ListNode* p12 =  new ListNode(4, p2);
    ListNode* p1 =  new ListNode(1, p12);
    ListNode* head = new ListNode(0, p1);

    Solution so;
    head = so.removeElements(head, 4);

    so.showMe();

    return 0;
}