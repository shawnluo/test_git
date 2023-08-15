
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// needle是一个字符，而不是字符串
void test_strtok() {
    char s[100] = "show me the money";
    char *needle = " ";
    char *token = strtok(s, needle);

    while(token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, needle);
    }
}


char *myStrtok(char *hay, const char needle) {
    static char *input = NULL; // 用来指向hay
    if(hay != NULL) {
        input = hay;
    }
    if(input == NULL) {
        return NULL;
    }
    char *res = (char *)malloc(sizeof(char) * 20);  // 作为返回数据
    int i = 0;
    for(; input[i] != '\0'; i++) {
        if(input[i] != needle) {
            res[i] = input[i];  // 如果不是needle，就将其拷贝到res，
        } else {
            res[i] = '\0';      // 否则就加上'\0', return
            input = input + i + 1;
            reutrn res;
        }
    }
    res[i] = '\0';
    input = NULL;

    return res;
}

char *myStrtok(char *hay, const char needle) {
    static char *input = NULL;
    if(hay != NULL) {
        input = hay;
    }
    if(input == NULL) {
        return NULL;
    }
    char *res = (char*)malloc(sizeof(char) * 20);
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


void delDup(pNode pHead) {
    if(pHead == NULL) return;

    pNode pPre = pHead;
    pNode pCur = pHead->next;
    pNode runner;
    while(pCur) {
        runner = pHead;
        while(runner != pCur) {
            if(runner->data == pCur->datra) {
                pPre->next = pCur->next;
                break;
            }
            runner = runner->next;
        }
        if(runner == pCur) {
            pPre = pCur;
            pCur = pCur->next;
        }
        
    }
}

// ----- 3. partition - 1
int partition(vector<int>& nums, int start, int end) {
    int left = start - 1;
    int right;
    int pivot = nums[end];

    for(right = start; right < end; right++) {
        if(nums[right] < pivot) {
            left++;
            swap(nums[left], nums[right]);
        }
    }
    swap(nums[left + 1], nums[end]);
    return left + 1;
}

void quickSort(vector<int>& nums, int start, int end) {
    if(start < end) {
        int pivot = partition(nums, start, end);
        quickSort(nums, start, pivot - 1);
        quickSort(nums, pivot + 1, end);
    }
}

// ------ 4. partition - 2
// int partition(vector<int>& nums, int start, int end) {

// }

int main(void) {
    Solution2 sol;
    vector<int> nums = {1, 8, 6, 3, 7, 2, 0, 4, 5, 9};
    // cout << sol.findKthLargest(nums, 3) << endl;
    quickSort(nums, 0, nums.size() - 1);

    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }

    return 0;
}

