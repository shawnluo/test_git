
#include "test.hpp"


// TODO 1
void delDup(vector<int>& nums) {
    // unordered_set<int> set;
    int size = nums.size();
    int pos = 1;

    for(int i = 1; i < size; i++) {
        int j;
        for(j = 0; j < i; j++) {
            if(nums[i] == nums[j]) {
                break;
            }
        }
        if(j == i) {
            nums[pos++] = nums[i];
        }
    }
    nums.resize(pos);
    
    for(auto it : nums) {
        cout << it << endl;
    }
}

void delAdjacentDup(vector<int>& nums) {
    int count = 1;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] != nums[i - 1]) {
            nums[count++] = nums[i];
            // count++;
        }
    }
    nums.resize(count);
    for(auto it : nums) {
        cout << it << endl;
    }
}

// TODO 2
void delExtraSpaces(string& s) {
    int size = s.size();
    int j = 0;
    for(int i = 0; i < size; i++) {
        if(s[i] != ' ') {
            if(j > 0) {
                s[j++] = ' ';
            }
        }
        while(i < size && s[i] != ' ') {
            s[j++] = s[i++];
        }
    }
    s.resize(j);
}

// TODO 3
int longestUniqString(string s) {
    int hash[256];
    for(int i = 0; i < 256; i++) {
        hash[i] = -1;
    }

    int size = s.size();
    int pos = -1;
    int len = 0;
    int res = 0;
    int lhs = 0;
    int rhs = 0;

    for(int i = 0; i < size; i++) {
        pos = max(pos, hash[s[i]]);
        lhs = pos + 1;
        len = i - pos;
        rhs = i;
        if(len > res) {
            lhs = pos + 1;
            res = len;
            rhs = i;
        }
        hash[s[i]] = i;
    }

    cout << s.substr(lhs, rhs) << endl;
    
    return res;
}

// TODO 4 - leetcode 209. 正整数数组中，长度最小的子数组
int shortestArr(vector<int> nums, int k) {
    int lhs = 0;
    int size = nums.size();
    int sum = 0;
    int res = INT_MAX;

    for(int rhs = 0; rhs < size; rhs++) {
        sum += nums[rhs];
        while(lhs < size && sum >= k) {
            len = rhs - lhs + 1;
            res = max(res, len);
            sum -= nums[lhs++];
        }
    }
    return res == INT_MAX ? 0 : res;
}


// TODO 5 - myStrtok
char* myStrtok(char* hay, const char needle) {
    static char* input = nullptr;
    if(hay != nullptr) {
        input = hay;
    }
    if(input == nullptr) {
        return nullptr;
    }

    char* res = (char*)malloc(sizeof(char) * 20);
    int i = 0;
    for(; input[i] != '\0'; i++) {
        if(input[i] != needle) {
            res[i] = input[i];
        } else {
            res[i] = '\0';
            input  = input + i + 1;
            return res;
        }
    }
    res[i] = '\0';
    input = nullptr;

    return res;
}

int main(void) {
    string s = "abacadex";
    cout << longestUniqString(s) << endl;

    // string s = "   ab c  d   ";
    // delExtraSpaces(s);
    // cout << "pp" << s << "pp" << endl;

    // vector<int> nums{1, 1, 2, 2, 1, 3};
    // delDup(nums);

    // vector<int> nums{1, 1, 2, 2, 3, 3, 4};
    // delAdjacentDup(nums);

    return 0;
}