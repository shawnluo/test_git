
#include "test.hpp"

#include <semaphore.h>
#include <unistd.h>
using namespace std;


#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>

using namespace std;


#include "test.hpp"

#include <semaphore.h>
#include <unistd.h>
using namespace std;


#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

struct treeNode {
    int data;
    treeNode* left;
    treeNode* right;

    treeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void insert(treeNode* &root, int val) {
    if(root == nullptr) {
        root = new treeNode(val);
        return;
    }
    if(val < root->data) {
        insert(root->left, val);
    } else {
        insert(root->right, val);
    }
}

void invertTree(treeNode* &root) {
    if(root == nullptr) {
        return;
    }
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
}

void inTravelsal(const treeNode* root) {
    if(root == nullptr) return;

    cout << root->data << endl;
    inTravelsal(root->left);
    inTravelsal(root->right);
}

bool search(const treeNode* root, int target) {
    if(root == nullptr) return false;

    if(root->data == target) return true;
    
    if(root->data < target)
        return search(root->left, target);
    else
        return search(root->right, target);
}

void* memMove(const void* src, void* dst, size_t len) {
    if(!src || !dst) return nullptr;

    if((size_t *)src + len > (size_t *)dst) {
        const char* src_char = (const char* )src + len - 1;
        char* dst_char = (char* )dst + len - 1;
        while(len--) {
            *dst_char-- = *src_char--;
        }
    } else {
        const char* src_char = (const char* )src;
        char* dst_char = (char* )dst;
        while(len--) {
            *dst_char++ = *src_char++;
        }
    }
    return dst;
}

int main(void) {
    // treeNode bt1(10);
    // treeNode bt2 = treeNode(2);
    // treeNode* bt3 = new treeNode(30);

    vector<int> nums{5, 4, 3};
    treeNode* root = nullptr;

    for(auto it : nums) {
        insert(root, it);
    }


    return 0;
}