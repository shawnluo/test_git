
#include "test.hpp"
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

// #define ELEMENT char
template <typename T>

struct TREE {
    T data;
    TREE* left;
    TREE* right;

    TREE(T value) : data(value), left(nullptr), right(nullptr) {}
};

// typedef struct TREE {
//     T data;
//     TREE* left;
//     TREE* right;

//     TREE(T value) : data(value), left(nullptr), right(nullptr) {}
// } Tree, *pTree;

// template <typename T>
void mySwap(int &a, int &b) {
    int val;
    swap(a, b);
}

template <typename T>
void test(T& x) {
    cout << "test" << endl;
}

void buildTree(TREE) {

}

int main(void) {
    // vector<int> nums = {10, 3, 4, 2, 1};

    int a = 10;
    int b = 20;

    mySwap(a, b);
    cout << a << endl;

    return 0;
}