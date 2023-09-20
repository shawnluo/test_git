#include "test.hpp"

#include <iostream>
#include <cstdlib>

// Comparison function for sorting the 2D array
int compare(const void* a, const void* b) {
    const int* arr1 = *(const int**)a;
    const int* arr2 = *(const int**)b;

    // Compare the first element of each array
    return arr1[0] - arr2[0];
}

int main() {
    const int rows = 3;
    const int cols = 2;

    int arr[rows][cols] = {
        {3, 2},
        {1, 4},
        {2, 3}
    };

    // Sort the 2D array using qsort
    qsort(&arr[0], rows, sizeof(arr[0]), compare);

    // Print the sorted array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}