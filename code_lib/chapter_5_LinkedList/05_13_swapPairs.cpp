

pListNode swapPairs(pListNode pHead) {
    pListNode pVHead = new ListNode(0);
    pVHead->next = pHead;
    pListNode pCur = pVHead;

    while(pCur->next != nullptr && pCur->next->next != nullptr) {
        pListNode p1 = pCur->next;
        pListNode p2 = pCur->next->next;
        pListNode p3 = pCur->next->next->next;

        pCur->next = p2;
        p2->next = p1;
        p1->next = p3;

        pCur = pCur->next->next;
    }
    return pVHead->next;
}