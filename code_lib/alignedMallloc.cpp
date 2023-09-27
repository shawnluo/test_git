// malloc aligned memory
void *memAlign(size_t size, size_t alignment) {
    // 1. the new length
    int offset = alignment - 1;
    int newSize = size + offset + sizeof(size_t);
    // 2. malloc
    size_t *addr = (size_t *)malloc(newSize);
    // 3. the newAddr
    void *newAddr = (void *)((size_t)(addr + offset) & ~(offset));

    // 4. save the diffencial
    *(size_t *)(newAddr - 1) = (size_t *)newAddr - addr;

    return newAddr;
}

void align_free(void * aligned_addr) {
    void *addr = (size_t *)aligned_addr - *((size_t *)aligned_addr - 1);
    free(addr);
}
