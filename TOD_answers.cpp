#include "test.hpp"

typedef struct binTree {
    int data;
    struct binTree* left;
    struct binTree* right;

    binTree(int val) : data(val), left(nullptr), right(nullptr) {}
} bTree, *pBTree;

pBTree insBTree(pBTree root, int val) {
    if(root == nullptr) {
        return new binTree(val);
    }
    if(val < root->data) {
        root->left = insBTree(root->left, val);
    } else if(val > root->data){
        root->right = insBTree(root->right, val);
    }
    return root;
}

void showMe(pBTree root) {
    if(!root) return;

    cout << root->data << endl;
    showMe(root->left);
    showMe(root->right);
}

void reverse(pBTree root) {
    if(!root) {
        return;
    }

    swap(root->left, root->right);
    reverse(root->left);
    reverse(root->right);
}

typedef struct node {
    int data;
    struct node *next;
} Node, *pNode;

pNode reverseLL(pNode pHead) {
    if(!pHead) return nullptr;

    pNode pPre = nullptr;
    pNode pCur = pHead;
    pNode pNext = pHead;

    while(pCur) {
        pNext = pCur->next;
        pCur->next = pPre;
        pPre = pCur;
        pCur = pNext;
    }
    return pPre;
}

void test(char **s) {
    for(int i = 0; i < 5; i++) {
        // cout << s[i] << endl;
        char *p = strstr(s[i], "23");

        // cout << p << endl;
        printf("xx: %s\n", p);
        // if(strstr(s[i], "23") != nullptr)
        //     cout << 1 << endl;
        // else
        //     cout << 2 << endl;
    }

}

void mergeArr(vector<int>& arr1, vector<int>& arr2) {
    int len1 = arr1.size();
    int len2 = arr2.size();
    int len = len1 + len2;

    arr1.resize(len);

    len1--;
    len2--;
    len--;
    while(len >= 0) {
        if(arr1[len1] > arr2[len2]) {
            arr1[len] = arr1[len1];
            len1--;
        } else {
            arr1[len] = arr2[len2];
            len2--;
        }
        len--;
    }
}

void remove_dup_LL(pNode& pHead) {
    if(!pHead) return;

    // pointer1 to travel in LL
    // pointer2 travel from head to pointer1

    pNode p1 = pHead->next;
    pNode p2 = nullptr;
    while(p1 != nullptr) {
        // pNode p2 = pHead;
        for(p2 = pHead; p2 != p1; p2 = p2->next) {
            if(p2->data == p1->data) {
                pNode tmp = p2;
                p2 = p2->next;
                // delLL(pHead, p2);
                free(tmp);
            }
        }
    }
}

pHead mergeLL(const pNode pHead1, const pNode pHead2) {
    if(!pHead1) return pHead2;
    if(!pHead2) return pHead1;

    pNode p1 = pHead1;
    pNode p2 = pHead2;
    pNode p = nullptr;

    while(p1) {
        if(!p2) {
            while(p1) {
                appendLL(p, p1);
                p1 = p1->next;
            }
            return p;
        }

        if(p1->data < p2->data) {
            appendLL(p, p1->data);
            p1 = p1->next;
        } else {
            appendLL(p, p2->data);
            p2 = p2->next;
        }
    }
    if(p2) {
        while(p2) {
            appendLL(p, p2);
            p2 = p2->next;
        }
    }
    return p;
}

int partition(int *nums, int start, int end) {
    int save = nums[start];
    while(start < end) {
        while(nums[end] >= save) {
            end--;
        }
        if(start < end) {
            nums[start++] = nums[end];
        }

        while(nums[start] <= save) {
            start++;
        }
        if(start < end) {
            nums[end--] = nums[start];
        }
    }
    nums[start] = save;
    return start;
}

void quickSort(int *nums, int start, int end) {
    if(start <= end) return;
    int pivot = partition(nums, start, end);
    quickSort(start, pivot - 1);
    quickSort(pivot + 1, end);
}

pNode addLL(pNode pHead1, pNode pHead2) {
    int carry = 0;
    while(pHead1 || pHead2) {
        if(pHead1) {
            data += pHead1->data;
            pHead1 = pHead1->next;
        }
        if(pHead2) {
            data += pHead2->data;
            pHead1 = pHead2->next;
        }
        data += carry;
        if(data >= 10) {
            carry = 1;
            data -= 10;
        } else {
            carry = 0;
        }
        appendLL(result, data);
    }
    if(carry) {
        appendLL(result, carry);
    }
}

void reverseStr(string& s, int left, int right) {
    if(s.size() <= 1) return;

    while(left < right) {
        swap(s[left], s[right]);
        left++, right--;
    }
}

void removeSpaces(string& s) {
    int slow = 0;
    for(int i = 0; i < s.size(); i++) {

    }
}

void reverseWord(string &s) {
    removeExtraSpaces(s);
    int left = 0;
    int right;
    for(int i = 0; i <= s.size(); i++) {
        if(i == s.size() || s[i] == ' ') {
            right = i - 1;
            reverseStr(s, left, right);
            left = i + 1;
        } 
    }
}

int LenDelRep(vector<int> nums) {
    int len = 1;

    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] != nums[i - 1]) {
            len++;
        }
    }
    return len;
}

// TODO
int shortest_consective_arr_dp(int *res, int size, int key) {
    int left = 0, right = 0;
    int len, len_min = INT_MAX;
    int sum = 0;

    for(right = 0; right < size; right++) {
        sum += res[right];
        while(left <= right && sum >= key) {
            len = right - left + 1;
            len_min = len < len_min ? len : len_min;
            sum -= res[left++];
        }
    }
    printf("%d\n", len_min);
    return len_min;
}

int main(void) {
    vector<int> arr1 = {1, 1, 4, 6};
    vector<int> arr2 = {1, 2, 3, 16};

    mergeArr(arr1, arr2);
    for(auto x : arr1) {
        cout << x << " ";
    }
    cout << endl;

    // pBTree root = nullptr;
    // root = insBTree(root, 10);
    // root = insBTree(root, 8);
    // root = insBTree(root, 7);
    // root = insBTree(root, 6);
    // root = insBTree(root, 19);
    // root = insBTree(root, 16);

    // showMe(root);

    // reverse(root);
    // showMe(root);

    // char *s[5] = {"abc", "123", "aaa", "bbb", "ccc"};
    // test(s);

    // mergeLL(pHead1, pHead2);


    return 0;
}