#include "common.h"
#include "test.h"

int string_copy(const char *s, char *res) {
    if(s == NULL)   return -1;
    while(*res++ = *s++) {
    }
    return 0;
}

int string_reverse(char *s) {
    if(s == NULL)   return -1;
    char *left = s;
    char *right = s + strlen(s) - 1;
    while(left < right) {
        swap(left, right);
        left++, right--;
    }
    return 0;
}

int mem_cpy(char *s, char *res, int len) {
    if(s == NULL)   return -1;
    if(s == res)    return 0;
    char *left = s;
    s = s + strlen(s) - 1;
    res += (strlen(s) - 1);

    if(s < res) {
        //copy from tail
        
        return 0;
    }
    //just copy
    while(len++ > 0) {
        *res-- = *s--;
    }
    return 0;
}


char *my_strtok(char *s, const char needle) {
    static char *input = NULL;
    if(s != NULL) input = s;
    if(input == NULL)   return NULL;
    int i = 0;

    while(input != NULL) {
        if(*input != needle) {
            res[i++] = *input++;
        } else {
            res[i] = '\0';
            input++;
        }
    }
    res[i] = '\0';
    input = NULL;
}

//a2b4a8 -> a10b4
char *convert(char *s) {
    int hash[256] = {0};
    int len = strlen(s);
    int data = 0;
    int save = 0;
    for(int i = 0 ; i < len; i++) {
        data = 0;
        if(isalpha(s[i]) == 0) {
            save = i;
            i++;
            while(isdigit(s[i]) == 0) {
                data = data * 10 + s[i] - '0';
                hash[s[i]] += data;
                i++;
            }
            hash[s[save]] += data;
        }
    }

    for(int i = 0; i < 256; i++) {
        if(!hash[i]) {
            continue;
        }
        sprintf(c_tmp, "%c", i);
        strcat(res, c_tmp);
        sprintf(c_tmp, "%d", hash[i]);
        strcat(res, c_tmp);
    }
}


int partition(int *nums, int start, int end) {
    int L = start;
    int R = end;
    int pivot = nums[L];
    while(L < R) {
        while(L < R && nums[R] >= pivot) R--;
        if(L < R)   nums[L++] = nums[R];
        while(L < R && nums[L] <= pivot) L++;
        if(L < R)   nums[R--] = nums[L];
    }
    nums[L] = pivot;
}


int **three_sum(int *nums, int len) {
    //1. sorting nums

    int L = 1;
    int R = len - 1;
    for(int i = 0; i < size; i++) {
        while(L < R) {
            sum = nums[i] + nums[L] + nums[R];
            if(sum > k) {
                R--;
            } else if(sum < k) {
                L++;
            } else {
                save();
            }
        }
    }
}


if == { [ ( push
else pop() != }]), return 0

sink_island() {
    if(s[i][j] == 0) return;
    s[i][j] = '0';
    sink_island(i + 1, j);
    i - 1, j;
    i, j + 1;
    i, j - 1; 
}


if n < 0
base = 1 / base;
n = -n;

double pow(int base, n) {
    if(n == 0) return 1.0;
    half = pow(base, n / 2);
    if(n % 2) return half * half * base;
    else    return half * half;
}


bool checkinclusion(char *s, char *sub) {
    //1. hash sub;
    int l, r;
    while(r < size) {
        if(hash[s[r++]]-- >= 1) count++;
        if count == size; return true;
        if(r - l == len_sub && hash[left++]++ >= 0) count--;
    }
    return false;
}

int main(void) {
    char s[] = "abc";
    string_reverse(s);
    printf("%s\n", s);

    return 0;
}