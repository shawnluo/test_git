
typedef struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
} listNode, *pListNode;

void showMe(pListNode pHead) {
    while(pHead != nullptr) {
        cout << pHead->val << " ";
        pHead = pHead->next;
    }
    cout << endl;    
}

pListNode createLL(const vector<int> nums) {
    pListNode pHead = nullptr;
    pListNode p = nullptr;
    int index = nums.size() - 1;

    while(index >= 0) {
        p = new ListNode(nums[index--]);
        p->next = pHead;
        pHead = p;
    }
    return pHead;
}

int createLL_2(pListNode& pHead, const vector<int> nums) {
    // pListNode pHead = nullptr;
    pListNode p = nullptr;
    int index = nums.size() - 1;

    while(index >= 0) {
        p = new ListNode(nums[index--]);
        p->next = pHead;
        pHead = p;
    }
    return 0;
}

void delSingleNode(pListNode *ppHead, int data) {
    pListNode *pp = ppHead;
    while(*pp && (*pp)->val != data) {
        pp = &((*pp)->next);
    }
    if(*pp) {
        pListNode tmp = *pp;
        *pp = (*pp)->next;
        delete tmp;
    }
}

// delete all specified elements
void delNodes(pListNode *ppHead, int data) {
    pListNode *pp = ppHead;
    while(*pp) {
        if((*pp)->val == data) {
            pListNode tmp = *pp;
            *pp = (*pp)->next;
            delete tmp;
        } else {
            pp = &((*pp)->next);
        }
    }
}

// delete duplicated elements
void delDupNodes(pListNode *ppHead) {   // 注意，指针只是一个字节的地址单元，跟结构体的物理存储不同 - 没有val和next单元
    pListNode *pp = ppHead;
    while(*pp) {
        delNodes(&(*pp)->next, (*pp)->val);
        pp = &((*pp)->next);
    }
}

int main(void) {
    vector<int> nums{1, 116, 2, 3, 4, 5, 116, 6, 1, 2, 3, 116};

    pListNode pHead = nullptr;

    createLL_2(pHead, nums);
    showMe(pHead);

    // delNode(&pHead, 4);
    delDupNodes(&pHead);
    showMe(pHead);

    return 0;
}