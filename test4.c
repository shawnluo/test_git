#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define swap_x(a, b, c) (c) = (a), (a) = (b), (b) = (c)

void swap(char *x, char *y) {
    char tmp = *x;
    *x = *y;
    *y = tmp;
}

void permutation_ext(char s[], int pos, int len) {// 长度为len的字符串，从s[i]开始全排列
    if(pos == len) // 等价于 if(s[pos]=='\0')
        printf("%s\n", s);

    if(pos < len) {
        for(int i = pos; i < len; i++) {
            int f = 0;
            for(int j = i - 1; j >= pos; j--) {// 遍历查询前面有没有出现该字符
                if(s[j] == s[i]) {
                    f = 1;
                    break;
                }
            }
            if(f == 1)
                continue;                // 跳过
            swap((s + pos), (s + i)); // 交换
            permutation_ext(s, pos + 1, len);  // 从s[pos+1]开始全排列
            swap((s + pos), (s + i)); // 返回原来字符串顺序
        }
    }
    return;
}


void permutation(char s[], int pos) { // 长度为len的字符串，从s[i]开始全排列
    int len = strlen(s);
    if(pos == len) // 等价于 if(s[pos]=='\0')
        printf("%s\n", s);

    for(int i = pos; i < len; i++) {
        swap((s + pos), (s + i)); // 交换
        permutation(s, pos + 1);  // 从s[pos+1]开始全排列
        swap((s + pos), (s + i)); // 返回原来字符串顺序
    }
}


int main(void)
{
    char s[] = "abc";
    int len = strlen(s);

    //permutation_ext(s, 0, len);
    permutation(s, 0);

    return 0;
}