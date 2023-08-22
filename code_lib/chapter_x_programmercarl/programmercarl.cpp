#include "test.hpp"


// ----------------------- 1.1
// 1, 3, 5, 9   t = 9

int search(vector<int> nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int mid = 0;

    while(left <= right) {
        mid = (left + right) / 2;
        if(nums[mid] == target) {
            return mid;
        } else if(target < nums[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int do_search(vector<int> nums, int start, int end, int target) {
    if(start > end) {
        return -1;
    }
    int mid = (start + end) / 2;
    if(nums[mid] == target) {
        return mid;
    }
    if(target < nums[mid]) {
        return do_search(nums, start, mid - 1, target);
    } else {
        return do_search(nums, mid + 1, end, target);
    }
}

int searchRe(vector<int> nums, int target) {
    return do_search(nums, 0, nums.size() - 1, target);
}

// ----------------------- 1.2
// 1, 1, 2, 4, 6, 9 ,1    val = 1
int remove(vector<int> nums, int val) {
    int len = nums.size();
    int index = 0;

    for(int i = 0; i < len; i++) {
        if(nums[i] != val) {
            nums[index++] = nums[i];
        }
    }
    return index;
}

// ----------------------- 1.3
vector<int> square(const vector<int> nums) {
    int size = nums.size();
    int left = 0;
    int right = size - 1;
    int newSize = right;
    vector<int> res(size);

    while(left < right) {
        if(nums[left] * nums[left] > nums[right] * nums[right]) {
            res[--newSize] = nums[left] * nums[left];
            left++;
        } else {
            res[-- newSize] = nums[right] * nums[right];
            right--;
        }
    }
    return res;
}

// ----------------------- 1.4
int minSize(vector<int> nums, int s) {
    int left = 0;
    int right = 0;
    int size = nums.size();
    int sum = 0;
    int res = INT_MAX;
    while(right < size) {
        sum += nums[right];
        while(sum >= s) {
            sum -= nums[left];
            left++;
            res = min(res, sum);
        }
        right++;
    }
    if(res == INT_MAX) return 0;

    return res;
}

// ----------------------- 1.5
// TODO
vector<vector<int>> mat(int n) {
    int offset = 1;
    int startX = 0;
    int startY = 0;
    int index = 0;
    int round = n / 2;
    vector<vector<int>> res(n, vector<int>(n, 0));   //?
    vector<vector<int>> res(n, vector<int>(n, 0));
    while(round > 0) {
        int x = startX;
        int y = startY;
        for(; y < n - offset; y++) {
            res[x][y] = index++;
        }
        for(; x < n - offset; x++) {
            res[x][y] = index++;
        }
        for(; y > startY; y--) {
            res[x][y] = index++;
        }
        for(; x > startX; x--) {
            res[x][y] = index++;
        }
        startX++;
        startY++;
        offset++;
        round--;
    }
    if(n % 2) {
        res[n / 2][n / 2] = index;
    }
    return res;
}

// ----------------------- 2.2
void delVal(pNode *ppHead, int val) {
    pNode *pp = ppHead;
    while(*pp) {
        if((*pp)->val != val) {
            pp = (*pp)->next;
        } else {
            pNode tmp = *pp;
            *pp = (*pp)->next;
            delete tmp;
        }
    }
}

// ----------------------- 2.3
int getLL(pNode pHead, int index) {
    if(!pHead) {
        return -1;
    }
    pNode p = pHead;
    int i = 0;
    while(p && i != index) {
        p = p->next;
    }
    if(p) {
        return p->val;
    }
    return -1;
}

void addAtHead(pNode* ppHead, int val) {
    pNode *pp = ppHead;
    pNode pNew = new Node(val);
    pNew->next = *ppHead;
    *pp = pNew;
}

void addAtTail(pNode pHead, int val) {
    pNode p = pHead;
    while(p->next != nullptr) {
        p = p->next;
    }
    pNode pNew = new Node(vak);
    p->next = pNew;
}

void deleteAtIndex(pNode* ppHead, int index) {
    if(!*ppHead) {
        return;
    }
    pNode *pp = ppHead;
    int i = 0;
    while(*pp && i != index) {
        pp = &(*pp)->next;
    }
    if(*pp) {
        pNode tmp = *pp;
        *pp = (*pp)->next;
        delete tmp;
    }
}

// ----------------------- 2.4
pNode reverse(pNode& pHead) {
    pNode pCur = pHead;
    pNode pPre = pHead;
    pNode pNex = nullptr;

    while(pCur) {
        pNex = pCur->next;
        pCur->nex = pPre;
        pPre = pCur;
        pCur = pNex;
    }
    return pPre;
}

// ----------------------- 2.5
pNode swapPairs(pNode& pHead) {
    pNode pVHead = new Node(0);
    pVHead->next = pHead;
    pCur = pVHead;

    while(pCur->next && pCur->next->next) {
        pNode p1 = pCur->next;
        pNode p2 = pCur->next->next;
        pNode p3 = pCur->next->next->next;

        pCur->next = p2;
        p2->next = p1;
        p1->next = p3;

        pCur = pCUr->next->next;
    }
    return pVHead->next;
}

// ----------------------- 2.6
void delNth(pNode& *ppHead, int n) {
    pNode pProb = *ppHead;
    pNode *pp = ppHead;

    for(int i = 0; i < n; i++) {
        pProb = pProb->next;
    }

    while(pProb) {
        pp = &(*pp)->next;
    }
    pNode tmp = *pp;
    *pp = (*pp)->next;
    delete tmp;
}

int main(void) {
    vector<int> nums{1, 3, 5, 9};
    int target = 1;
    int ret = searchRe(nums, target);
    cout << ret << endl;

    return 0;
}