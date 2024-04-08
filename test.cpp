#include "test.hpp"

#include <functional>
#include <semaphore.h>
#include <thread>
using namespace std;

typedef struct NODE {
    int data;
    struct NODE* next;

    NODE(int x) : data(x), next(nullptr) {};
    NODE(int x, struct NODE* p) : data(x), next(p) {};
} node, *pNode;

void create(pNode& pHead, vector<int>& v) {
    int n = v.size();
    while(--n >= 0) {
        pNode p = new NODE(v[n]);
        p->next = pHead;
        pHead = p;
    }
}

pNode del_val(pNode& pHead, int val) {
    pNode dummy = new NODE(0, pHead);
    pNode p = dummy;

    while(p && p->next) {
        if(p->next->data == val) {
            pNode tmp = p->next;
            p->next = p->next->next;
            delete tmp;
        } else {
            p = p->next;
        }
    }
    return dummy->next;
}

pNode switchNode(pNode& pHead) {
    pNode dummy = new NODE(0, pHead);
    pNode p0 = dummy;
    pNode p1 = dummy->next;
    pNode p2 = dummy->next->next;
    pNode p3 = dummy->next->next->next;

    while(p0 && p1) {
        p0->next = p2;
        p2->next = p1;
        p1->next = p3;
        p0 = p0->next->next;
    }
}

void showMe(pNode pHead) {
    while(pHead) {
        cout << pHead->data << " ";
        pHead = pHead->next;
    }
    cout << endl;
}

void delNth(pNode& pHead, int n) {

}

bool isAna(string& s, string& t) {
    unordered_map<char, int> map;
    for(auto it : s) {
        map[it]++;
    }
    for(auto it : t) {
        if(map.find(it) != map.end()) {
            map[it]--;
        } else {
            return false;
        }
    }
    for(auto it = map.begin(); it != map.end(); it++) {
        if(it->second != 0) {
            return false;
        }
    }

    return true;
}

vector<int> interSection(vector<int>& v1, vector<int>& v2) {
    unordered_set<int> set(v1.begin(), v1.end());
    vector<int> vRes;
    for(auto it = set.begin(); it != set.end(); it++) {
        if(find(v2.begin(), v2.end(), *it) != v2.end()) {
            vRes.push_back(*it);
        }
    }

    return vRes;
}

int getSum(int n) {
    int res = 0;
    while(n) {
        int mod = n % 10;
        res += (mod * mod);
        n /= 10;
    }
    return res;
}

bool isHappy(int n) {
    // 123 -> 1*1 + 2*2 + 3*3
    vector<int> rep;

    while(1) {
        int sum = getSum(n);
        if(1 == sum) {
            return true;
        }
        if(find(rep.begin(), rep.end(), sum) != rep.end()) {
            return false;
        }
        rep.push_back(sum);
        n = sum;
    }
}

pair<int, int> twoSum(vector<int> nums, int target) {
    vector<int> v;
    unordered_map<int, int> map;

    for(int i = 0; i < nums.size(); i++) {
        auto it = map.find(target - nums[i]);
        if(it != map.end()) {
            return pair<int, int>(i, it->second);
        } else {
            map.insert(pair<int, int>(nums[i], i));
        }
    }
    return {};
}

vector<vector<int>> threeSum(vector<int>& nums) {
    
}

int main(void) {
    cout << getSum(111) << endl;
    // vector<int> v1{1, 2, 3};
    // vector<int> v2{1, 2, 4};
    // vector<int>res = interSection(v1, v2);
    // for(auto it : res) {
    //     cout << it << " ";
    // }
    // cout << endl;
    // string s = "abcd";
    // string t = "cbda";
    // cout << isAna(s, t) << endl;
    // vector<int> v{1, 2, 3, 4, 5, 1, 2, 1};
    // int n = v.size();
    // pNode pHead = nullptr;
    // create(pHead, v);
    // showMe(pHead);

    // del_val(pHead, 2);
    // showMe(pHead);
    // cout << find(v, 312, 0, n - 1) << endl;

    // cout << test(v, 312) << endl;

    // showMe(v);

    return 0;
}