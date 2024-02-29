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


typedef struct TREE {
    char val;
    TREE* left;
    TREE* right;
    TREE(char x) : val(x), left(nullptr), right(nullptr) {}
} Tree, *pTree;

int tree_num = 0;
void createBin(pTree& root, vector<char>& v) {
    static int index = 0;
    if(index >= tree_num) {
        return;
    }

    char ele = v[index++];

    if(ele == '#') {
        root = nullptr;
    } else {
        root = new TREE(ele);
        createBin(root->left, v);
        createBin(root->right, v);
    }
}

void dfs(pTree root) {
    if(!root) return;

    cout << root->val << " ";
    dfs(root->left);
    dfs(root->right);
}

void breadth_first_search(pTree root) {
    if(!root) return;

    queue<pTree> q;
    q.push(root);
    pTree pCur;

    int index = 0;
    // int res = 0;
    while(!q.empty()) {
        pCur = q.front();
        cout << pCur->val << " ";
        q.pop();

        if(pCur->left) {
            q.push(pCur->left);
            index++;
            // if()
            // res = max();
        }
        if(pCur->right) {
            q.push(pCur->right);
        }
    }
    cout << endl;
}

/* 
    1 2 3
    4 5 6
    7 8 9
 */
void rotate(vector<vector<int>>& nums) {
    // for() {
        
    // }
}



int main(void) {
    vector<char> nums = {'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', 'F','#', '#', 'G', '#', '#'};
    tree_num = nums.size();

    pTree root;
    createBin(root, nums);
    // dfs(root);
    breadth_first_search(root);

    // for_each(nums.begin(), nums.end(), [](int x){cout << x << endl;});

    return 0;
}