/*  [001] string reverse
*/
void string_reverse() {
    char s[] = "abcd";
    char *left = s;
    char *right = s + strlen(s) - 1;
    while(left < right) {
        //char tmp = *right;
        //*right = *left;
        //*left = tmp;
        swap(left, right);
        left++, right--;
    }
    printf("%s\n", s);
}

/*  [001] - 01. strcpy implement
*/
int str_cpy(const char *s, char *res) {
    if(s == NULL)   return -1;
    while(*res = *s) ;
    return 0;
}

/*  [001] - 02. memcpy implement
*/
int mem_cpy(char *s, char *res, int len) {
    if(s == NULL)   return -1;
    if(s == res)    return 0;
    
    if(len <= 0)    return 0;   //important!

    char *left = s;

    if(s < res) {
        s = s + strlen(s) - 1;
        res += (strlen(s) - 1);
        //copy from tail
        *res-- = *s--;
        return 0;
    }
    //just copy
    while(len++ > 0) {
        *res++ = *s++;
    }
    return 0;
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

/*  003
    using qsort to sort array
*/
//case1
int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);     //ascending
    //return (*(int *)b - *(int *)a);     //descending
}

void sort_arr(void) {
    int values[] = {88, 56, 100, 2, 25};
    int size = sizeof(values) / sizeof(values[0]);
    qsort(values, size, sizeof(int), cmpfunc);
}

//case2
typedef struct Node {
    int num1;
    int num2;
} node;

int func(void *a, void *b) {
    node x = *(node *)a;
    node y = *(node *)b;

    return x.num1 - y.num1;
}

void sort(void) {
    node data[5];
    data[0].num1 = 5;
    data[0].num2 = 50;
    data[1].num1 = 4;
    data[1].num2 = 40;
    data[2].num1 = 3;
    data[2].num2 = 30;
    data[3].num1 = 1;
    data[3].num2 = 10;
    data[4].num1 = 2;
    data[4].num2 = 20;

    qsort(data, 5, sizeof(struct Node), func);

    for(int i = 0; i < 5; i++) {
        printf("%d\n", data[i].num1);
    }

    return 0;
}

/*  [003-01]    binary sorting **************************************

*/
int partition(int *nums, int start, int end) {
    int left = start - 1;
    int right;
    int pivot = nums[end];

    for(right = start; right < end; right++) {
        if(nums[right] < pivot) {
            left++;
            swap(nums + left, nums + right);
        }
    }
    swap(&nums[left + 1], &nums[end]);
    return left + 1;
}


void quick_sort(int *nums, int start, int end) {
    if(start < end) {
        int pivot = partition(nums, start, end);
        quick_sort(nums, start, pivot - 1);
        quick_sort(nums, pivot + 1, end);
    }
}


/*  004
    strtok()
*/
char *my_strtok(char *hay, const char needle) {
    static char *input = NULL;
    if(hay != NULL) input = hay;
    if(input == NULL) return NULL;

    char *res = (char *)calloc(20, sizeof(char));
    int i = 0;
    for(; input[i] != '\0'; i++) {
        if(input[i] != needle) {
            res[i] = input[i];
        } else {
            res[i] = '\0';
            input = input + i + 1;
            return res;
        }
    }
    res[i] = '\0';
    input = NULL;

    return res;
}

int main(void) {
    char hay[] = "show me the money!";
    char needle = ' ';
    char *s = my_strtok(hay, needle);
    while(s) {
        s = my_strtok(NULL, needle);
        printf("- %s\n", s);
    }
    return 0;
}

/*  005
    long long vs double
    
    0. c语言采用float和double来定义小数！
        float 单精度（4个字节 32-bit）
        double 双精度（8个字节 64-bit）
    
    1. long: is a data type that is capable of storing 64 bit two's complement integer
    2. double: is a doulbe-precision(8 bytes) 64-bit floating point
    3. long long is integer
*/

/*  006
    isalnum: letters and numbers
    isalpha: letters
    isdigit: numbers
*/

/*  007
    the differences between 0 and '\0' of string end:
    '\0'
*/


/* [010] aligned malloc
*/
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


/*  [100] a1b2c3a8c6 -> a9b2c9
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
            while(s[i] >= '0' && s[i] <= '9') { //isdigit(s[i]) == 0
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

    *returnSize = 0;
    return res;
}

/*  [102] three sum
    给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
    使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
*/

void quickSort(int* nums, int start, int end) {     //快速排序 
	int pivot, L, R;
	if (start >= end)   return;

	pivot = nums[start];
	L = start;
	R = end;
	while (L < R) {
		while (L < R && nums[R] >= pivot)   R--;
		if (L < R)                          nums[L++] = nums[R];
		while (L < R && nums[L] <= pivot)   L++;
		if (L < R)                          nums[R--] = nums[L];
	}
	nums[L] = pivot;
	quickSort(nums, start, L - 1);
	quickSort(nums, L + 1, end);
}

int comp(int *x, int *y) {
    return *x - *y;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	int i = 0;								//当前数值下标
	int left = i+1;							//左指针
	int right = numsSize - 1;				//右指针
	int sum = 0;							//和
	int base_alloc_size = 16;				//基本内存
	int** res = (int**)malloc(sizeof(int*) * base_alloc_size);
	(*returnSize) = 0;
	*returnColumnSizes = (int*)malloc(sizeof(int) * base_alloc_size);

	if (numsSize < 3 || nums == NULL) {
		return NULL;
	}

	quickSort(nums, 0, numsSize - 1);                           //排序
    //qsort(nums, numsSize, sizeof(int), comp);

	for (i = 0; i <= numsSize - 3; i++) {
		left = i + 1;
		right = numsSize - 1;
		if (nums[i] > 0) {			// 如果当前数字大于0，则三数之和一定大于0，所以结束循环
			break;
		}
		if (i > 0 && nums[i] == nums[i - 1]) {	// 去重
			continue;
		}
		while (left < right) {
			sum = nums[i] + nums[left] + nums[right];
			if (sum > 0) {
				right--;
			}
			else if (sum < 0) {
				left++;
			}
			else {
				res[*returnSize] = (int*)calloc(3, sizeof(int));
				res[*returnSize][0] = nums[i];
				res[*returnSize][1] = nums[left];
				res[*returnSize][2] = nums[right];

				(*returnColumnSizes)[*returnSize] = 3;
				(*returnSize)++;

				while (left < right && nums[left] == nums[left + 1]) {		//去除重复的
					left++;
				}
				while (left < right && nums[right] == nums[right - 1]) {
					right--;
				}
				left++; right--;
			}

			if (*returnSize == base_alloc_size) {							//空间不足，扩充内存
				base_alloc_size = base_alloc_size * 2;
				res = (int**)realloc(res, base_alloc_size * sizeof(int*));
				(*returnColumnSizes) = (int*)realloc((*returnColumnSizes), \
                    base_alloc_size * sizeof(int));
			}
		}
	}
	return res;
}

int main() {
	int num[] = { -1, 0, 1, 2, -1, -4 };
	int* nums = (int*)num;
	int numsSize = sizeof(num) / sizeof(int);
	int* returnSize = (int*)calloc(1, sizeof(int));
	//这里的内存分配最大值,即排列组合知识,C几取3
	//C6取3 == 20
	int** returnColumnSizes = (int**)malloc(sizeof(int*) * \
        (numsSize * (numsSize - 1) * (numsSize - 2)) / 6);
	int** res = threeSum(nums, numsSize, returnSize, returnColumnSizes);

	for (int i = 0; i < *returnSize; i++) {				//打印
		for (int j = 0; j < 3; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	return 0;
}

/*  [103]
    []{}()  -> true
    {[()]}  -> true
    {(})    -> false
    [}      -> false
*/
int sp = -1;
char stack[10000] = {0};

//void stack_init(int size) {

//}

void push(char c) {
    stack[++sp] = c;
}

char pop() {
    return stack[sp--];
}

bool isValid(char * s){
    int size = strlen(s);
    //stack_init(size);

    while(*s) {
        switch(*s) {
            case '(':
                push('(');
                break;
            case '[':
                push('[');
                break;
            case '{':
                push('{');
                break;
            case ')':
                if(pop() != '(')            return false;
                break;
            case ']':
                if(pop() != '[')            return false;
                break;
            case '}':
                if(pop() != '{')            return false;
                break;
        }
        s++;
    }
    if(sp == -1){
        return true;
    }
    return false;
}

int main(void) {
    // break_int(8);
    int res = isValid("{[]}");
    printf("%d\n", res);

    return 0;
}

/*  [104]
    find islands
*/
void sink_island(char **s, int i, int j, int gridSize, int gridColSize) {
    if(i < 0 || i >= gridSize)      return;
    if(j < 0 || j >= gridColSize)   return;
    if(s[i][j] == 0)                return;

    s[i][j] = '0';
    sink_island(s, i + 1, j, gridSize, gridColSize);
    sink_island(s, i - 1, j, gridSize, gridColSize);
    sink_island(s, i, j + 1, gridSize, gridColSize);
    sink_island(s, i, j - 1, gridSize, gridColSize);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    if(grid == 0 || gridSize == 0 || *gridColSize == 0) {
        return 0;
    }
    //1. find 1, then reverse it and 1s connected with it. counter + 1
    //2. scan the rest of grid. repeat 1, until all 1s become zero
    int count = 0, i, j;
    for(i = 0; i < gridSize; i++) {
        for(j = 0; j < *gridColSize; j++) {
            if(grid[i][j] == '1') {
                sink_island(grid, i, j, gridSize, *gridColSize);
                count++;
            }
        }
    }
    return count;
}

/*  [105]
    pow
*/
double fastPow(double x, int n){
    if(n == 0)  return 1.0;

    double half = fastPow(x, n / 2);
    if(n % 2 == 0)  return half * half;
    else            return half * half * x;
}

double myPow(double x, int n) {
    long long N = n;
    //x: 3  n: 2
    //x: 3  n: -2
    if(N < 0) {
        x = 1 / x;
        N = -N;
    }
    return fastPow(x, N);
}

double myPow2(double x, int n) {
    long long N = n;
    if(n < 0) {
        x = 1 / x;
        N = -N;
    }
    double res = 1;
    for(long long i = N; i; i /= 2) {
        if((i % 2) == 1)    res = res * x;
        x = x * x;
    }
    return res;
}

/*  [106]
    Given a string, return true if the s can be palindrom after deleting at most one character from it.
*/
int palindrom_ext(char *s) {
    int size = strlen(s);
    char *left = s;
    char *right = s + size - 1;
    int count = 0;
    while(left < right) {
        if(*left == *right) {
            left++, right--;
        } else {
            count++;
            left++;
        }
    }
    if(count <= 1) return true;
    count = 0;
    while(left < right) {
        if(*left == *right) left++, right--;
        else    count++, right--;
    }
    if(count <= 1) return true;
    return false;
}

/*  [107]
    1. Digits (one of ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"])
        Both decimal numbers and integers must contain at least one digit.

    2. A sign ("+" or "-"):
        Sign characters are optional for both decimal numbers and integers, 
        but if one is present, it will always be the first character. 
        Note, this means that a sign character can also appear immediately after an exponent.

    3. An exponent ("e" or "E")
        Exponents are also optional, but if the string contains one then 
        it must be after a decimal number or an integer.
        An integer must follow the exponent.

    4. A dot (".")
        A decimal number should only contain one dot. Integers cannot contain dots.

    5. Anything else
        There will never be anything else in a valid number.
        From these facts, we can logically determine a set of rules to follow in our algorithm.
*/
bool isNumber(char *s) {
    bool seenDigit = false;
    bool seenExponent = false;
    bool seenDot = false;

    int size = strlen(s);
    for(int i = 0; i < size; i++) {
        char cur = s[i];
        if(cur >= '0' && cur <= '9') {
            seenDigit = true;
        } else if(cur == '+' || cur == '-') {
            if(i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                return false;
            }
        } else if(cur == 'e' || cur == 'E') {
            if(seenExponent || !seenDigit) {
                return false;
            }
            seenExponent = true;
            seenDigit = false;
        } else if(cur == '.') {
            if(seenDot || seenExponent) {
                return false;
            }
            seenDot = true;
        } else {
            return false;
        }
    }
    return seenDigit;
}

/*  [108] leetcode 567. Permutation in String
    Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
    In other words, return true if one of s1's permutations is the substring of s2.
    for example: 
        input:  s1 "abc"     s2 "xbacy"
        return: true
*/
bool checkInclusion(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if(len1 < len2) {
        return false;
    }
    int count[26] = {0};
    for(int i = 0; i < len1; i++) {
        count[s1[i] - 'a']++;
    }
    for(int i = 0; i < len2; i++) {
        count[s2[i] - 'a']--;
        if(i >= len1) {
            count[s2[i - len1] -'a']++;
        }
        int j;
        for(j = 0; j < 26; j++) {
            if(count[j] != 0) break;
        }
        if(j == 26) return true;
    }
    return false;
}

bool check_inclusion_ext(char *s, char *sub) {
    int len_s = strlen(s);
    int len_sub = strlen(sub);
    int hash[256] = {0};
    for(int i = 0; i < len_sub; i++) {
        hash[sub[i]]++;
    }
    int left = 0, right = 0;
    int count = 0;
    while(right < len_s) {
        if(hash[s[right++]]-- >= 1)     count++;    //s[right] is one of sub[]
        if(count == len_sub)            return true;
        if(right - left >= len_sub && \
            hash[s[left++]]++ >= 0) {   //s[left] is one of sub[]
            count--;
        }
    }
    return false;
}

/*  [109] leetcode 438. 
    Input: s = "cbaebabacd", p = "abc"
    Output: [0,6]
*/
int *findAnagrams(char *s, char *p, int *returnSize) {
    if(!s || !p)    return NULL;

    int size1 = strlen(s);
    int size2 = strlen(p);
    int *res = (int *)malloc(sizeof(int) * size1);
    memset(res, 0, sizeof(int) * size1);
    int hash[256] = {0};
    int left = 0, right = 0;

    for(int i = 0; i < size2; i++) {
        hash[p[i]]++;
    }

    int count = size2;
    int i = 0;
    while(right < size1) {
        if(hash[s[right++]]-- >= 1) {
            count--;
        }
        if(count == 0) {
            res[i++] = left;
        }
        
        //1. right - left == size2      already passed the len of sub, so left need increase 1
        //2. hash[s[left++]]++ >= 0     >= 0 means s[left] was the member of sub, now need increase the count 
        //      to compensate the hash, because decreased one more at the beginning loop.
        //      also, if hash >=0, means the count also need to be compensated. 
        if(right - left == size2 && hash[s[left++]]++ >= 0) {
            count++;
        }
    }
    *returnSize = i;
}

/*  [110]   the longest increasing sub array
    Output: the number of longest increasing sub
*/
int longest_increasing_sub(int *arr, int len) {
    int dp[len];
    int res = INT_MIN;
    for(int i = 0; i < len; i++) dp[i] = 1;

    for(int i = 1; i < len; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}

/*  [111]   the largest contiguous sum of sub array
    input: {3, -2, 4, 5, 6};
    output: 16
*/
int max_sum_arr(int *arr, int len) {
    int dp[len];
    int res = INT_MIN;
    dp[0] = arr[0];

    for(int i = 1; i < len; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        res = max(res, dp[i]);
    }
    return res;
}

/*  [112]   minimum meeting room II

*/
int min_meeting_rooms(int **intervals) {
    int len = sizeof(intervals) / sizeof(intervals[0]);
    int start[len];
    int end[len];
    for(int i = 0; i < len i++) {
        start[i] = intervals[i][0];
        end[i] = intervals[i][1];
    }
    qsort(start);
    qsort(end);

    int pStart = 0;
    int pEnd = 0;
    int room = 0;
    while(pStart != len) {
        //make an example, then it's easy to understand!
        //[1, 3], [4, 5], [6, 7]
        if(pStart == 0 || start[pStart] < end[pEnd]) {
            room++;
        } else {
            pEnd++;
        }
        pStart++;
    }
    return room;
}


/*  [113] - permutation
*/
void permutition(char *s, int pos) {
    int size = strlen(s);
    if(pos >= size) printf("%s\n", s);
    for(int i = pos; i < size; i++) {
        swap(&s[i], &s[pos]);
        permutation(s, pos + 1);
        swap(&s[i], &s[pos]);
    }
}


/*  [114] - leetcode 392
    Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
    A subsequence of a string is a new string that is formed from the original string by 
    deleting some (can be none) of the characters without disturbing the relative positions 
    of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
*/
bool isSubsequence(char *s, char *sub) {
    int len_s = strlen(s);
    int len_sub = strlen(sub);
    int dp[len_s + 1][len_sub + 1];
    dp[0][0] = 0;
    int i, j;
    for(i = 1; i < len_s; i++) {
        for(j = 1; j < len_sub; j++) {
            if(s[i] == sub[j])  dp[i][j] = dp[i - 1][j - 1] + 1;
            else                dp[i][j] = dp[i][j - 1];
        }
    }
    if(dp[i][j] == len_sub) return true;
    return false;
}

/*  [120] - binary additation
    "101" + "11" = "1000"
*/
char *addBinary(char *s1, char *s2) {
    if(s1 == NULL || s2 == NULL)    return NULL;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int sum = 0;
    int size = (len1 > len2 ? len1 : len2) + 1;

    while(len1 > 0 || len2 > 0 || size > 0) {
        if(len1 > 0) sum += s1[--len1] - '0';
        if(len2 > 0) sum += s2[--len2] - '0';

        res[--size] = sum % 2 + '0';
        sum /= 2;
    }
    return res + size;
}

/*  [121] rotate matrix **********************************
 *  
*/
void rotate(){
    int a[4][3] = {{1,2,3},
                   {4,5,6},
                   {7,8,9},
                   {10,11,12}};
    int b[3][4];
    int m = 4, n = 3;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
           b[i][j] = a[j][n - 1 - i];
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}

//TODO
/*  [121] rotate matrix in place**********************************
 *  
*/
int **rotate_matrix(int **mat, int row, int col) {
    int save = mat[x][y];
    for(int x = 0; x < row / 2; x++) {
        for(int y = x; y < col - x - 1; y++) {
            mat[x][y]                       = mat[y][col - x + 1];
            mat[y][col - x - 1]             = mat[col - x - 1][row - y - 1];
            mat[col - x - 1][row - y - 1]   = mat[row - y - 1][x];
            mat[row - y - 1][x] = save;
        }
    }
}

/*  [122] - spiral matrix
    Input: 
        [[1,2,3],
        [4,5,6],
        [7,8,9]]
    Output: [1,2,3,6,9,8,7,4,5]
*/


/*  [123] - spiral matrix ii
    Input: N = 5
    Output: 
        1,  2,  3,  4,  5
        16, 17, 18, 19, 6
        15, 24, 25  20, 7
        14, 23, 22, 21, 8
        13, 12, 11, 10, 9
*/


/*************************************************************
    [123] - merge intervals
    Input: intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
    Output: [[1, 6], [8, 10], [15, 18]]
    Explanation: [1, 3] and [2, 6] overlap, merge them into [1, 6]

 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int Comp(const void **a, const void **b) {
    int *one = *(int **)a;
    int *two = *(int **)b;
    
    if (one[0] == two[0]) {
        return one[1] - two[1];
    } 
    return one[0] - two[0];
}
 
int** merge_intervals(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int i;
    int left = 0;
    int right = 0;
    int **res;
    int idx = 0;
    
    res = (int **)malloc(sizeof(int *) * intervalsSize);
    for ( i = 0; i < intervalsSize; i++) {
        res[i] = (int *)malloc(sizeof(int) *2);
        memset(res[i], 0, sizeof(int) *2);
    }
    
    returnColumnSizes[0] = (int *)malloc(sizeof(int) * intervalsSize);
    for (i = 0; i < intervalsSize; i++) {
        returnColumnSizes[0][i] = 2;
    }
    
    qsort(intervals, intervalsSize, sizeof(intervals[0]), Comp);
    
    left = intervals[0][0];
    right = intervals[0][1];
    for (i = 1; i < intervalsSize; i++){
        if ((intervals[i][0] >= left) && (intervals[i][0] <= right) && (intervals[i][1] > right)) {
            right = intervals[i][1];
        } else if (intervals[i][0] > right) {
            res[idx][0] = left;
            res[idx][1] = right;
            left = intervals[i][0];
            right = intervals[i][1];
            idx++;
        }
    }
    
    res[idx][0] = left;
    res[idx][1] = right;
    idx++;
    
    *returnSize = idx;
    
    return res;
}

/*************************************************************
    [124] - simplify path
*/
char *simplify_path(char *path) {
    char *save[100];
    int size = 0;
    for(char *s = strtok(path, "/"); s; s = strtok(NULL, "/")) {
        if(strcmp(s, ".")) {
            
        } else if (strcmp(s, "..")) {
            size = fmax(0, size - 1);
        } else {
            save[size++] = s;
        }
    }
    if(size == 0) {
        return "/";
    }
    char *res = calloc(1000, sizeof(char));
    for(int i = 0; i < size; i++) {
        strcat(res, "/");
        strcat(res, save[i]);
    }
    return res;
}

/*************************************************************
    [130] - longest unique sub strings
    abca     -> abc 3
*/
int longest_uniq_sub(char *s) {
    /*1. initialize hash[] to all -1. pos set to -1;
      2. get len by chosing the larger value of hash[] and pos.
        2.1 hash[] saves the postion of repeat character last position.
        2.2 pos save the largest position except the current char
      3. update the hash of char i to i
    */

    int hash[256];
    for(int i = 0; i < 256; i++) hash[i] = -1;

    int len = strlen(s);
    int len_max = 0;
    int pos = -1;
    for(int i = 0; i < len; i++) {
        pos = fmax(pos, hash[s[i]]);
        len = i - pos;
        len_max = fmax(len_max, len);
        hash[s[i]] = i;
    }
    return len_max;
}

/*************************************************************
    [131] - shortest 
    1.  L points to start, R points to L
    2.  R in the loop [R, end], 
        if sum >= key, then
            save and compare len with len_min
            break;
*/
int shortest_consective(const int *nums, int len, const int key) {
    int L = 0;
    int R = 0;
    int sum;
    int len = 0;
    int len_min = INT_MAX;
    for(L = 0; L < len; L++) {
        sum = 0;
        for(R = L; R < len; R++) {
            sum += nums[R];
            if(sum >= key) {
                len = R - L + 1;
                len_min = fmin(len_min, len);
                break;
            }
        }
    }
    return len_min;
}

/*************************************************************
    [132] - depth first search in matrix
    0 0 0
    1 1 0
    0 0 0

    from [starx, starty] to [endx, endy]
    return true or false
*/
public class DFSinMatrix {
	//Check whether there is path from src(x,y) to dest (x, y)
	//DFS wraper, Time O(m*n), Space O(m*n)
	public static boolean hasPathDfs( int[][] adj, int sx, int sy, int dx, int dy) {
		int m = adj.length;
		int n = adj[0].length;
		boolean[][] visited = new boolean[m][n];
		dfs(adj, sx,sy, visited);
		if(!visited[dx][dy]) {
			return false;
		}
		return true;
	}
	
	//DFS + memoization, Time O(m*n), Space O(m*n) 
	private static void dfs(int[][] adj, int i, int j, boolean[][] visited) {
		int m = adj.length;
		int n = adj[0].length;
		if(i < 0 || i >= m || j < 0 || j >= n || adj[i][j] == 1 || visited[i][j]) {
			return;
		}		
		visited[i][j] = true;
		dfs(adj, i-1, j, visited); // Move left
		dfs(adj, i+1, j, visited); // Move Right
		dfs(adj, i, j-1, visited); //Move top
		dfs(adj, i, j+1, visited); //Move bottom		
	}
		
	public static void main(String[] args) {
		//2D matrix with 1's as blocked  and 0's as path.
		int[][] matrix = {{0,0,1,0,1},
		          		      {0,0,0,0,0},
				              {0,1,0,1,1},
				              {0,0,0,0,0}};
		//find path
		int sx = 1, sy = 3, dx = 3, dy = 1;
		System.out.println("Find path from (" + sx + "," + sy + ") to (" + dx + "," + dy + "): ");
		System.out.println("DFS: " + hasPathDfs(matrix, sx, sy, dx, dy));	
	}
}

public class DFSinMatrix {
	//Check whether there is path from src(x,y) to dest (x, y)
	//DFS wraper, Time O(m*n), Space O(m*n)
	public static boolean hasPathDfs( int[][] adj, int sx, int sy, int dx, int dy) {
		int m = adj.length;
		int n = adj[0].length;
		boolean[][] visited = new boolean[m][n];
		dfs(adj, sx,sy, visited);
		if(!visited[dx][dy]) {
			return false;
		}
		return true;
	}
	
	//DFS + memoization, Time O(m*n), Space O(m*n) 
	private static void dfs(int[][] adj, int i, int j, boolean[][] visited) {
		int m = adj.length;
		int n = adj[0].length;
		if(i < 0 || i >= m || j < 0 || j >= n || adj[i][j] == 1 || visited[i][j]) {
			return;
		}		
		visited[i][j] = true;
		dfs(adj, i-1, j, visited); // Move left
		dfs(adj, i+1, j, visited); // Move Right
		dfs(adj, i, j-1, visited); //Move top
		dfs(adj, i, j+1, visited); //Move bottom		
	}
		
	public static void main(String[] args) {
		//2D matrix with 1's as blocked  and 0's as path.
		int[][] matrix = {{0,0,1,0,1},
		          		      {0,0,0,0,0},
				              {0,1,0,1,1},
				              {0,0,0,0,0}};
		//find path
		int sx = 1, sy = 3, dx = 3, dy = 1;
		System.out.println("Find path from (" + sx + "," + sy + ") to (" + dx + "," + dy + "): ");
		System.out.println("DFS: " + hasPathDfs(matrix, sx, sy, dx, dy));	
	


/*************************************************************
    [132] - ShortestPathBetweenCellsBFS

*/
    https://www.lavivienpost.com/shortest-path-between-cells-in-matrix-code/
    import java.util.LinkedList;
public class ShortestPathBetweenCellsBFS {
    private static class Cell  {
        int x;
        int y;
        int dist;  	//distance
        Cell prev;  //parent cell in the path
        Cell(int x, int y, int dist, Cell prev) {
            this.x = x;
            this.y = y;
            this.dist = dist;
            this.prev = prev;
        }
        
        @Override
        public String toString(){
        	return "(" + x + "," + y + ")";
        }
    }
	//BFS, Time O(n^2), Space O(n^2)
	public static void shortestPath(int[][] matrix, int[] start, int[] end) {
		int sx = start[0], sy = start[1];
		int dx = end[0], dy = end[1];	
		//if start or end value is 0, return
		if (matrix[sx][sy] == 0 || matrix[dx][dy] == 0) {
			System.out.println("There is no path.");
			return;  
		}
		//initialize the cells 
	    int m = matrix.length;
	    int n = matrix[0].length;	    
	    Cell[][] cells = new Cell[m][n];
	    for (int i = 0; i < m; i++) {
	        for (int j = 0; j < n; j++) {
	            if (matrix[i][j] != 0) {
	                cells[i][j] = new Cell(i, j, Integer.MAX_VALUE, null);
	            }
	        }
	    }
	    //breadth first search
	    LinkedList<Cell> queue = new LinkedList<>();       
	    Cell src = cells[sx][sy];
	    src.dist = 0;
	    queue.add(src);
	    Cell dest = null;
	    Cell p;
	    while ((p = queue.poll()) != null) {
	    	//find destination 
	        if (p.x == dx && p.y == dy) { 
	            dest = p;
	            break;
	        }      
	        // moving up
	        visit(cells, queue, p.x - 1, p.y, p);        
	        // moving down
	        visit(cells, queue, p.x + 1, p.y, p);        
	        // moving left
	        visit(cells, queue, p.x, p.y - 1, p);        
	        //moving right
	        visit(cells, queue, p.x, p.y + 1, p);
	    }
	    
	    //compose the path if path exists
	    if (dest == null) {
	    	System.out.println("there is no path.");
	        return;
	    } else {
	        LinkedList<Cell> path = new LinkedList<>();
	        p = dest;
	        do {
	            path.addFirst(p);
	        } while ((p = p.prev) != null);
	        System.out.println(path);
	    }
	}
	
	//function to update cell visiting status, Time O(1), Space O(1)
	private static void visit(Cell[][] cells, LinkedList<Cell> queue, int x, int y, Cell parent) { 
		//out of boundary
	    if (x < 0 || x >= cells.length || y < 0 || y >= cells[0].length || cells[x][y] == null) {
	        return;
	    }    
	    //update distance, and previous node
	    int dist = parent.dist + 1;
	    Cell p = cells[x][y];
	    if (dist < p.dist) {
	        p.dist = dist;
	        p.prev = parent;
	        queue.add(p);
	    }
	}
	public static void main(String[] args) { 		
	   	int[][] matrix = {
		   {1, 0, 1},
		   {0, 1, 1},
		   {0, 0, 1}};
	   	
	   	//case1, there is no path
	   	int[] start = {0, 0};
	   	int[] end = {1, 1};
	   	System.out.print("case 1: ");
	   	shortestPath(matrix, start, end);
	   
	   	//case 2, there is path
	   	int[] start1 = {0, 2};
	   	int[] end1 = {1, 1};
	   	System.out.print("case 2: ");
	   	shortestPath(matrix, start1, end1);
	} 
}


/*************************************************************
    [134] - interger break (leetcode 343)
        Given an integer n, break it into the sum of k positive integers, 
        where k >= 2, and maximize the product of those integers.
*/
long long integerBreak(int n) {
    long long dp[n + 1];
    for(int i = 0; i <= n + 1; i++) dp[i] = 0;

    int max = 0;
    dp[2] = 1;
    for(int i = 3; i <= n + 1; i++) {
        for(int j = 1; j < i - 1; j++) {
            dp[i] = fmax(dp[i], fmax((i - j) * j), dp[i - j] * j);
        }
    }
    return dp[n];
}

/*************************************************************
    [135] - best team with no conflicts
    You are the manager of a basketball team. For the upcoming tournament, 
    you want to choose the team with the highest overall score. 
    The score of the team is the sum of scores of all the players in the team.
    However, the basketball team is not allowed to have conflicts. 
    A conflict exists if a younger player has a strictly higher score 
    than an older player. A conflict does not occur between players of the same age.
    Given two lists, scores and ages, where each scores[i] and ages[i] represents 
    the score and age of the ith player, 
    respectively, return the highest overall score of all possible basketball teams.

    Example 1:
    Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
    Output: 34
    Explanation: You can choose all the players.

    Example 2:
    Input: scores = [4,5,6,5], ages = [2,1,2,1]
    Output: 16
    Explanation: It is best to choose the last 3 players. Notice that you are allowed 
    to choose multiple people of the same age.

    Example 3:
    Input: scores = [1,2,3,5], ages = [8,9,10,1]
    Output: 6
    Explanation: It is best to choose the first 3 players. 

    solution:
        1. sorting by age descending
        2. longest increasing subseq
*/
static
int cmp_pair(const void* l, const void* r) {
  const int (*lhs)[2] = l;
  const int (*rhs)[2] = r;
  return ((*lhs)[0] != (*rhs)[0]) ? (*rhs)[0] - (*lhs)[0] : (*rhs)[1] - (*lhs)[1];
}

static
int imax(int a, int b) { return (a > b) ? a : b; }

int bestTeamScore(int* scores, int scoresSize, int* ages, int agesSize){
  int (*pairs)[2] = malloc(scoresSize * sizeof(*pairs));
  for (int i = 0; i < scoresSize; ++i) {
    pairs[i][0] = ages[i];
    pairs[i][1] = scores[i];
  }

  /* Sort via age, then score, descending */
  qsort(pairs, scoresSize, sizeof(*pairs), &cmp_pair);

  /* Initialise the 'best' for each player to be a team of just them */
  int* const best = malloc(scoresSize * sizeof(*best));
  for (int i = 0; i < scoresSize; ++i) {
    best[i] = pairs[i][1];
  }

  /*
  Pairs is sorted by ages, then scores, descendingly, as such, the age of any
	pair to the right of another is irrelevant and we only need to consider the
	score to see whether the pairs are in conflict.  
	*/
  for (int i = 0; i < scoresSize; ++i) {
    for (int j = i + 1; j < scoresSize; ++j) {
      if (pairs[i][1] >= pairs[j][1]) {
        best[j] = imax(best[j], best[i] + pairs[j][1]);
      }
    }
  }

  /* The find the best of the best */
  int ret = best[0];
  for (int i = 1; i < scoresSize; ++i) {
    ret = imax(ret, best[i]);
  }

  free(pairs);
  free(best);
  return ret;
}



/*  [136]
    Longest Increasing Subsequence
    2, 9, 3, 0, 5, 13 -> 2, 3, 5, 13

*/
int longest_increasing_subseq(int nums[], int len) {
    int dp[len];
    int res = INT_MIN;

    //dp[i]: longest sub sequence including nums[i]
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < i; j++) {
            if(dp[i] > dp[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = dp[i] > res ? dp[i] : res;
    }
    return res;
}

/*  [137] find Median Sorted Arrays (leetcode 4)
    Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
    The overall run time complexity should be O(log (m+n)).

    Example 1:
    Input: nums1 = [1,3], nums2 = [2]
    Output: 2.00000
    Explanation: merged array = [1,2,3] and median is 2.

    Example 2:
    Input: nums1 = [1,2], nums2 = [3,4]
    Output: 2.50000
    Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int newSize = nums1Size + nums2Size;
    int tmp[newSize];
    int i = 0, j = 0, count = 0;
    while(i < nums1Size || j < nums2Size) {
        if(i == nums1Size) {
            tmp[count++] = nums2[j++];
        } else if(j == nums2Size) {
            tmp[count++] = nums1[i++];
        } else if(nums1[i] <= nums2[j]) {
            tmp[count++] = nums1[i++];
        } else if(nums1[i] > nums2[j]) {
            tmp[count++] = nums2[j++];
        }
    }

    if(newSize % 2) {
        return tmp[newSize / 2];
    } else {
        return (tmp[newSize / 2 - 1] + tmp[newSize / 2]) / 2.0;
    }
}

/*  [138] - hanoi
*/
void move(char x, char y) {
    printf("%c -> %c\n", x, y);
}
void hanoi(int n, char one, char two, char three) {
    if(n == 1)  move(one, three);
    else {
        hanoi(n - 1, one, three, two);
        move(one, three);
        hanoi(n - 1, two, one, three);
    }
}

/*  [139] - the next and previous binary
*/
int count_one0(int x){
    int cnt = 0;
    for(int i=0; i<32; ++i){
        if(x & 1) ++cnt;
        x >>= 1;
    }
    return cnt;
}
int count_one(int x){
    x = (x & (0x55555555)) + ((x >> 1) & (0x55555555));
    x = (x & (0x33333333)) + ((x >> 2) & (0x33333333));
    x = (x & (0x0f0f0f0f)) + ((x >> 4) & (0x0f0f0f0f));
    x = (x & (0x00ff00ff)) + ((x >> 8) & (0x00ff00ff));
    x = (x & (0x0000ffff)) + ((x >> 16) & (0x0000ffff));
    return x;
}
int next(int x){
    int max_int = ~(1<<31);
    int num = count_one(x);
    if(num == 0 || x == -1) return -1;
    for(++x; count_one(x) != num && x < max_int; ++x);
    if(count_one(x) == num) return x;
    return -1;	
}
int previous(int x){
    int min_int = (1<<31);
    int num = count_one(x);
    if(num == 0 || x == -1) return -1;
    for(--x; count_one(x) != num && x > min_int; --x);
    if(count_one(x) == num) return x;
    return -1;	
}
int next1(int x){
    int xx = x, bit = 0;
    for(; (x&1) != 1 && bit < 32; x >>= 1, ++bit);
    for(; (x&1) != 0 && bit < 32; x >>= 1, ++bit);
    if(bit == 31) return -1; //011.., none satisify
    x |= 1;
    x <<= bit; // wtf, x<<32 != 0,so use next line to make x=0
    if(bit == 32) x = 0; // for 11100..00
    int num1 = count_one(xx) - count_one(x);
    int c = 1;
    for(; num1 > 0; x |= c, --num1, c <<= 1);
    return x;
}
int previous1(int x){
    int xx = x, bit = 0;
    for(; (x&1) != 0 && bit < 32; x >>= 1, ++bit);
    for(; (x&1) != 1 && bit < 32; x >>= 1, ++bit);
    if(bit == 31) return -1; //100..11, none satisify
    x -= 1;
    x <<= bit;
    if(bit == 32) x = 0;
    int num1 = count_one(xx) - count_one(x);
    x >>= bit;
    for(; num1 > 0; x = (x<<1) | 1, --num1, --bit);
    x <<= bit;
    return x;
}
int test_binary(){
    int a = -976756;//(1<<31)+(1<<29);//-8737776;
    cout<<next(a)<<" "<<previous(a)<<endl; // very slow
    cout<<next1(a)<<" "<<previous1(a)<<endl;;
    return 0;
}

/*  [140] - bit swap required
    using xor,     
        0 ^ 1 = 1
        0 ^ 0 = 0
        1 ^ 1 = 0 
*/
int bitSwapRequired(int a, int b) {
    int cnt = 0;
    int data = a ^ b;
    for(; data != 0; data >= 1) cnt += data & 1;

    return cnt;
}

/*  [141] - swap odd with even bits
*/
int swap_odd_even_bits(int x) {
    return ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1);
}

/*  [142] - 
An array A[1...n] contains all the integers from 0 to n except for one number 
which is missing.In this problem, we cannot access an entire integer in A with a single operation.
The elements of A are represented in binary, and the only operation we can use to access them 
is "fetch the jth bit of A[i]", which takes constant time. Write code to find the missing integer.
Can you do it in O(n) time?
以0-5，少了3为例:
000
001
010
011
100
101
首先观察最后一位，由于数是从0开始的，因此，如果没有去掉一个数，0的数目应该比一的数目大1（奇数个数）
或者相等（偶数个数）。现在的具体情况是3个0，2个1，因此去掉的数的最后一位一定是1，因为如果为0，
那么就有4个0和2个1，显然不合理。
这样，我们就可以排除最后一位不是1的数，这些数都是存在的，即不可能是所求。
000
001
010
011
100
101
现在来看倒数第二位，2个0,0个1，因此去掉的数的倒数第二位一定是1。
排除倒数第二位不是1的数
000
001
010
011
100
101
此时A[]里的数已经全部被排除了，那么结果就是最后一位和倒数第二位为1，其余为0的数，即011
*/
int fetch(int i, int j) {//获取整数i的第j位
    if(j > 32 || j < 0) return 0;
    else            return (i >> j) & 1;
}

int func(int colum, int *A, int len) {  //colum是倒数第几位，len是数组A的长度
    if(len == 0)    return 0;

    int cnt0, cnt1;//colum位有几个1，几个0
    cnt0 = 0;
    cnt1 = 0;

    for(int i = 0; i < len; i++) {
        if((fetch(A[i], colum) & 1) > 0)   cnt1++;
        else    cnt0++;
    }

    int *A1, *A0;
    if(cnt1 > 0)        A1 = new int[cnt1];
    else        A1=NULL;

    if(cnt0 > 0)  A0 = new int[cnt0];
    else    A0 = NULL;

    cnt1 = 0;
    cnt0 = 0;

    for(int i = 0; i < len; i++) {//将colum位为1的和为0的分别放在两个新的数组A1,A0中
        if((fetch(A[i],colum)&1) > 0) {
            A1[cnt1] = A[i];
            cnt1++;
        }
        else {
            A0[cnt0] = A[i];
            cnt0++;
        }
    }

    if(cnt1 >= cnt0) {return func(colum+1, A0, cnt0);}//结果的colum位为0
    else    {return (1 << colum) + func(colum + 1, A1, cnt1);} //结果的colum位为1

    delete[]A1;
    A1 = NULL;
    delete[]A0;
    A0 = NULL;
}

int test() {
    int A[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10, 11};
    printf("%d\n", func(0, A, sizeof(A) / sizeof(int)));
    return 0;
}

/*  [143] - merge sorted array
*/
void merge(int a[], int b[], int len_a, int len_b) {
    int len = len_a + len_b - 1;
    int i = len_a - 1;
    int j = len_b - 1;

    while(i >= 0 && j >= 0) {
        if(a[i] > b[j]) a[len--] = a[i--];
        else    a[len--] = b[j--];
    }
    while(j >= 0) a[len--] = b[j--];    //if len_b > len_a
}

/*  [144] - find element in matrix
    the matrix each row and each column is sorted
*/
bool find_element(int row, int col, int mat[row][col], int target) {
    int x = 0;
    int y = col - 1;
    while(x < row && y >= 0) {
        if(target == mat[x][y]) return true;
        if(target < mat[x][y])  y--;
        else    x++;
    }
    return false;
}