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

void permutation(char s[], int b, int len) // 长度为len的字符串，从s[i]开始全排列
{
    if(b == len) // 等价于 if(s[b]=='\0')
        printf("%s\n", s);

    if(b < len) {
        for(int i = b; i < len; i++) {
            int f = 0;
            for(int j = i - 1; j >= b; j--) {// 遍历查询前面有没有出现该字符
                if(s[j] == s[i]) {
                    f = 1;
                    break;
                }
            }
            if(f == 1)
                continue;                // 跳过
            swap((s + b), (s + i)); // 交换
            permutation(s, b + 1, len);  // 从s[b+1]开始全排列
            swap((s + b), (s + i)); // 返回原来字符串顺序
        }
    }
    return;
}
int main()
{
    char s[] = "abc";
    int len = strlen(s);
    permutation(s, 0, len);
    // system ( "pause" );
    return 0;
}
