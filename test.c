#include "common.h"
#include "test.h"

void move(char x, char y) {
    printf("%c --> %c\n", x, y);
}

//move n plates, from one to three, by using two as a buffer
void hanoi(int n, char one, char two, char three) {
    if (n == 1) {
        move(one, three);
    } else {
        hanoi(n - 1, one, three, two);
        move(one, three);
        hanoi(n - 1, two, one, three);
    }
}

//https://zhuanlan.zhihu.com/p/459055987
int main(void) {
    #if 0
    int nums[] = {1, 1, 1, 8, 6, 0, 6 ,7};
    int size = sizeof(nums) / sizeof(nums[0]);
    int ret = removeDuplicates(nums, size);
    printf("%d\n", ret);
    #endif

    hanoi(5, 'A', 'B', 'C');

    return 0;
}