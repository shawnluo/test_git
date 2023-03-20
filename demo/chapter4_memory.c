#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>


/*  1. malloc new size;
        1). new_size = size + offset;
        2). offset = base - 1 + sizeof(size_t)
        3). address = malloc(new_size)
    3. what's the return new_address
        1). new_address = (address + offset) & ~(base - 1)
    4. save the difference between address and new_address
        *(new_address - 1) = new_address - address
    5. return new_address
*/
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


void alignment_free(void *aligned_address) {
    void *address = (size_t *)aligned_address - *((size_t *)aligned_address - 1);
    free(address);
}

void *memory_copy(void *src, void *des, size_t len) {
    if(des == NULL || src == NULL) {
        printf("invalid parameters!\n");
        return -1;
    }

    if(src == des) return src;

    if(des > src) {
        for(int i = 0; i < len; i++) {
            *(char *)des = *(char *)src;
        }
    } else if(src < des) {
        for(int i = len - 1; i >= 0; i--) {
            *(char *)des = *(char *)src;
        }
    }
    return (void *)des;
}

char *str_cpy(const char *src, char *des, size_t len) {
    if(src == NULL || des == NULL) {
        return -1;
    }
    char *tmp = des;
    while(*des++ = *src++) {
    }

    return tmp;
}


//[04]
void bin_print(int n) {
    unsigned char *p = (unsigned char *)&n;
    p = p + 3;

    for(int j = 0; j < 4; j++) {
        for(int i = 7; i >= 0; i--) {
            if((*p) & (1 << i)) {
                printf("1");
            } else {
                printf("0");
            }
        }
        p--;
        printf("\n");
    }
}


int main(void) {
    char *s = "ababcde";
    int size = strlen(s);
    longest_uniq_character(s);

    return 0;
}