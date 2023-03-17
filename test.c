#include "common.h"
#include "test.h"

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


int partition(int *arr, int start, int end) {
    int pivot = arr[start];
    int L = start;
    int R = end;
    while(L < R) {
        while(L < R && arr[R] > pivot)  R--;
        if(L < R)   arr[L++] = arr[R];
        while(L < R && arr[L] < pivot)  L++;
        if(L < R)   arr[R--] = arr[L];
    }
    arr[L] = pivot;
    return L;
}

void quickSort(int *arr, int start, int end) {
    if(start < end) {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}

int main(void) {
    printf("%f\n", myPow2(3, 3));

    return 0;
}