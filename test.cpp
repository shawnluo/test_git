#include "test.hpp"

void getNext(int* next, string s) {
    next[0] = 0;
    int j = 0;

    for(int i = 1; i < s.size(); i++) {
        while(j > 0 && s[i] != s[j]) {
            j = s[j - 1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        s[i] = j;
    }
}

// return the sub start pos in s, if it's existed, then return -1
int kmp(string s, string sub) {
    int next[sub.size()];

    int j = 0;
    for(int i = 0; i < s.size(); i++) {
        while(j > 0 && s[i] != sub[j]) {
            j = next[j - 1];
        }
        if(s[i] == sub[j]) {
            j++;
        }
        if(j == sub.size()) {
            return i - sub.size() + 1;
        }
    }
    return -1;
}

void* alignedMalloc(size_t size, size_t alignment) {
    size_t offset = alignment - 1;
    size_t newSize = size + offset + sizeof(size_t);
    void* addr = (void*)malloc(newSize);
    void* alignedAddr = (size_t *)addr & ~(offset);
    *((size_t *)alignedAddr - 1) = (size_t *)alignedAddr - (size_t*)addr;

    return alignedAddr;
}



vector<int> hash(vector<int> nums, int target) {
    unordered_map<int, int> map;

    for(int i = 0; i < nums.size(); i++) {
        auto it = map.find(target);
        if(it != map.end()) {
            return {it->second, i};
        }
        map.insert(pair<int, int>(nums[i], i));
    }
    return {};
}

int hash_06(vector<int> a, vector<int> b, vector<int> c, vector<int> d) {
    unordered_map<int, int> map;
    int count = 0;

    for(auto i : a) {
        for(auto j : b) {
            map[i + j]++;
        }
    }

    for(auto i : c) {
        for(auto j : d) {
            if(map.find(0 - i - j) != map.end()) {
                count += map[0 - i - j];
            }
        }
    }
    return count;
}

int hash_07(string ransom, string mag) {
    unordered_map<char, int> map;
    for(int i = 0; i < mag.size(); i++) {
        map[mag[i]]++;
    }
    for(int i = 0; i < ransom.size(); i++) {
        if(--map[ransom[i]] < 0) {
            return false;
        }
    }
    return true;
}

// -4, -1, -1, -1, 2
int sumOfThree(vector<int> nums) {
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] > 0) return res;

        if(i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int left = i + 1;
        int right = nums.size() - 1;
        while(left < right) {
            res.push_back(vector<int>{nums[i], nums[left], nums[right]});
            if(nums[i] + nums[left] + nums[right] > 0) {
                right--;
            } else if(nums[i] + nums[left] + nums[right] < 0) {
                left++;
            } else {
                while(left < right && nums[right] == nums[right - 1]) right--;
                while(left < right && nums[left] == nums[left + 1]) left++;
                right--;
                left++;
            }
        }
    }
    return res;
}

bool isValid(string s) {
    if(s.size() % 2) return false;

    stack<char> st;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            st.push(')');
        } else if(s[i] == '{') {
            st.push('}');
        } else if(s[i] == '[') {
            st.push(']');
        } else if(st.emplty() || st.top() != s[i]) {
            return false;
        } else {
            st.pop();
        }
    }
    return st.empty();
}

int main(void) {
    test();
    // vector<int> arr = {1, 6, 4, 2, 3, 5, 7};
    // quickSort(arr, 0, arr.size() - 1);
    // for(auto x : arr) {
    //     cout << x << " ";
    // }
    // cout << endl;

    return 0;
}