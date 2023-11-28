

// 1. string copy

char *str_cpy(char* des, const char* src) {
    if(src == NULL || des == NULL) {
        return -1;
    }
    char* tmp = des;
    while(*des++ = *src++) {
    }

    return tmp;
}


/*
    2. 
    要解决两个问题：
    其一，一次一个字节效率太低，地址总线一般是32位，能搬运4字节，一次一个肯定慢的不行；
    其二，当内存区域重叠时会出现混乱情况。

    memcpy的库函数，没有考虑内存地址重叠的情况；
    但是memmove函数考虑到了这种情况。
    所以，需要弄清楚是要实现哪一个！！！！！
*/

void* memcpy(void* dst, const void* src, size_t size) { // 注意const, void*
    if(dst == nullptr || src == nullptr) 
        return dst;

    if(src + size > dst) {                         // possible overlap - backward
        char* lastcdst = (char*)dst + size - 1;
        const char* lastcsrc = (const char*)src + size - 1;
        while(size--) {
            *lastcdst-- = *lastcsrc--;
        }   
    } else {                                   // forward
        char* cdst = (char*)dst;
        const char* csrc = (const char*)src;
        while(size--) {
            *cdst++ = *csrc++;
        }
    }
    return dst;
}

// 3. 优化了拷贝速度
// 考虑了拷贝速度，按照cpu的位宽来拷贝。比如32bitcpu, 就按照4个字节一次来拷贝。因为cpu一次能读4个字节
void *Memcpy_ext(void *dest, const void *src, size_t count) {  
    int bytelen = count / sizeof(dest); /*按CPU位宽拷贝*/
    int remain = count % sizeof(dest); /*剩余的按字节拷贝*/
    unsigned int* d = (unsigned int*)dest;  
    unsigned int* s = (unsigned int*)src;  

    if (((int)dest > ((int)src+count)) || (dest < src)) {  
        while (bytelen--)  
            *d++ = *s++;  
        while (remain--)  
            *(char *)d++ = *(char *)s++; 
    } else {   /* overlap重叠 */ 
        d = (unsigned int*)((unsigned int)dest + count - 4); /*指针位置从末端开始，注意偏置 */  
        s = (unsigned int*)((unsigned int)src + count -4);  
        while (bytelen--)  
            *d-- = *s--;
        d++;
        s++;

        char * d1=(char *)d;
        char * s1=(char *)s;
        d1--;
        s1--;
        while (remain--)  
            *(char *)d1-- = *(char *)s1--; 
    }  
    return dest;  
}


// 4. memocpy alignment

void* memcpyAlign(size_t alignment, void* dst, void* src, size_t dstLen, size_t srcLen) {
    // 1. get the newAddress
    //     1. offset = alignment - 1
    //     2. newAddr = dst + offset & ~(offset)
    // 2. memcpy
    // 4. return newAddr

    size_t offset = alignment - 1;
    // size_t newLen = srcLen + offset;
    // size_t* addr = (size_t)malloc(newLen);
    // if(!addr) return nullptr;

    size_t* newAddr = ((size_t*)dst + offset) & ~(offset);
    size_t cpuSize = sizeof(size_t);
    size_t t1 = srcLen / cpuSize;   // cpu size count
    size_t t2 = srcLen % cpuSize;   // remain byte count
    
    size_t* d = (size_t*)dst;
    size_t* s = (size_t*)src;

    for(int i = 0; i < t1; i++) {
        *d++ = *s++;
    }

    d = (size_t*)((size_t)dst + t1 - cpuSize);
    s = (size_t*)((size_t)src + t1 - cpuSize);
    char* d1 = (char*)d;
    char* s1 = (char*)s;
    for(int i = 0; i < t2; i++) {
        *d1++ = *s1++;
    }

    return (void*)newAddr;
}