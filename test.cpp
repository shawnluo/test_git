#include <iostream>
#include <exception>
#include <memory>
#include <vector>

// using namespace std;
using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::unique_ptr;
using std::shared_ptr;
using std::weak_ptr;
using std::make_unique;
using std::make_shared;
using std::move;

typedef struct NODE {
    int id;
    struct NODE *next;
} node, *pNode;

#define LEN sizeof(node)

void showMe(pNode pHead) {
    if(!pHead) return;
    while(pHead) {
        cout << pHead->id << " ";
        pHead = pHead->next;
    }
    cout << endl;
}

pNode create_ll(std::vector<int> &v) {
    // for(auto i : v) {
    //     cout << i << " ";
    // }
    // cout << endl;
    auto size = v.size();

    pNode pHead = NULL, pCur = NULL, pNext = NULL;
    if(pHead == NULL) {
        pHead = (pNode)malloc(LEN);
        if(!pHead) {
            perror("malloc failed!");
            return (pNode)NULL;
        }
        pHead->id = v[0];
        pHead->next = NULL;
    }
    pCur = pHead;
    pNext = pHead;
    for(auto i = 1; i < size; i++) {
        pNext = (pNode)malloc(LEN);
        if(!pNext) {
            perror("malloc failed!");
            return (pNode)NULL;
        }

        pNext->id = v[i];
        pNext->next = NULL;

        pCur->next = pNext;
        pCur = pNext;
    }

    // showMe(pHead);

    return pHead;
}

pNode create_ll_ext(std::vector<int> &v) {
    pNode pHead = NULL, p = NULL;
    // cout << v.size() << endl;
    for(int i = v.size() - 1; i >= 0; i--) {    // be carefull! using "auto" may cause infinty loop problem!
        p = (pNode)malloc(LEN);
        // cout << v[i] << endl;
        p->id = v[i];
        p->next = pHead;
        pHead = p;
    }
    return pHead;
}

pNode insert_ll_front(pNode *ppHead, int target, int new_value) {

}

pNode insert_ll_behind() {

}

pNode reverse_ll() {

}

pNode swap_injacent() {

}

pNode has_circular() {

}

pNode find_circular_entry() {

}

pNode add_ll(pNode pHead1, pNode pHead2) {

}

void test(std::vector<int>& v) {
    for(auto i : v) {
        cout << i << endl;
    }
}

int main(void) {
    std::vector<int> v;
    for(auto i = 0; i < 5; i++) {
        // v[i] = i;
        v.push_back(i);
    }

    // for(auto i : v) {
    //     cout << i << " ";
    // }
    // cout << endl;

    pNode pHead = create_ll_ext(v);
    showMe(pHead);

    return 0;
}