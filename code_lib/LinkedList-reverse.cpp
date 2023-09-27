

pNode reveseLL(pNode pHead) {
    pNode pCur = pHead;
    pNode pPre = nullptr;
    pNode pNext;

    while(pCur) {
        pNext = pCur->next;
        pCur->next = pPre;
        pPre = pCur;
        pCur = pNext;
    }
    return pPre;
}