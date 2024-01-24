#include "test.hpp"

#include <stdlib.h>
#include <functional>
#include <semaphore.h>
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


int main(void) {
    int num = 2048;
    setBits(num, 4, 2);

    cout << endl;

    num = 2047;
    clearBits(num, 4, 2);

    return 0;
}