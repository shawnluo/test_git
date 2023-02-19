/*
    001. string reverse
*/
void string_reverse() {
    char s[] = "abcd";
    char *left = s;
    char *right = s + strlen(s) - 1;
    while(left < right) {
        char tmp = *right;
        *right = *left;
        *left = tmp;
        left++, right--;
    }
    printf("%s\n", s);
}

/*  0002
    1. convert interger into ASCII character    96 -> 'a'
    2. convert interget into string number.     96 -> "96"
*/
int use_sprintf(void) {
    int i = 97;
    char res[100] = {'0'};
    sprintf(res, "%c", i);
    printf("%s\n", res);

    sprintf(res, "%d", i);
    printf("%s\n", res);

    return 0;
}


/*
    100. a1b2c3a8c6 -> a9b2c9
*/
void print_hash(int hash[], int size) {
    for(int i = 0; i < 256; i++) {
        printf("%d, ", hash[i]);
    }
}

void convert_string(void) {
    char *s = "a1b2c3a8c6";
    //1. using hash table to store the number of character
    //2. go throught hash[256] to store char with number

    int hash[256] = {0};
    int size = strlen(s);
    int sum = 0;
    int save = 0;
    int i, j;
    for(i = 0; i < size; ) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            save = i;
            i++;
            sum = 0;
            while(s[i] >= '0' && s[i] <= '9') {
                sum += sum * 10 + s[i] - '0';
                i++;
            }
            hash[s[save]] += sum;
        }
    }
    
    //print_hash(hash, 256);

    char res[1000] = {0};
    char c_tmp[1000] = {0};
    for(i = 0; i < 256; i++) {
        if(hash[i]) {
            sprintf(c_tmp, "%c", i);
            printf("%s\n", c_tmp);
            strcat(res, c_tmp);
            sprintf(c_tmp, "%d", hash[i]);
            printf("%s\n", c_tmp);
            strcat(res, c_tmp);
        }
    }

    printf("%s\n", res);
}


/*
    [101] sum of 2 elements in nums equal target
*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int left, right;
    int res[2] = (int *)malloc(sizeof(int) * 2);
    for(right = 1; right < numsSize; right++) {
        for(left = 0; left < right; left++) {
            if(nums[left] + nums[right] == target) {
                res[0] = left;
                res[1] = right;
                *returnSize = 2;
                return res;
            }
        }
    }

    *returnsSize = 0;
    return res;
}