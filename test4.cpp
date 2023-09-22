#include "test.hpp"


int LenDelRep(vector<int> nums) {
    int len = 1;

    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] != nums[i - 1]) {
            len++;
        }
    }
    return len;
}

int nOf1s(int num) {
    int count = 0;

    while(num) {
        num = num & (num - 1);
        count++;
    }
    return count;
}

void isLittle() {
    int i = 1;
    char x = *(char*)&i;
    if(x == 1) {
        cout << "little" << endl;
    }
}

int longestIc(string s) {
    int pos  = -1;
    int len = 0;
    int hash[256];
    int res = 0;
    for(int i = 0; i < 256; i++) hash[i] = -1;

    for(int i = 0; i < s.size(); i++) {
        pos = max(pos, hash[s[i]]);
        len = i - pos;
        res = max(res, len);
        hash[s[i]] = i;
    }
    return res;
}

void getNext(int *next, string s) {
    next[0] = 0;
    int j = 0;  // 指向
    for(int i = 1; i < s.size(); i++) {
        while(j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        next[i] = j;
    }
}

int myStrstr(string s, string t, int *next) {
    int j = 0;
    getNext(next, t);

    for(int i = 0; i < s.size(); i++) {
        while(j > 0 && s[i] != t[j]) {
            j = next[j - 1];
        }
        if(s[i] == t[j]) {
            j++;
        }
        if(j == t.size()) {
            return i - t.size() + 1;
        }
    }
    return -1;
}

#define REG         *(volatile unsigned long *)0x333000
#define SOUND_CTL   (*(volatile unsigned long *)0x80000000)

REG |= 0x1;



int main(void) {
    // vector<int> arr1 = {1, 1, 4, 6, 9};

    // cout << LenDelRep(arr1) << endl;

    string s = "aabcabbdab";
    cout << longestIc(s) << endl;

    return 0;
}