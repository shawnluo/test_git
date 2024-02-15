
#include "test.hpp"

#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;


#include <iostream>
#include <string>

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

typedef void (*pF)();

void *memcpy(void* dst, const void* src, size_t size) {
    if(!dst || !src) return dst;

    // backward
    if((size_t*)src + size > (size_t*)dst) {
        char* lastcdst = (char*)dst + size - 1;
        const char* lastcsrc = (const char*)src + size - 1;

        while(size--) {
            *lastcdst-- = *lastcsrc++;
        }
    } else {
        char* cdst = (char*)dst;
        const char* csrc = (const char*)csrc;
        while(size--) {
            *cdst++ = *csrc++;
        }
    }
    return dst;
}

void* memcpyAlign(size_t alignment, void* dst, const void* src, size_t dstLen, size_t srcLen) {
    size_t offset = alignment - 1;
    size_t* newDst = ((size_t*)dst + offset) & ~(offset);
    if(dstLen - (newDst - dst) < srcLen) {
        return nullptr;
    }
    memcpy(...);
}

intPart = s.substr(0, pos);
fracPart = s.substr(pos + 1);

double resInt = 0.0;
for(int i = 0; i < intPart.size(); i++) {
    if(intPart[i] == '1') {
        resInt <<= 1;
        resInt += intPart[i] - '0';
    }
}

int64_t myPow(int base, int n) {
    if(base == 0) return 0;
    if(n == 0) return 1;
    if(n < 0) {
        base = 1 / base;
        n = -n;
    }
    uint64_t res = 1.0;
    for(int i = 0; i <= n; i++) {
        res *= base;
    }
    return res;
}

double resFraction = 0.0;
for(int i = 0; i < frac.size(); i++) {
    if(frac[i] =='1') {
        resFra += pow(2.0, -(i + 1));
    }
}

// 50, 16
void* memAlign(size_t size, size_t alignment) {
    // 1. malloc size;
    size_t offset = alignment - 1;
    size_t newSize = size + offset + sizeof(size_t);
    size_t* addr = (size_t*)malloc(newSize);

    // 2. align address
    size_t* newAddr = (addr + offset) & ~(offset);

    // 3. for free()
    *(newAddr - 1) = newAddr - addr;

    return newAddr;
}

void* myFree(void* addr) {
    size_t* realAddr = (size_t*)addr - *((size_t*)addr - 1);
    free(realAddr);
}

int main() {
    run(showMe);

    return 0;
}