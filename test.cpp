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
        // root->data = ele;
        root = new Node(ele);

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

// "356+*"
// NOT consider of priority
string calculator(string s) {
    stack<long long> st;
    for(int i = 0; i < s.size(); i++) {
        if(isalpha(s[i]) != 0) {
            long long a = st.top();
            st.pop();
            long long b = st.top();
            st.pop();

            if(s[i] == '+') st.push(a + b);
        } else {
            string charAsString(1, s[i]);   // convert char to string
            st.push(stoll(charAsString));   // convert string to long long integer

            // or just use the below
            // st.push(s[i] - '0');
        }
    }
    return to_string(st.top());
}

// "3+2* 2"
int cal_priority(string& s) {
    char op = '+';
    long long cur = 0;
    stack<long long> st;

    for(int i = 0; i < s.size(); i++) {
        if(isdigit(s[i])) {
            cur = cur * 10 + s[i] - '0';
        }

        if((!isdigit(s[i]) && !isspace(s[i]) || (i + 1) == s.size())) {
            long long x;
            switch(op) {
                case '+':
                    st.push(cur);
                break;
                case '-':
                    st.push(-cur);
                break;
                case '*':
                    x = st.top();
                    st.pop();
                    st.push(x * cur);
                break;
                case '/':
                    x = st.top();
                    st.pop();
                    st.push(x / cur);
                break;
            }
            op = s[i];
            cur = 0;
        }
    }

    int res = 0;
    while(!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

void sortByFre(string& s) {

}

int main() {
    // string res = calculator("23+");
    // cout << res << endl;

    string s = "3+2* 3";
    cout << cal_priority(s) << endl;

    // ELEMENT data[NODE_NUM] = {'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', 'F','#', '#', 'G', '#', '#'};
    // Tree tree;

    // binaryTreeConstructor(tree, data);
    // breadthFirstSearch(tree);

    return 0;
}