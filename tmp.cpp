
#include "test.hpp"

// 1. strcpy
char* my_strcpy(char* dst, const char* src) {
    char* p = dst;
    while(*dst = *src) {
        dst++, src++;
    }
    cout << p << endl;
    return p;
}

/* 
    const usage:
        char* p;
        const char* p;  // *p cannot be modified  p[0] = 'x' failed
        char* const p;  // p cannot be modified   p++   failed
 */

#if 0
void test_const() {
    char s[20] = "abc";
    const char* p1 = s;
    p1++;           // ok
    p1[0] = 'x';    // ng

    char* const p2 = s;
    p2++;               // ng
    p2[0] = 'y';     // ok

    // cout << p1[0] << endl;
    cout << p2[0] << endl;
}
#endif

// 2. memcpy
void* myMemcpy(const void* src, void* dst, const size_t len) {
    char* pSrc = (char*)src;
    char* pDst = (char*)dst;
    for(int i = 0; i < len; i++) {
        *pDst++ = *pSrc++;
    }
    return dst;
}

// 3. malloc alignment
void* malloc_align(const void* src, void* dst, size_t len, size_t alignment) {
    /* 
        if aligned, just return? no! why? 
        Yes, we can just return the address. However, to ensure uniformity 
        across the API, we need to modify this function to align with our
        standardized API.    
    */
    size_t offset = alignment - 1;
    size_t newLen = len + offset + sizeof(size_t);
    size_t* addr = (size_t*)malloc(newLen);
    size_t* newAddr = (addr + offset)&(~offset);
    *(newAddr - 1) = newAddr - addr;

    return newAddr;
}

void myFree(const void* addr) {
    size_t diff = *((size_t*)addr - 1);
    size_t* realAddr = (size_t *)addr - diff;

    free(realAddr);
}

// 4. memcpy alignment (not memmove)
void* memcpyAlignment(const void* src, void* dst, size_t len, size_t align) {
    // 1. get new dst address which is aligned
    // if it's aligned, then just copy
    size_t offset = align - 1;
    if(dst % align != 0) {
        size_t* newDst = (dst + align)&(~offset);
    }
    // 2. memory copy
        // 1). wordLoop copy
        // 2). remain bytes copy

    size_t* d_word = newDst;
    size_t* s_word = src;

    size_t count = len / align;
    size_t remainCount = len % align;

    while(count--) {
        *d_word++ = *s_word++;
    }

    char* d_char = (char*)d_word;
    char* s_char = (char*)s_word;
    while(remainCount--) {
        *d_char++ = *s_char++;
    }
    return newDst;
}

// 5. bit manipulate - mask from bit i to bit j
// given n and m
int bitmask(int n, int m, int i, int j) {
    // int left = (1 << (m + 1)) - 1;
    // int right = ()
    int max = ~0;
    int left = max - ((1 << j) - 1);
    int right = ((1 << i) - 1);

    int mask = left | right;

    return (n & mask) | (m << i);
}

int bitmask2(int n, int m, int i, int j) {
    int left = (1 << (j + 1)) - 1;
    int right = (1 << i) - 1;
    int mask = left - right;    // mask is all 1s
    n = n & (~mask);    // for n, mask area all 0s

    return n | (m << i);
}

// 6. add 2 numbers without using plus
// 7. counting ones
// 8. checking number is power of two
// 9. setting or clearing bits
// 10. finding the missing number
// 11. swap 2 number
// ok 12. i2c test application by using c++ virtual function

// 13. blur pix
// read 4

int main(void) {
    // char* src = "abc";
    // char dst[100] = {0};
    // my_strcpy(dst, src);
    // test_const();

    cout << 

    return 0;
}