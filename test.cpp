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

void reverse(string& s, int start, int end) {
    int left = start;
    int right = end;

    while(left < right) {
        swap(s[left], s[right]);
        left++, right--;
    }
}

string reverseStr(string& s, int k) {
    for(int i = 0; i < s.size(); i += (2 * k)) {
        if(i + k <= s.size()) {
            reverse(s, i, i + k);
        } else {
            reverse(s, i, s.size() - 1);
        }
    }
    return s;
}

void removeExtraSpaces(string& s) {
    int slow  = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != ' ') {
            if(slow != 0) {
                s[slow++] = ' ';
            }
            while(i < s.size() && s[i] != ' ') {
                s[slow++] = s[i++];
            }
        }
    }
    s.resize(slow);
}

int partition(int* nums, int start, int end) {
    int left = start - 1;
    int pivot = nums[end];
    for(int right = start; right < end; right++) {
        if(nums[right] < pivot) {
            left++;
            swap(nums[left], nums[right]);
        }
    }
    swap(nums[left + 1], nums[end]);
    return left + 1;
}

void quickSort(int* nums, int start, int end) {
    if(start < end) {
        int pivot;
        pivot = partition(nums, start, end);
        quickSort(nums, start, pivot - 1);
        quickSort(nums, pivot + 1, end);
    }
}

int getOnes(int n) {
    int count = 0;
    while(n) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int xx() {
    return table[n & 0xff] + table[(n >> 8) & 0xff] + table[(n >> 16) & 0xff] + table[(n >> 24) & 0xff];
}

int fre(vector<int>& v) {
    unordered_map<int, int> map;
    for(auto it : v) {
        map[it]++;
    }

    vector<pair<int, int>> mapV(map.begin(), map.end());
    sort(mapV.begin(), mapV.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        return a.second < b.second;
    });
}
cc
TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr) return root;

    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    if(n == 1) return nums[]0;
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[n - 1];
}

int longestUniq(vector<int>& v) {
    // 1. hash[256] -1
    // 2. for i in v
    //  position: max(hash[i], pos)
    // len = i - pos;
    // res = max()
    // 
}

int longestContigousIncreasingSub(v) {
    // dp[i]
    // i: take i, dp[i] is the longest ...
    if(v[i] > v[i - 1]) {
        dp[i] = dp[i - 1] + 1;
        res = max(res, dp[i]);
    }
    return res;
}

for(int i = 1; i < n; i++) {
    for(int j = 0; j < i; j++) {
        if(nums[i] > nums[j]) {
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }
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