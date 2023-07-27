#include "test.hpp"

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void insert(TreeNode* &root, int val) {
    if(root == nullptr) {
        root = new TreeNode(val);
        return;
    }
    if(val < root->data) {
        insert(root->left, val);
    } else {
        insert(root->right, val);
    }
}

void invertTree(TreeNode* &root) {
    if(root == nullptr) {
        return;
    }

    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
}

void inTravelsal(const TreeNode* root) {
    if(root == nullptr) return;
    // cout << root->data << endl;
    inTravelsal(root->left);
    cout << root->data << endl;
    inTravelsal(root->right);
}

bool search(const TreeNode* root, int target) {
    if(root == nullptr) return false;

    if(root->data == target) return true;

    if(target < root->data) {
        search(root->left, target);
    } else {
        search(root->right, target);
    }
}

TreeNode* findMinNode(TreeNode* root) {
    if(root == nullptr) {
        return nullptr;
    }
    TreeNode* cur = root;
    while(cur->left) {
        cur = cur->left;
    }
    return cur;
}

TreeNode* del(TreeNode* &root, int target) {
    if(root == nullptr) return root;

    TreeNode* tmp = nullptr;
    if(target < root->data) {
        root->left = del(root->left, target);
    } else if(target > root->data) {
        root->right = del(root->right, target);
    } else {
        if(root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        } else if (root->left == nullptr) {
            tmp = root;
            root = root->right;
            delete(tmp);
        } else if(root->right == nullptr) {
            tmp = root;
            root = root->left;
            delete(tmp);
        } else {    // 找到右节点中的最小节点(在最左端!)，并把其值拷贝到当前节点，最后删除找到的最小节点。
            tmp = findMinNode(root->left);
            root->data = tmp->data;
            del(root->right, tmp->data);
        }
    }
    return root;
}

int main() {
    TreeNode* root = nullptr;
    insert(root, 5);
    insert(root, 4);
    insert(root, 3);

    // inTravelsal(root);

    // invertTree(root);
    // inTravelsal(root);

    // cout << search(root, 31) << endl;

    del(root, 5);
    inTravelsal(root);

    return 0;
}