

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


// 一定要用&, 否则pHead返回值不会被改变, 因为修改的是pHead，而不是pHead的指向
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

void insert(pListNode& pHead, int val) {
    if(pHead == nullptr) {
        pHead = new ListNode(val);
        return;
    }
    insert(pHead->next, val);
}

void insertPP(pListNode *ppHead, int val) {
    if(*ppHead == nullptr) {
        *ppHead = new ListNode(val);
        return;
    }
    insertPP(&((*ppHead)->next), val);
}

// append new node
void createLL(pNode pHead, int val) {
    if(pHead == nullptr) {
        pHead = new Node(val);
        return;
    }
    createLL(pHead->next, val);
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

    for(auto x : nums) {
        insert(pHead, x);
        insertPP(&pHead, x);
    }

    return 0;
}