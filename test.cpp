


#include "test.hpp"
#include <thread>

using namespace std;


binaryToDecimal() {
    for(int i = 0; i < size; i++) {
        if(intergerPart[i] == '1') {
            decimalInter += pow(2.0, size - i - 1);
        }
        decimalFraction += pow(2.0, -(i + 1));
    }
}



bool isSub(string& s, string& sub) {
    int size = sub.size();
    int next[size];
    getNext(sub, next);

    for() {
        
    }
}

string intToRoman(int num) {
    // 1. divide by M, untile mode == 1
    // 2. divide by D, untile mod == 1
    // ...

    string res;
    vector<pair<string, int>> v = { { "I", 1 }, { "IV", 4 }, { "V", 5 }, { "IX", 9 }, { "X", 10 }, { "XL", 40 },
        { "L", 50 }, { "XC", 90 }, { "C", 100 }, { "CD", 400 }, { "D", 500 }, { "CM", 900 }, { "M", 1000 } };

    for (int i = 12; i >= 0; i--) {
        for (; num >= v[i].second;) {
            cout << "i = " << i << "\t" << num << endl;
            res.append(v[i].first);
            num -= v[i].second;
        }
    }

    // cout << res << endl;
    return res;
}

/*
public int romanToInt(String s) {
    int res=0;
    for(int i=0;i<s.length();i++){
        char c = s.charAt(i);
        if (c == 'I') {
            if (i + 1 < s.length() && s.charAt(i + 1) == 'V') {
                res += 4;
                i++;
            } else if (i + 1 < s.length() && s.charAt(i + 1) == 'X') {
                res += 9;
                i++;
            } else
                res += 1;
        } else if (c == 'X') {
            if (i + 1 < s.length() && s.charAt(i + 1) == 'L') {
                res += 40;
                i++;
            } else if (i + 1 < s.length() && s.charAt(i + 1) == 'C') {
                res += 90;
                i++;
            } else
                res += 10;
        } else if (c == 'C') {
            if (i + 1 < s.length() && s.charAt(i + 1) == 'D') {
                res += 400;
                i++;
            } else if (i + 1 < s.length() && s.charAt(i + 1) == 'M') {
                res += 900;
                i++;
            } else
                res += 100;
        } else if (c == 'V')
            res += 5;
        else if (c == 'L')
            res += 50;
        else if (c == 'D')
            res += 500;
        else if (c == 'M')
            res += 1000;
    }
    return res;
}
*/

int RomanToInt(string s) {
    // vector<pair<string, int>> v = {{"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9}, {"X", 10}, {"XL", 40}, {"L", 50}, \
    //                                 {"XC", 90}, {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000}};

    // vector<pair<char, int>> v = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, \
    //                                 {'C', 100}, {'D', 500}, {'M', 1000}};

    map<char, int> Map =  {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    // cout << Map['X'] << endl;
    int res = 0;
    int nS = s.size();
    int nM = Map.size();

    // for(int i = nV - 1; i >= 0; ) {
    for(int j = 0; j < nS; j++) {
        if(s[j] < s[j + 1]) {
            res -= Map[s[j]];
        } else {
            res += Map[s[j]];
        }
    }

    return res;
}

int main(void) {
    // cout << intToRoman(1994) << endl;
    cout << RomanToInt("CCC") << endl;

    return 0;
}

void* alignedAlloc(size_t align, size_t size) {
    int offset = align - 1;     // 16 -> 1111,1111
    int newSize = size + offset + sizeof(size_t);
    size_t* addr = (size_t*)malloc(newSize);
    size_t* newAddr = addr & ~(offset);
}


int myRead(int n, char* buf) {
    int readChar = 4;
    int copiedChar = 0;

    for(; readChar == 4; ) {
        readChar = read4(buf4);
        for(int i = 0; i < 4; i++) {
            if(copiedChar == n) {
                return copiedChar;            
            }
            buf[copiedChar++] = buf4[i];
        }
    }
    return copiedChar;
}

int cal(char* s) {
    char operation = '+';
    long long num = 0;

    while(*s) {
        if(isdigit(*s)) {
            num = num * 10 + *s - '0';
        }
        if((!isdigit(*s) && !isspace(*s)) || *(s + 1) == '\0') {
            switch(operation) {
                case '+':
                    push(num);
                    break;
                case '-':
                    push(-num);
                    break;
                case '*':
                    push(pop() * num);
                    break;
                case '/':
                    push(pop() / num);
                    break;
            }
            operation = *s;
            curNum = 0;
        }
        s++;
    }
    int res = 0;
    while(!isEmtpy()) {
        res += pop();
    }
    return res;
}