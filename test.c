#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>


int bin_search(int *arr, int size, int key) {
    int left = 0;
    int right = size - 1;
    int mid;

    while(left <= right) {
        mid = (left + right) / 2;
        if(arr[mid] == key)         return mid;
        else if(arr[mid] > key)     right = mid - 1;
        else if(arr[mid] < key)     left = mid + 1;
    }
    return -1;
}

//TODO 3
int quick_sort(int *arr, int left, int right) {
    return 0;
}


//TODO 2
int mystrstr(char *haystack, char *needle) {
    return 0;
}


//TODO 1
//pass array[][] as parameter
void showme(int *arr, int row, int col) {
    int (*p)[col] = (int (*)[col])arr;

    for(int i = 0; i < row; i++) {
        for(int j = 0;j < col; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}

//pass double pointer as parameter
void showme_2(int **arr, int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0;j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}


int main(void) {
    int arr[5][5] = {   
                    {1, 2, 3, 4, 5},
                    {11, 22, 33, 44, 55},
                    {111, 222, 333, 444, 555},
                    {1111, 2222, 3333, 4444, 5555},
                    {11111, 22222, 33333, 44444, 55555}};

    //showme((int *)arr, 5, 5);

    int **arr_2 = (int **)malloc(5 * sizeof(int *));
    for(int i = 0; i < 5; i++) {
        arr_2[i] = (int *)malloc(5 * sizeof(int));
    }
    arr_2[0][0] = 100;
    //showme_2(arr_2, 5, 5);

#if 0
    char *s[] = {"show", "me", "the", "money", "!"};
    char *p_s[5];
    p_s[1] = s[1];
    printf("%s\n", p_s[1]);
#endif

    int (*p_a)[5] = arr;
    printf("%d\n", p_a[0][4]);
    p_a++;
    printf("%d\n", p_a[0][4]);

    return 0;
}