
#include "test.hpp"

#define SOUND_CTL *(volatile unsigned long*)0x80000000

#define CTL (unsigned long*)0x80000000

int main() {
    vector<int> v = {1, 2, 3, 4};
    auto it = find(v.begin() + 3, v.end(), 3);
    if (it != v.end()) {
        std::cout << "Value 3 found at index: " << std::distance(v.begin(), it) << std::endl;
    } else {
        std::cout << "Value 3 not found in the vector" << std::endl;
    }

    return 0;
}

#define REG *(volatile unsigned long*)0x90000000
void test(unsigned int BIT, unsigned int start, unsigned int end) {
    REG |= (1 << BIT);  // set
    REG &= ~(1 << BIT); // clean

    // mask

    // for loop set bits
    for(int i = start; i < end; i++) {
        REG |= (1 << i);
    }
}

void t(int data, int i, int j, int M, int N) {
    // 1, 000, 000, 000, 000
    // mask: 111100
    // int rhs = 1 << i - 1;
    // int lhs = 1 << j - 1;
    int max = ~0;
    int lhs = max - ((1 << j) - 1);
    int rhs = (1 << i) - 1;
    int mask = lhs | rhs;   // 000 111 000
    N = N & ~(mask);
    N = N | (M << i);
}

bool decialToBin(string s) {
    int pos = s.find('.');
    if(pos == string::npos) {
        intPart = s;
        fraPart = "";
    } else {
        intPart = s.substr(0, pos);
        fraPart = s.substr(pos + 1);
    }

    for(int i = 0; i < intPart.size(); i++) {
        sumInt = sumInt * 2;
        sumInt += intPart[i] - '0';
    }

    for(int i = 0; i < fraPart.size(); i++) {
        sumFra += pow(2, -(fraPart[i + 1] - '0'));
    }
}