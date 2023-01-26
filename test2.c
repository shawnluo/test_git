#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>


typedef struct NODE {
    int data;
    struct NODE *next;
} Node, *pNode;

#define LEN sizeof(struct NODE)

pNode create_LL(int arr[], int size) {
    pNode pHead;
    pNode p, pNext;
    if(!arr) {
        return -1;
    }
    if (size <= 0) {
        return -1;
    }

    p = (pNode)malloc(LEN);
    p->data = arr[0];
    p->next = NULL;
    pHead = p;
    pNext = p;

    for(int i = 1; i < size; i++) {
        p = (pNode)malloc(LEN);
        p->data = arr[i];
        p->next = NULL;
        pNext->next = p;
        pNext = p;
    }

    return pHead;
}


pNode create_LL2(int arr[], int size) {
    pNode pHead = NULL;
    pNode p = NULL;
    for(int i = size - 1; i >= 0; i--) {
        p = (pNode)malloc(LEN);
        p->data = arr[i];
        p->next = pHead;
        pHead = p;
    }
    return pHead;
}


void showMe(pNode pHead) {
    if(pHead == NULL) {
        return;
    }
    while(pHead) {
        printf("%d ", pHead->data);
        pHead = pHead->next;
    }
}


int isSub(char *s1, char *s2) {
    int i = 0, j = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    while(i < len1) {
        int tmp = i;
        while(j < len2) {
            if(s1[tmp] != s2[j]) {
                break;
            }
            tmp++, j++;
        }
        if(j == len2) {
            return 1;
        }
        i++;
    }

    return 0;
}

int myStrstr(char *haystack, char *needle) {
    int size1 = strlen(haystack);
    int size2 = strlen(needle);
    int i, j;
    for(i = 0; i < size1; i++) {
        for(j = 0; j < size2; j++) {
            if(haystack[i + j] != needle[j]) {
                break;
            }
        }
        if(j == size2) {
            return i;
        }
    }
    return -1;
}


int isSub2(char *s1, char *s2) {
    char *p1 = s1;
    char *p2 = s2;
    while(*s1) {
        p1 = s1;
        p2 = s2;
        while(*p2) {
            if(*p1 != *p2) {
                break;
            }
            p1++, p2++;
        }
        if(!*p2) {
            return 1;
        }
        s1++;
    }
    return 0;
}


int first_non_repeat(char *s) {
    int size = strlen(s);
    int hash[256] = {0};
    
    char *p = s;
    while(*p) {
        hash[*p]++;
        p++;
    }

    p = s;
    while(*p) {
        if(hash[*p] > 1) {
            return *p;
        }
        p++;
    }
    return -1;
}


int first_non_repeat2(char *s) {
    int size = strlen(s);
    int hash[256] = {0};
    int i;

    for(i = 0; i < size; i++) {
        if(hash[s[i]]) {
            return i;
        }
        hash[s[i]] = i;
    }
    return -1;
}


int max(int x, int y) {
    return x >= y ? x : y;
}


int min(int x, int y) {
    return x <= y ? x : y;
}


int longest_unique_substring(char *s) {
    int size = strlen(s);
    int pos = -1;
    int len = 0;
    int len_max = INT_MIN;
    int hash[256];
    int i;

    for(i = 0; i < 256; i++) {
        hash[i] = -1;
    }

    for(i = 0; i < size; i++) {
        pos = max(pos, hash[s[i]]);
        len = i - pos;
        len_max = max(len, len_max);
        hash[s[i]] = i;
    }
    return len_max;
}


int shortest_consective_arr(int arr[], int size, int key) {
    int left = 0;
    int right = 0;
    int sum = 0;
    int len, len_min = INT_MAX;

    for(right = 0; right < size; right++) {
        while(left <= right && sum >= key) {
            len = right - left + 1;
            if(len < len_min) {
                len_min = len;
                sum -= arr[left++];
            }
        }
    }
    return len_min;
}


int short_consecutive(int arr[], int size, int key) {
    for(right = 0; right < size; right++) {
        sum += arr[right];
        while(left <= right && sum >= key) {
            len = right - left + 1;
            len_min = len < len_min ? len : len_min;
            sum -= arr[left++];
        }
    }
    return len_min;
}


int main(void) {
    #if 0
    pNode pHead = NULL;
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    pHead = create_LL2(arr, size);
    showMe(pHead);
    #endif

    //int ret = isSub2("abcd", "axbc");
    //printf("%d\n", ret);
    //int ret = first_non_repeat2("abcdba");
    int ret = longest_unique_substring("abcaxf");
    printf("%d\n", ret);

    return 0;
}