/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    int size = sizeof(struct ListNode);

    // dummy head
    struct ListNode* dummy = (struct ListNode*)malloc(size);
    dummy->next = head;
    struct ListNode* headLocal = dummy;

    for(int i = 0; i < left - 1; i++) {
        headLocal = headLocal->next;
    }

    struct ListNode* tailLocal = headLocal->next;
    struct ListNode* pCur = tailLocal->next;

    // struct ListNode* pPre = tailLocal;
    // struct ListNode* pNext;
    
    for(int i = 0; i < right - left; i++) {
        // pNext = pCur->next;
        // pCur->next = pPre;
        // pPre = pCur;
        // pCur = pNext;
        
        // 把pNext换成tailLocal->next，pPre换成headLocal，就可以了
        tailLocal->next = pCur->next;
        pCur->next = headLocal->next;
        headLocal->next = pCur;
        pCur = tailLocal->next;
    }

    return dummy->next;
}