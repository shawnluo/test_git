#include "test.hpp"

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_set>


#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>


#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template<typename T>
struct TREE {
    T data;
    TREE* left;
    TREE* right;
    TREE(T x) : data(x), left(nullptr), right(nullptr) {}
};

template<typename T>
using Tree = TREE<T>;

template<typename T>
using pTree = TREE<T>*;

int dfs_sum(pTree<int> tree) {
    if(tree == nullptr) {
        return 0;
    } else {
        return tree->data + dfs_sum(tree->left) + dfs_sum(tree->right);
    }
    // cout << tree->data << " ";
    
    // int left = dfs_sum(tree->left);
    // int right = dfs_sum(tree->right);
}

// int sum = 0;

int equalTo(pTree<int> tree) {
    static int sum = 0;
    
    if(tree == nullptr) {
        return sum;
    }
    if(dfs_sum(tree) == tree->data * 2) {
        sum += 1;
    }
    equalTo(tree->left);
    equalTo(tree->right);
    return sum;
}

int main(void) {
    // vector<char> nums = {'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', 'F','#', '#', 'G', '#', '#'};
    vector<int> nums = {10, 3, 4, 2, 1};

    // pTree<int> tree = new TREE<int>(10);
    // pTree<int> tree1 = new TREE<int>(3);
    // pTree<int> tree2 = new TREE<int>(4);
    // pTree<int> tree3 = new TREE<int>(2);
    // pTree<int> tree4 = new TREE<int>(1);
    // tree->left = tree1;
    // tree->right = tree2;

    // tree1->left = tree3;
    // tree1->right = tree4;

    pTree<int> tree = new TREE<int>(5);
    pTree<int> tree1 = new TREE<int>(3);
    pTree<int> tree2 = new TREE<int>(2);

    tree->left = tree1;
    tree1->left = tree2;

    // int res = dfs_sum(tree) - tree->data;
    // cout << res << endl;

    int sum = equalTo(tree);
    cout << sum << endl;

    // for_each(nums.begin(), nums.end(), [](int x){cout << x << endl;});

    return 0;
}