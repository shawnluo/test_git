

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


//TODO
void insNodeBehind(pListNode pHead, int target, int newData) {
    pListNode p = pHead;
    while(p && p->val != target) {
        pListNode newNode = new ListNode(newData);
        newNode->next = p->next;
        p->next = newNode;
    }
}