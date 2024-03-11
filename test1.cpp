
#include "test.hpp"
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>


ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;

    if(l1->val < l2->val) {
        l1->next = merge2Lists(l1->next, l2);
        return l1;
    } else {
        l2->next = merge2Lists(l2->next, l1);
        return l2;
    }
}

void createList(ListNode* list, vector<int>& v, int pos) {
    if(pos == v.size()) return;

    list->next = new ListNode(v[pos]);
    createList(list->next, v, pos + 1);
}

void showMe(ListNode* list) {
    while(list) {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}

int main() {
    ListNode* l1 = new ListNode(0);
    ListNode* l2 = new ListNode(0);

    vector<int> v1{1, 2, 3};
    vector<int> v2{11, 22, 33};
    createList(l1, v1, 0);
    // showMe(l1);

    createList(l2, v2, 0);

    ListNode* list = merge2Lists(l1, l2);
    showMe(list);

    return 0;
}