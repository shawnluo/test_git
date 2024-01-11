
#include "test.hpp"
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;


typedef struct node {
    int data;
    node* left;
    node* right;
    node(int val) : data(val), left(nullptr), right(nullptr) {}
} Node, *pNode;

/* 2 ways to use struct node: 
    1. node*
    2. pNode */
// node* insert(node* root, int val) {

pNode insert(pNode root, int val) {
    if(root == nullptr) {
        return new node(val);
    }
    if(val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void dfs(node* root) {
    if(root == nullptr) return;
    // cout << root->data << endl;
    dfs(root->left);
    cout << root->data << endl;     // 中序 - 从小到大排列输出
    dfs(root->right);

    // cout << root->data << endl;
}

// void bfs(Node* root) {
//     if(root == nullptr) {
//         return;
//     }
//     if(root->left == nullptr) {
//         cout << root->data << endl;
//     }
// }

int height(pNode root) {
    if(root == nullptr) return 0;
    else {
        int lheight = height(root->left);
        int rheight = height(root->right);

        return max(lheight, rheight) + 1;
    }
}

void printCurrentLevel(pNode root, int level) {
    if(root == nullptr) {
        return;
    }
    if(level == 0) cout << root->data << endl;
    else if(level > 0) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void bfs(pNode root) {
    int h = height(root);
    for(int i = 0; i < h; i++) {
        printCurrentLevel(root, i);
    }
}


// 找到二叉树中两个值之和等于val的元素
set<int> mySet;
bool find(pNode root, int val) {
    if(root == nullptr) return false;

    if(mySet.find(val - root->data) != mySet.end()) {
        return true;
    }
    mySet.insert(root->data);

    bool foundLeft = find(root->left, val);
    bool foundRight = find(root->right, val);

    return foundLeft || foundRight;
}


int main(void) {
    Node* root = nullptr;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);
    root = insert(root, 1);

    dfs(root);

    int res_height = height(root);
    cout << "height: " << res_height << endl;
    bfs(root);

/* 
            5
        3       7
      2   4   6    8
    1

 */

    // cout << ret << endl;

    return 0;
}