
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

int meetingRoom(vector<vector<int>> nums) {
    int room = 0;
    vector<int> start;
    vector<int> end;
    for(auto x : nums) {
        start.push_back(x[0]);
        end.push_back(x[1]);
    }
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int size = nums.size();
    int pEnd = 0;
    for(int pStart = 0; pStart < size; pStart++) {
        if(pStart == 0 || start[pStart] < end[pEnd]) {
            room++;
        } else {
            pEnd++;
        }
    }
    return room;
}

int longest_u(string s) {
    int hash[256];
    int len = 0;
    int pos = -1;
    int res = 0;
    for(int i = 0; i < 256; i++) {
        hash[i] = -1;
    }

    for(int i = 0; i < 256; i++) {
        // cout << hash[i] << " ";
    }
    
    for(int i = 0; i < s.size(); i++) {
        pos = max(pos, hash[s[i]]);
        len = i - pos;
        res = max(res, len);
        hash[s[i]] = i;
    }
    return res;
}

int myRead(char* buf, int n) {
    int readChar = 4;
    char buf4[4];
    int count = 0;
    
    while(readChar == 4 && cout < n) {
        readChar = read4(buf4);
        for(int i = 0; i < readChar; i++) {
            if(count == n) {
                return count;
            }
            buf[count++] = buf4[i];
        }
    }

    return count;
}

bool isRect(vector<vector<int>> nums) {
    // 6 lines len
    // sort
    // if long * long == short * short + shorter * shorter; return true;
    // else return false;
}

void permu(string s, int pos) {
    if(pos == s.size()) {
        cout << s << endl;
        return;
    }
    for(int i = pos; i < s.size(); i++) {
        swap(s[i], s[pos]);
        permu(s, pos + 1);
        swap(s[i], s[pos]);
    }
}

void bt(int n, int k, int pos) {
    if(buf.size() == k) {
        res.push_back(buf);
        return;
    }
    for(int i = 1; i <= n; i++) {
        buf.push_back(i);
        bt(n, k, i + 1);
        buf.pop();
    }
}

int main(void) {
    string s = "abcada";
    cout << longest_u(s) << endl;
    // vector<vector<int>> nums = {{1, 3}, {2, 6}, {7, 9}};
    // cout << meetingRoom(nums) << endl;
    // uint32_t n = 4;
    // cout << getOnes(n) << endl;

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