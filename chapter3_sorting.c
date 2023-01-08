#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>
#include <limits.h>
#include <math.h>

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


void bubble_sort(int *arr, int size) {
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
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//
int partition(int *arr, int left, int right) {
    int save = arr[left];
    while(left < right) {
        while(left < right && arr[right] >= save) {
            right--;
        }
        if(left < right) {
            arr[left++] = arr[right];
        }

        while(left < right && arr[left] <= save) {
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
    if(left >= right) {
        return;
    }

    int mid = partition(arr, left, right);
    quick_sort(arr, left, mid - 1);
    quick_sort(arr, mid + 1, right);
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
