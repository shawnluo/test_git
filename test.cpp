#include "test.hpp"

#include <functional>
#include <semaphore.h>
#include <thread>
using namespace std;

#define ELEMENT char
#define FORMAT "%c"
#define NODE_NUM 15

typedef struct Node {
    ELEMENT data;
    struct Node* left;
    struct Node* right;

    Node(ELEMENT val) : data(val), left(nullptr), right(nullptr) {}
} *Tree;

/* 
    Binary Tree Constructor
    1. construct in preorder
    2. '#' means no left child or right child
    A, B, D, #, #, E, #, #, C, F, #, #, G, #, #
 */
void binaryTreeConstructor(Tree& root, ELEMENT data[]) {
    static int index = 0;
    if(index >= NODE_NUM) {
        return;
    }

    ELEMENT ele = data[index++];
    if(ele == '#') {
        root = nullptr;
    } else {
        // root = (Node*)malloc(sizeof(Node));
        root = new Node(ele);
        root->data = ele;

        // unique_ptr<Node> root(new Node(ele));
        // shared_ptr<Node> root(new Node(ele));

        binaryTreeConstructor(root->left, data);
        binaryTreeConstructor(root->right, data);
        // cout << root.use_count() << endl;
    }
}

void constructorBinTree(Tree& root, ELEMENT data[]) {
    static int index = 0;
    ELEMENT val = data[index];

    if(data[index] == '#') {
        root = nullptr;
    } else {
        unique_ptr<Node> node(new Node(val));

        constructorBinTree(root->left, data);
        constructorBinTree(root->right, data);
    }
}

void breadthFirstSearch(Tree root) {
    queue<Tree>treeQueue;
    treeQueue.push(root);
    Tree curNode;

    while(!treeQueue.empty()) {
        curNode = treeQueue.front();
        treeQueue.pop();
        cout << curNode->data << " ";

        if(curNode->left) {
            treeQueue.push(curNode->left);
        }
        if(curNode->right) {
            treeQueue.push(curNode->right);
        }
    }
}

int main() {
    ELEMENT data[NODE_NUM] = {'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', 'F','#', '#', 'G', '#', '#'};
    Tree tree;

    binaryTreeConstructor(tree, data);
    breadthFirstSearch(tree);

    return 0;
}