#include "test.hpp"

#include <cstdio>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <unordered_set>

#include <iostream>
#include <string>


#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

#include <iostream>
#include <queue>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void printLayers(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<Node*> q;
    q.push(root);

    int res = root->data;
    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();
            // std::cout << current->data << " ";

            if (current->left) {
                q.push(current->left);
                res = current->left->data;
            }
            if (current->right) {
                q.push(current->right);
            }
        }

        std::cout << std::endl;
        cout << size << endl;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // root->right->left = new Node(6);
    root->right->right = new Node(7);

    printLayers(root);

    return 0;
}