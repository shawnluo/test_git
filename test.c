#include "common.h"
#include "test.h"



//TODO chapter 5
create() {
    pNode pHead = NULL;
    while(size--) {
        p = (pNode)malloc(LEN);
        p->data = nums[size];
        p->next = pHead;
        pHead = p;
    }
}

create2() {
    if(pHead == NULL) {
        p = (pNode)malloc(LEN);
        p->data = nums[0];
        p->next = NULL:
        pNext = pHead;
    }
    pNew = pHead;
    for(i = 1; i < size; i++) {
        p = (pNode)malloc(LEN);
        p->data = nums[i];
        p->next = NULL;
        pNext->next = p;
        pNext = p;
    }
}

//TODO chapter 6

#define REG *(volatile unsigned int *)0x55000000
REG | 0x1
for(i = 0; i < 8; i++) {
    REG |= (1 << i);
    REG &= ~(1 << i);
}

int min(int x, int y) {
    return x < y ? x : y;
}

void shortest_sum(int nums[], int size, int key) {
    int left, right, sum = 0;
    int len = 0;
    int len_min = INT_MIN;
    int hash[256] = {0};
    for(right = 0; right < size; right) {
        sum += nums[right];

        while(left < right && sum >= key) {
            len = right - left + 1;
            len_min = min(len_min, len);
            sum -= nums[left++];
        }
    }
}

int dataType(void) {
    printf( "Size of C data types:\n\n"                                 );
    printf( "Type               Bytes\n\n"                             );
    printf( "--------------------------------\n");
    printf( "char                 %lu\n" , sizeof( char )               );
    printf( "int8_t               %lu\n" , sizeof( int8_t )             );
    printf( "unsigned char        %lu\n" , sizeof( unsigned char )      );
    printf( "uint8_t              %lu\n" , sizeof( uint8_t )            );
    printf( "short                %lu\n" , sizeof( short )              );
    printf( "int16_t              %lu\n" , sizeof( int16_t )            );
    printf( "uint16t              %lu\n" , sizeof( uint16_t )           );
    printf( "int                  %lu\n" , sizeof( int )                );
    printf( "unsigned             %lu\n" , sizeof( unsigned )           );
    printf( "long                 %lu\n" , sizeof( long )               );
    printf( "unsigned long        %lu\n" , sizeof( unsigned long )      );
    printf( "int32_t              %lu\n" , sizeof( int32_t )            );
    printf( "uint32_t             %lu\n" , sizeof( uint32_t )           );
    printf( "long long            %lu\n" , sizeof( long long )          );
    printf( "int64_t              %lu\n" , sizeof( int64_t )            );
    printf( "unsigned long long   %lu\n" , sizeof( unsigned long long ) );
    printf( "uint64_t             %lu\n" , sizeof( uint64_t )           );
    printf( "float                %lu\n" , sizeof( float )              );
    printf( "double               %lu\n" , sizeof( double )             );
    printf( "long double          %lu\n" , sizeof( long double )        );
    printf( "_Bool                %lu\n" , sizeof( _Bool )              );
    printf( "\n" );
    return 0;
}


pNode ins_front(pNode *ppHed, int des, int newData) {
    if(*ppHead == NULL) {
        return -1;
    }
    pNode *pp = ppHead;
    while(*pp && (*pp)->data != des) {
        pp = &(*pp)->next;
    }
    if(*pp == NULL) return NULL;

    pNode tmp = (pNode)malloc(LEN);
    tmp->data = newData;
    tmp->next = *pp;
    *pp = tmp;
}


// 1 2 3 -> 1 3 2

void swap_adjacent() {
    pNode pHead;
    //save ll_2 to pos
    //p->next = ll_3
    //insert 2 behind 3

}


int main(void) {
    //char s[] = "abc";
    //find_anagrams("xvabc", "av");
    
    return 0;
}