#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>


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


//=============== combination ==================
#define swap(a, b, c) (c) = (a), (a) = (b), (b) = (c)

void combine(char *s, char *re, int len, int num) {
// len长度的字符串s 选取num个字符自由组合存放到字符串re
    if (num == 0) {// 判断是否完成任务，不再需要选取字符
        printf("%s\n", re);
        return;
    }
    if (len >= num){
        combine(s, re, len - 1, num); // 不选取s[len-1]
        re[num - 1] = s[len - 1];     // 选取s[len-1]
        combine(s, re, len - 1, num - 1);
    }
    return;
}

int cmp(const void *a, const void *b) {
    return *(char *)a - *(char *)b;
}

int main(void) {
    int len, i, j, k;
    char s[100], d[100], re[100];
    while (scanf("%s", s) != EOF) {
        len = strlen(s);
        qsort(s, len, sizeof(char), cmp); // s字符串递增排序
        d[0] = s[0];
        for (i = 1, j = 1; i < len; i++) {// 挑选出s中独一无二的字符 存到d
            if (s[i] != s[i - 1]) {
                d[j++] = s[i];
            }
        }
        d[j] = '\0';
        for (i = 1; i <= j; i++){
            re[i] = '\0', combine(d, re, j, i);
        }
    }
}
