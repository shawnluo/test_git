#include "test.hpp"

#include <functional>
#include <semaphore.h>
#include <thread>
using namespace std;

typedef struct NODE {
    int val;
    NODE* next;
    NODE(int x) : val(x), next(nullptr) {}
} ListNode, *pListNode;

// input: pListNode head
// output: pListNode head
/* 
    using dummyhead to handle head swap issue.
    p1 = head->next;
    p2 = head->next->next;
    p3 = head->next->next->next;
    
    head -> p1 -> p2 -> p3
    head -> p2
    p2 -> p1
    p1 -> p3
    head = head->next->next
 */
ListNode* swapPairs(ListNode* head) {
    pListNode pDummy = new NODE(0);
    pDummy->next = head;
    pListNode pCur = pDummy;

    for(; pCur && pCur->next && pCur->next->next; ) {
        pListNode p1 = pCur->next;
        pListNode p2 = pCur->next->next;
        pListNode p3 = pCur->next->next->next;

        pCur->next = p2;
        p2->next = p1;
        p1->next = p3;

        pCur = pCur->next->next;
    }

    return pDummy->next;
}

pListNode create(vector<int>& nums) {
    pListNode pHead = new NODE(nums[0]);
    pListNode pCur = pHead;
    pListNode pNext;

    for(int i = 1; i < nums.size(); i++) {
        pNext = new NODE(nums[i]);
        pCur->next = pNext;
        pCur = pNext;
    }
    return pHead;
}

void showMe(pListNode& pHead) {
    pListNode p = pHead;
    while(p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

pListNode findCircle(pListNode pHead) {
    pListNode pFast = pHead->next->next;
    pListNode pSlow = pHead->next;

    while(pFast && pSlow && pFast != pSlow) {
        pFast = pFast->next->next;
        pSlow = pSlow->next;
    }
    if(pFast == nullptr || pSlow == nullptr) {
        return nullptr;
    }
    string s = "abc";
    unordered_map<char, int> uMap;
    for(auto it : s) {
        uMap[it]++;
    }

    for(auto it : uMap) {
        it.second--;
    }
    for(auto it = uMap.begin(); it != uMap.end(); it++) {
        it->second = 0;
    }
}

class myComp {
public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second > rhs.second;
    }
    myComp(int num, int data) : n(num), val(data){
        for(int i = 0; i < num; i++) {
            rates[i] = val;
        }
    }
    myComp(const myComp& original) {
        val = original.val;
        for(int i = 0; i < original.n; i++) {
            rates[i] = original.rates[i];
        }
    }

    ~myComp() {
        delete[] rates;
        rates = nullptr;
    }

private:
    int n;
    int val;
    int *rates;
};
void sortByFreq(v) {
    // 1. map <int, int>
    // 2. priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> pq;
}

unordered_map<char, int> uMap;
for(auto it : s) {
    uMap[it]++;
}

for(auto it : t) {
    uMap[it]--;
}
for(auto it : uMap) {
    it.second
}

v = {1, 2, 3, 6, 9};
target = 22;
unordered_map<int, int> uMap;   // first: number, sec: position
for(int i = 0; i < n; i++) {
    auto it = uMap.find(target - nums[i]);
    if(it != uMap.end()) {
        return {i, it->second};
    }
    uMap[nums[i]] = i;
}
return {};

vector<int> interSection(v1, v2) {
    unordered_set<int> res;
    unordered_set<int> nSet(v1.begin(), v1.end());
    for(auto it : v2) {
        if(nSet.find(it) != nSet.end()) {
            res.insert(it);
        }
    }
}


// nums = {2, 3, 5},  target = 8, return indices
vector<int> twoSum(vector<int>& nums, int target) {
    // 1. unordered_map to save num and index
    unordered_map<int, int>uMap;

    // 2. loop travel in nums, if find diff in map, then return indices
    for(int i = 0; i < nums.size(); i++) {
        auto x = uMap.find(target - nums[i]);
        if(x != uMap.end()) {
            return {i, x->second};
        }
        uMap.insert({nums[i], i});
    }
    return {};
    //      else push element into 
}

// 19: 1 * 1 + 9 * 9 = 82
// 8 * 8 + 2 * 2 = 68
// 6 * 6 + 8 * 8 = 100
// 1 * 1 + 0 * 0 + 0 * 0 = 1

// 2 
// 2 * 2 = 4
/* 
    4 * 4 = 16
    1 + 36 = 37
    9 + 49 = 58
    25 + 64 = 99
    81 + 81 = 162
    1 + 36 + 4 = 41
    16 + 2 = 18
    1 + 64 = 65
    36 + 25 = 61
    36 + 2 = 38
    9 + 64 = 73
    49 + 9 = 58
 */

int getSum(int n) {
    int sum = 0;
    for(; n != 0; ) {
        int x = n % 10;
        x *= x;
        n /= 10;
        sum += x;
    }
    return sum;
}

bool isHappy(int n) {
    // 1. unordered_set<int> uSet
    unordered_set<int> uSet;
    // 2. save sum of digits to uSet
    while(1) {
        int sum = getSum(n);
        if(sum == 1) {
            return true;
        }
        if(uSet.find(sum) != uSet.end()) {
            return false;
        }
    }
    // 3. if find repeat then return false
}

// TODO
/* 
    1. reverse str
    2. string to decimal
    3. decimal to string
 */

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {11, 0, 22, 3, 4, 5};
    pListNode pHead1 = create(nums1);
    pListNode pHead2 = create(nums2);



    // showMe(pHead);

    // pHead = swapPairs(pHead);
    // showMe(pHead);

    return 0;
}