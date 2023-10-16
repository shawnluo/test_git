
#include "test.hpp"

typedef struct node {
    int data;
    struct node* next;
} Node, *pNode;

#define SIZE sizeof(Node)




int main() {
    unordered_set<int> set;
    set.insert(10);
    set.insert(100);

    for(auto it : set) {
        cout << it << endl;
    }

    return 0;
}