
#include "test.hpp"

void delExtraSpaces(string& s) {
    int j = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != ' ') {
            if(j != 0) {
                s[j++] = ' ';
            }
            while(i < s.size() && s[i] != ' ') {
                s[j++] = s[i++];
            }
        }
    }
    s.resize(j);

    // cout << "START" << s << "END" << endl;
}

void reverse(string& s, int start, int end) {
    if(s.size() <= 1) {
        return;
    }

    int left = start;
    int right = end;

    while(left < right) {
        swap(s[left++], s[right--]);
    }
}

/*
    show me the money -> money the me show
*/
void reverseWords(string& s) {
    delExtraSpaces(s);
    reverse(s, 0, s.size() - 1);

    int start = 0;
    int end = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') {
            end = i - 1;
            reverse(s, start, end);
            start = i + 1;
        }
    }
    reverse(s, start, s.size() - 1);
}

int calLen(vector<int>& nums) {
    int count = 1;

    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] != nums[i - 1]) {
            nums[count] = nums[i];
            count++;
        }
    }
    nums.resize(count);
    return count;
}

uint32_t getOnes(uint32_t num) {
    int count = 0;

    while(num) {
        num &= (num - 1);
        count++;
    }
    return count;
}

/*  1. 注意const的使用
    2. 注意类型转换

    memory copy: copy all the contents for len
    string copy: copy will stop when meet a '\0'
*/
void* memCpy(void* dest, const void* src, size_t count) {
    char* pDest = static_cast<char*>(dest);     // 强制类型转换 - 编译时期
    const char* pSrc = static_cast<const char*>(src);

    for(size_t i = 0; i < count; ++i) {
        pDest[i] = pSrc[i];
    }
    return dest;
}

int main(void) {
    uint32_t n = 4;
    cout << getOnes(n) << endl;

    // vector<int> nums = {2, 1, 3, 16, 51, 14};
    // test_revers_iterator(nums);

    // string s = "  show   me the    money  ";
    // reverseWords(s);
    // cout << s << endl;
    
    // vector<int> nums{1, 1, 1, 2, 3, 4, 4, 5};
    // cout << calLen(nums) << endl;

    // for(auto x : nums) {
    //     cout << x << " ";
    // }
    // cout << endl;

    //     for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
    //     cout << *it << endl;
    // }

    return 0;
}