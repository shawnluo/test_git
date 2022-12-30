#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>

void *alignment_malloc(size_t size, size_t alignment) {
    //1. need add a offset to malloc enough space
    int offset = alignment - 1;
    /*2. malloc enough space: 
        1). original memory
        2). offset
        3). space to save the difference between address and aligned_address
    */
    size_t *address = (size_t *)malloc(size + offset + sizeof(size_t));

    //3. adjust the aligned_address
    void *aligned_address;
    aligned_address = (void *)((size_t)(address + offset) & ~(offset));

    //4. save the difference
    *(size_t *)(aligned_address - 1) = (size_t *)aligned_address - address;

    //5. return it
    return aligned_address;
}

int longest_uniq_character(char *s) {
    int size = strlen(s);
    int longest = 0;
    int hash[size];
    int cur_len = 0;
    int pos = -1;
    int i = 0;

    for(i = 0; i < size; i++) hash[i] = -1;

    for(i = 0; i < size; i++) {
        if(pos < hash[s[i]])  pos = hash[s[i]];

        cur_len = i - pos;
        if(longest < cur_len)   longest = cur_len;

        hash[s[i]] = i;
    }
    return longest;
}


void alignment_free(void *aligned_address) {
    void *address = (size_t *)aligned_address - *((size_t *)aligned_address - 1);
    free(address);
}

void *memory_copy(void *src, void *des, size_t len) {
    assert(src);
    assert(des);
    assert(len);

    if(src == des) return src;

    if(des > src) {
        for(int i = 0; i < len; i++) {
            *(char *)des = *(char *)src;
        }
    } else if(src > des) {
        for(int i = len - 1; i >= 0; i--) {
            *(char *)des = *(char *)src;
        }
    }
    return (void *)des;
}

void *str_cpy(void *src, void *des, size_t len) {

}

int main(void) {
    char *s = "ababcde";
    int size = strlen(s);
    longest_uniq_character(s);

    return 0;
}