
#include "test.hpp"


void getNext(string& s, vector<int>& next) {
    next[0] = 0;
    int j = 0;
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

int strstr(string s, string sub) {
    vector<int> next(sub.size(), 0);
    getNext(sub, next);

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

bool hasRepeatSub() {
    if(next[sub.size() -1] != 0 && sub.size() % (sub.size() - next[sub.size() - 1]) == 0) {
        return true;    
    }
    return false;
}

// TODO 
// 1. read() call read4(buf4) - done
// 2. memcpy
// 3. bit manipulate -- important
// 4. 1s in interger

#define REG (*((volatile unsigned long*) 0xabcd))

    // 1. set bit
    // 2. clear bit
    // 3. set from i to j
    // 4. clear from i to  j

// set n bits from startBit
void bitSet(int startBit, int n) {
    for(int i = 0; i < n; i++) {
        REG |= 1 << (startBit + i);
    }
}

void bitClear(int startBit, int n) {
    for(int i = 0; i < n; i++) {
        REG &= ~(1 << (i + startBit));
    }
}

void* memcpy(const void* src, void* dest, size_t count) {
    if(dest == nullptr || src == nullptr) return dest;
    unsigned int* d = (unsigned int*) dest;
    unsigned int* s = (unsigned int*) src;

    int byteLen = count / sizeof(dest);
    int remain = count % sizeof(dest);

    if(d < s) {
        while(byteLen--) {
            *d++ = *s++;
        }
        while(remain--) {
            *(char*)d++ = *(char*)s++;
        }
    } else {
        d = (unsigned int*)((unsigned int)dest + count - 4);
        s = (unsigned int*)((unsigned int)src + count - 4);
        while(byteLen--) {
            *d-- = *s--;
        }
        while(remain--) {
            *(char*)d-- = *(char*)s--;
        }
        return dest;
    }
}

int read(char* buf, int n) {
    char buf4[4];
    int readChar = 4;
    int copiedChar = 0;

    while(readChar == 4 && copiedChar < n) {
        readChar = read4(buf4);
        for(int i = 0; i < readChar; i++) {
            if(copiedChar == n) {
                return copiedChar;
            }
            buf[copiedChar++] = buf4[i];
        }
    }
    return copiedChar;
}

int main() {
    string s = "abcdef";
    string sub = "abcabcabc";

    vector<int> next(sub.size(), 0);
    getNext(sub, next);



    // for(auto it : next) {
    //     cout << it << " ";
    // }
    // cout << endl;

    return 0;
}