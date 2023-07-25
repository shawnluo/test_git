#include "test.hpp"

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void insert(TreeNode*& root, int value) {
    if (root == nullptr) {
        root = new TreeNode(value);
        return;
    }
    if (value < root->data) {
        insert(root->left, value);
    } else {
        insert(root->right, value);
    }
}

void insert_x(TreeNode*& root, int value) { // using reference (&) to ensure that any changes made to
                                            // the root pointer within the function are reflected outside
                                            // the function as well.
    if (root == nullptr) {
        root = new TreeNode(value);
        return;
    }
    if (value < root->data) {
        insert_x(root->left, value);
    } else {
        insert_x(root->right, value);
    }
}

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << endl;
    inorderTraversal(root->right);
}

void preorderTraversal(TreeNode* root) {
    if(root == nullptr) return;

    cout << root->data << endl;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void invertTree(TreeNode* &root) {
    if(root == nullptr) return;

    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
}

bool search(TreeNode* root, int value) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        search(root->left, value);
    } else {
        search(root->right, value);
    }
}


int main() {
    TreeNode* root = nullptr;
    insert(root, 5);
    insert(root, 6);
    insert(root, 7);
    // preorderTraversal(root);
    inorderTraversal(root);
    // cout << search(root, 60) << endl;
    invertTree(root);
    inorderTraversal(root);

    return 0;
}