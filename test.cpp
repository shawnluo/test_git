#include "test.hpp"

#include <functional>
#include <semaphore.h>
#include <stdlib.h>
#include <thread>
using namespace std;


int sum(int a, int b) {
    while (b) {
        int carry = a & b;
        a         = a ^ b;
        b         = carry << 1;
    }
    return a;
}

double binaryFractionToDecimal(const string& s) {
    size_t pos = s.find('.');
    string intPart;
    string fractionPart;

    if(pos == string::npos) {
        intPart = s;
        fractionPart = "";
    } else {
        intPart = s.substr(0, pos);
        fractionPart = s.substr(pos + 1);
    }
    cout << intPart << endl;
    cout << fractionPart << endl;

    // step 1: make a mask which bits [high, low] set to 1
    uint32_t mask = (1 << (high + 1)) - 1;
    mask -= ((1 << low) - 1);
    // cout << bitset<10>(mask) << endl;

    // step 2: set bits by | ~(mask)
    num |= mask;
    cout << bitset<11>(num) << endl;
}

void clearBits(int& num, int high, int low) {
    cout << bitset<11>(num) << endl;

    // step 1: make a mask which bits [high, low] set to 1
    uint32_t mask = (1 << (high + 1)) - 1;
    mask -= ((1 << low) - 1);
    // cout << bitset<11>(mask) << endl;

    // step 2: clear bits by | ~(mask)
    num &= ~(mask);
    cout << bitset<11>(num) << endl;
}

int nOfbits(int a, int b) {
    // unisgned int table[256] = {0, 1, 1, 2, 2, 3...};
}

int getPrev(int n) { return 0; }

int setBit(int n, int index, bool b) {
    if (b == true) {
        n |= (1 << index);
    } else {
        n &= ~(1 << index);
    }
    return n;
    double resInt = 0.0;
    for(int i = 0; i < intPart.size(); i++) {
        if(intPart[i] == '1') {
            // resInt += pow(2.0, intPart.size() - i - 1);
            resInt += 1 << (intPart.size() - i - 1);
        }
    }
    cout << resInt << endl;

    double resFraction = 0.0;
    for(int i = 0; i < fractionPart.size(); i++) {
        if(fractionPart[i] == '1') {
            // resFraction += pow(2.0, -(i + 1));
            resFraction += 1 / (1 << ((i + 1)));
        }
    }
    cout << resFraction << endl;

    return resInt + resFraction;
}

// TODO 1101 next biggest

uint64_t myPow(int base, int n) {
    if(base == 0) return 0;
    if(n == 0) return 1;

    uint64_t res = 1;

    if(n < 0) {
        base = 1 / base;
        n = -n;
    }

    for(int i = 1; i <= n; i++) {
        res = res * base;
    }
    
    return res;
}

bool getBit(int n, int index) { return (n & (1 << index)) > 0; }

// 0,1100 -> 1,1100 -> 1,0100
int getNext(int n) {
    if (n <= 0) return -1;

    int index     = 0;
    int countOnes = 0;
    while (getBit(n, index) == 0) {
        index++;
        countOnes++;
    }
    n = setBit(n, index, true);

    index--;
    n = setBit(n, index, false);

    // set zeros
    for (int i = index; i >= countOnes; i--) {
        n = setBit(n, i, false);
    }

    // set ones
    for (int i = countOnes - 1; i >= 0; i--) {
        n = setBit(n, i, true);
    }

    return n;
}

int setBits(int num, int high, int low, int val) {
    int mask = 0;
    mask     = (1 << high + 1) - 1;
    mask -= ((1 << low) - 1);
    num &= ~mask;
    num |= (val << low);

    return num;
}

string decToBin(string n) {}

int main(void) {
    uint64_t res;
    res = myPow(-100, 1);
    cout << res << endl;

    // string s = "0101.1101";
    // double res = binaryFractionToDecimal(s);
    // cout << res << endl;

    // int a   = 3;
    // int b   = -11;
    // int ret = sum(a, b);
    // cout << ret << endl;

    return 0;
}

int bitConvert(int a, int b) {
    int x   = a ^ b;
    int res = 0;

    while (x) {
        x = x & (x - 1);
        res++;
    }
    return res;
}

int swapOddEvenBits(int x) {
    int a = (x & 0x55555555) << 1;
    int b = (x & 0xaaaaaaaa) >> 1;
    return a | b;
}

int findMissing(vector<int>& array, int column) {
    if (column < 0) return 0;

    vector<int> odd;
    vector<int> eve;

    for (auto it : array) {
        if ((it >> column) && 1) {
            odd.push_back(it);
        } else {
            eve.push_back(it);
        }
    }

    if(odd.size() >= eve.size()) {
        return findMissing(array, column - 1) << 1 | 0;
    } else {
        return findMissing(array, column - 1) << 1 | 1;
    }
}