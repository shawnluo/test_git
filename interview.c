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

/*  003
    using qsort to sort array
*/
int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void sort_arr(void) {
    int values[] = {88, 56, 100, 2, 25};
    int size = sizeof(values) / sizeof(values[0]);
    qsort(values, size, sizeof(int), cmpfunc);
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

    *returnSize = 0;
    return res;
}

/*  [102] three sum
*/

void quickSort(int* nums, int first, int end) {     //快速排序 
	int temp, l, r;
	if (first >= end) {
		return;
	}
	temp = nums[first];
	l = first;
	r = end;
	while (l < r) {
		while (l < r && nums[r] >= temp) {
			r--;
		}
		if (l < r) {
			nums[l] = nums[r];
		}
		while (l < r && nums[l] <= temp) {
			l++;
		}
		if (l < r) {
			nums[r] = nums[l];
		}
	}
	nums[l] = temp;
	quickSort(nums, first, l - 1);
	quickSort(nums, l + 1, end);
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

	for (i = 0; i <= numsSize - 3; i++) {
		left = i + 1;
		right = numsSize - 1;
		if (nums[i] > 0) {										// 如果当前数字大于0，则三数之和一定大于0，所以结束循环
			break;
		}
		if (i > 0 && nums[i] == nums[i - 1]) {					// 去重
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
				(*returnColumnSizes) = (int*)realloc((*returnColumnSizes), base_alloc_size * sizeof(int));
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
	int** returnColumnSizes = (int**)malloc(sizeof(int*) * (numsSize * (numsSize - 1) * (numsSize - 2)) / 6);
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
void find_clear(char **s, int i, int j, int gridSize, int gridColSize) {
    if(i < 0 || i >= gridSize || j < 0 || j >= gridColSize) {
        return;
    }
    if(s[i][j] == '1') {
        s[i][j] = '0';
        find_clear(s, i + 1, j, gridSize, gridColSize);
        find_clear(s, i - 1, j, gridSize, gridColSize);
        find_clear(s, i, j + 1, gridSize, gridColSize);
        find_clear(s, i, j - 1, gridSize, gridColSize);
    }
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
                find_clear(grid, i, j, gridSize, *gridColSize);
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
    double cur = x;
    for(long long i = N; i; i /= 2) {
        if((i % 2) == 1)    res = res * cur;
        cur = cur * cur;
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