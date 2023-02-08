#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define swap(a, b, c) (c) = (a), (a) = (b), (b) = (c)

void combine(char *s, char *re, int len, int num)
// len长度的字符串s 选取num个字符自由组合存放到字符串re
{
    if (num == 0) // 判断是否完成任务，不再需要选取字符
    {
        printf("%s\n", re);
        return;
    }
    if (len >= num)
    {
        combine(s, re, len - 1, num); // 不选取s[len-1]
        re[num - 1] = s[len - 1];     // 选取s[len-1]
        combine(s, re, len - 1, num - 1);
    }
    return;
}
int cmp(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}
int main()
{
    int len, i, j, k;
    char s[100], d[100], re[100];
    while (scanf("%s", s) != EOF)
    {
        len = strlen(s);
        qsort(s, len, sizeof(char), cmp); // s字符串递增排序
        d[0] = s[0];
        for (i = 1, j = 1; i < len; i++) // 挑选出s中独一无二的字符 存到d
            if (s[i] != s[i - 1])
                d[j++] = s[i];
        d[j] = '\0';
        for (i = 1; i <= j; i++)
        {
            re[i] = '\0', combine(d, re, j, i);
        }
    }
}