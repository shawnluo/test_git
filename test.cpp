#include "test.hpp"



//TODO
// 1. 字符串转成整数 myAtoi
// 2. 用栈来实现队列
// 3. 去掉string中的多余空格
// 4. hanoi

vector<int> hash_03(vector<int> a, vector<int> b) {
    unordered_set<int> set(b.begin(), b.end());
    unordered_set<int> res;
    for(auto it : a) {
        auto x = set.find(it);
        if(x != set.end()) {
            res.insert(it);
        }
    }
    return vector<int>(res.begin(), res.end());
}

int getSum(int n) {
    int sum = 0;
    
    while(n) {
        sum += pow(n % 10, 2);
        n /= 10;
    }
    return sum;
}

bool isHappyNum(int n) {
    unordered_set<int> set;

    while(1) {
        int sum = getSum(n);
        if(sum == 1) {
            return true;
        }
        if(set.find(sum) != set.end()) {
            return false;
        }
        set.insert(sum);
        n = sum;
    }
}

vector<int> hash_05(vector<int> nums, int target) {
    unordered_map<int, int> map;

    for(int i = 0; i < nums.size(); i++) {
        auto it = map.find(target - nums[i]);
        if(it != map.end()) {
            return {it->second, i};
        }
        map.insert(pair<int, int>(nums[i], i));
    }
    return {};
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
    string s = "showme";
    string sub = "meshwow";
    vector<int> a = {1, 2, 3};
    vector<int> b = {3, 2, 4};

    vector<int> res = hash_03(a, b);
    for(auto it : res) {
        cout << it << " ";
    }
    cout << endl;
    // bt_02(4, 2, 1);

    // for(auto it : res) {
    //     for(auto it_ : it) {
    //         cout << it_ << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}