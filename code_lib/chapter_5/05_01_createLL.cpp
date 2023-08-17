

typedef struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
} listNode, *pListNode;


// 直接返回指针
pListNode createLL(const vector<int> nums) {
    pListNode pHead = nullptr;
    pListNode p = nullptr;
    int index = nums.size() - 1;

    while(index >= 0) {
        p = new ListNode(nums[index--]);
        // 等价于下面三句
        // p = (pListNode)malloc(sizeof(listNode));
        // p->val = nums[index--];
        // p->next = nullptr;

        p->next = pHead;
        pHead = p;
    }
    return pHead;
}


// 一定要用&, 否则pHead返回值不会被改变
int createLL_2(pListNode& pHead, const vector<int> nums) {
    pListNode p = nullptr;
    int index = nums.size() - 1;

    while(index >= 0) {
        p = new ListNode(nums[index--]);
        p->next = pHead;
        pHead = p;
    }
    return 0;
}

int main(void) {
    vector<int> nums{1, 2, 3, 4, 5, 116};
    // int s = 7;

    pListNode pHead = nullptr;
    // pListNode p = new ListNode(41);
    // head->next = p;

    createLL_2(pHead, nums);
    while(pHead != nullptr) {
        cout << pHead->val << " ";
        pHead = pHead->next;
    }
    cout << endl;

    // pListNode pHead = (pListNode)malloc(sizeof(listNode));

    return 0;
}