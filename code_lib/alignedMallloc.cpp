// 1. malloc aligned memory
void *memAlign(size_t size, size_t alignment) {
    // 1. the new length
    size_t offset = alignment - 1;
    size_t newSize = size + offset + sizeof(size_t);

    // 2. malloc
    size_t *addr = (size_t *)malloc(newSize);

    // 3. the newAddr
    size_t *newAddr = (addr + offset) & ~(offset);

    // 4. save the diffencial
    *(newAddr - 1) = newAddr - addr;

    return newAddr;
}

void align_free(void * aligned_addr) {
    void *addr = (size_t *)aligned_addr - *((size_t *)aligned_addr - 1);
    free(addr);
}



// 2. memcpy alignment
//      not optimized for copy speed
void* memcpyAlign(size_t alignment, void* dst, void* src, size_t dstLen, size_t srcLen) {
    // 1. get the alignedAddr newAddr
    size_t offset = alignment - 1;
    size_t* newDst = ((size_t*)dst + offset) & ~(offset);

    // 如果偏移后的剩余长度不足以放下src，那么就返回
    if(dstLen - (newDst - dst) < src) {
        return nullptr;
    }

    // need malloc new address? if yes, then insert alignedMalloc()

    // 2. get the cpu size, then split the copied data into 2 parts. 
    size_t cpuSize = sizeof(size_t);
    size_t t1 = srcLen / cpuSize;   // cpu size count
    size_t t2 = srcLen % cpuSize;   // remain byte count
    
    size_t* d = (size_t*)newDst;
    size_t* s = (size_t*)src;

    for(int i = 0; i < t1; i++) {
        *d++ = *s++;
    }

    d = (size_t*)((size_t)newDst + t1 - cpuSize);
    s = (size_t*)((size_t)src + t1 - cpuSize);
    char* d1 = (char*)d;
    char* s1 = (char*)s;
    for(int i = 0; i < t2; i++) {
        *d1++ = *s1++;
    }

    *(dst - 1) = newDst - (size_t*)dst;

    return (void*)newDst;
}