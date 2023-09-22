
typedef struct Node {
    int data;
    struct Node* next;

    Node(int val) : data(val), next(nullptr) {}
} node, *pNode;


void showMe(pNode p) {
    if(p == nullptr) return;
    while(p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


pNode reverseLL(pNode pHead) {
    if(pHead == nullptr) return pHead;
    if(pHead->next == nullptr) return pHead;

    pNode pPre = nullptr;
    pNode pCur = pHead;
    pNode pNex;

    while(pCur) {
        pNex = pCur->next;
        pCur->next = pPre;
        pPre = pCur;
        pCur = pNex;
    }
    return pPre;
}


int main(void) {
    pNode pHead = new node(0); // or Node(0)
    pNode L1 = new node(1);
    pNode L2 = new node(2);
    pNode L3 = new node(3);
    pHead->next = L1;
    L1->next = L2;
    L2->next = L3;
    showMe(pHead);

    pNode res = reverseLL(pHead);
    showMe(res);

    return 0;
}