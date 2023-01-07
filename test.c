#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>
#include <limits.h>
#include <math.h>


//clock-wise
void rotate(int mat[4][4], int size) {
    /*
        top:        x,              y
        right:      y,              size - x - 1
        bottom:     size - x - 1,   size - y - 1
        left:       size - y - 1,   x
    */
   int x, y;
    for(x = 0; x < size / 2; x++) {
        for(y = 0; y < size / 2; y++) {
            int save = mat[x][y];
            mat[x][y] = mat[size - y - 1][x];
            mat[size - y - 1][x] = mat[size - x - 1][size - y - 1];
            mat[size - x - 1][size - y - 1] = mat[y][size - x - 1];
            mat[y][size - x - 1] = save;
        }
   }
    for(x = 0; x < size; x++) {
        for(y = 0; y < size; y++) {
            printf("%d\t", mat[x][y]);
        }
        printf("\n");
    }
}

void spiral_matrix(int n) {

}

int bin_search(int *arr, int left, int right, int key) {
    int mid;

    while(left <= right) {
        mid = (left + right) / 2;
        if(arr[mid] == key) {
            return mid;
        }
        if(arr[mid] > key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int partition(int *arr, int left, int right) {
    int save = arr[left];
    while(left < right) {
        while(left < right && arr[right] > save) {
            right--;
        }
        if(left < right) {
            arr[left++] = arr[right];
        }
        while(left < right && arr[left] < save) {
            left++;
        }
        if(left < right) {
            arr[right--] = arr[left];
        }
    }
    arr[left] = save;
    
    return left;
}

void quick_sort(int *arr, int left, int right) {
    if(left < right) {
        int mid = partition(arr, left, right);
        quick_sort(arr, left, mid - 1);
        quick_sort(arr, mid + 1, right);
    }
}

void bubble(int *arr, int size) {
    int i, j;
    for(i = 0; i < size; i++) {
        for(j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    for(i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void select_sort(int *arr, int size) {
    int i, j;
    int min;
    int index = -1;
    for(i = 0; i < size; i++) {
        min = arr[i];
        for(j = i + 1; j < size; j++) {
            if(arr[j] < min) {
                min = arr[j];
                index = j;
            }
        }
        if(arr[i] > min) {
            int tmp = arr[index];
            arr[index] = arr[i];
            arr[i] = tmp;
        }
    }
    for(i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void ins_array(int *arr, int size, int pos, int key) {
    for(int i = pos; i <= size; i++) {
        int save = arr[i];
        arr[i] = key;
        key = save;
    }

    for(int i = 0; i <= size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void move_array(int *arr, int size) {
    int key = arr[0];
    for(int i = 1; i <= size; i++) {
        int save = arr[i];
        arr[i] = key;
        key = save;
    }

    for(int i = 0; i <= size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

char *str_cpy(char *des, const char *src) {
    if(des == NULL || src == NULL) {
        printf("invalid paraters!\n");
        return -1;
    }
    char *tmp = des;

    while(*des++ = *src++) {
    }

    return tmp;
}

int mem_cpy(char *des, const char *src) {
    if(des == NULL || src == NULL) {
        printf("invalid parameters!\n");
        return -1;
    }

    int size = strlen(src);

    if(src == des) {
        return src;
    } else if(src > des) {
        //from tail
        while(size--) {
            *(des + size - 1) = *(src + size - 1);
        }
    } else {
        for(int i = 0; i < size; i++) {
            *des++ = *src++;
        }
    }
    return 0;
}

void binary_print(int num) {
    unsigned char *p1 = (unsigned char *)&num;
    unsigned char *p2 = (unsigned char *)&num + 1;
    unsigned char *p3 = (unsigned char *)&num + 2;
    unsigned char *p4 = (unsigned char *)&num + 3;

    for(int i = 7; i >= 0; i--) {
        if(*p1 & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

void merge_ll(pNode *ppHead1, pNode *ppHead2) {
    if() {
        return;
    }
    pNode *pp1 = ppHead1;
    pNode *pp2 = ppHead2;

    while(*pp1 || *pp2) {
        if((*pp2)->data <= (*pp1)->data) {
            ins_ll_front(ppHead1, *pp1, *pp2);    //ins *pp2 to *pp1
            pp2 = &((*pp2)->next);
        } else {
            pp1 = &((*pp1)->next);
        }
    }
}

int main(void) {
    char s1[] = "abxcy";
    char s2[] = "axabccx";

    int size1 = strlen(s1);
    int size2 = strlen(s2);

    int mat[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    
    int arr[] = {211, 98, 65, 100, 765};
    int sizeA = sizeof(arr) / sizeof(arr[arr[0]]);
    //int ret = bin_search(arr, 0, sizeA, 101);
    //printf("%d\n", ret);

    //quick_sort(arr, 0, sizeA - 1);
    for(int i = 0; i < sizeA; i++) {
        //printf("%d ", arr[i]);
    }
    //bubble(arr, sizeA);
    //select_sort(arr, sizeA);

    //ins_array(arr, sizeA, 2, 10000);
    //move_array(arr, sizeA);
    //printf("%s\n", str_cpy(s2, s1));
    
    binary_print(5);
    
    return 0;
}