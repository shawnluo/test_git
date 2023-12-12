#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


void* alignedAlloc(size_t align, size_t size) {
    int offset                  = align - 1; // 16 -> 1111,1111
    int newSize                 = size + offset + sizeof(size_t);
    size_t* addr                = (size_t*)malloc(newSize);
    size_t* newAddr             = (addr + offset) & ~(offset);
    *(newAddr - sizeof(size_t)) = newAddr - addr;

    return (void*)newAddr;
}

void alignedFree() {
    
}