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

void delDup(vector<int>& nums) {
    int n = nums.size();
    int j = 1;
    for(int i = 1; i < n; i++) {
        if(nums[i] != nums[i - 1]) {
            nums[j++] = nums[i];
        }
    }
    nums.resize(j);
    for(auto it : nums) {
        cout << it << endl;
    }
}

void delStr(string s) {
    stack<char> st;
    int n = s.size();

    for(int i = 0; i < n; i++) {
        if(st.empty() || s[i] != st.top()) {
            st.push(s[i]);
        } else {
            st.pop();
        }
    }

    string res;
    while(!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }

    reverse(res.begin(), res.end());

    cout << res << endl;
}

int evalRPM(vector<string>& s) {
    stack<long long> st;
    for(int i = 0; i < s.size(); i++) {
        if((s[i] == "+") || (s[i] == "-") || s[i] == "*" || s[i] == "/") {
            long long a = st.top();
            st.pop();
            long long b = st.top();
            st.pop();

            if(s[i] == "+") st.push(a + b);
            if(s[i] == "-") st.push(a - b);
            if(s[i] == "*") st.push(a * b);
            if(s[i] == "/") st.push(a / b);
        } else {
            st.push(stoll(s[i]));
        }
    }
    return st.top();
}

int main() {
    vector<int> nums{1, 1, 2, 2, 3, 4, 5, 6, 6};
    // delDup(nums);
    
    // string s = "abaabax";
    // delStr(s);

    string s = "111";
    long res = stoll(s);
    cout << res << endl;

    return 0;
}