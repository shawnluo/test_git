#include "test.hpp"

#include <functional>
#include <semaphore.h>
#include <stdlib.h>
#include <thread>
using namespace std;


#define REG(addr) (*(volatile uint32_t*)(addr))


// from [n, m]] bits, set to 1
void setBits(int& num, int high, int low) {
    cout << bitset<11>(num) << endl;

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
    int num = 2048;
    setBits(num, 4, 2);

    cout << endl;

    num = 2047;
    clearBits(num, 4, 2);

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