
#include "test.hpp"
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

#define ELEMENT char

typedef struct TREE {
    ELEMENT val;
    TREE* left;
    TREE* right;

    TREE(int data) : val(data), left(nullptr), right(nullptr) {}
} Tree, *pTree;

void createBTree(pTree& tree, vector<ELEMENT>& nums) {
    static int index = 0;
    if(index >= nums.size()) return;

    // new tree node
    ELEMENT ele = nums[index++];
    if(ele == '#') {
        tree = nullptr;
    } else {
        tree = new TREE(ele);
        // recusively call new tree node left
        createBTree(tree->left, nums);

        // recusively call new tree node right
        createBTree(tree->right, nums);
    }
}

void BFS(pTree& tree) {
    queue<pTree> q;
    q.push(tree);

    while(!q.empty()) {
        pTree curNode = q.front();
        q.pop();
        cout << curNode->val;

        if(curNode->left) {
            q.push(curNode->left);
        }

        if(curNode->right) {
            q.push(curNode->right);
        }
    }
}
/* 
    Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
    Output: 700
 */
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> adj(n);
    for(auto& e : flights) {
        adj[e[0]].push_back({e[1], e[2]});
    }

    vector<int> dist(n, INT_MAX);
    queue<pair<int, int>> q;
    q.push({src, 0});
    int stops = 0;

    while(stops <= k && !q.empty()) {
        int sz = q.size();
        // iterate on current level
        while(sz--) {
            auto[node, distance] = q.front();
            q.pop();
            // iterate over neighbors of popped node
            for(auto& [neighbour, price] : adj[node]) {
                if(price + distance >= dist[neighbour]) {
                    continue;
                }
                dist[neighbour] = price + distance;
                q.push({neighbour, dist[neighbour]});
            }
        }
        stops++;
    }
    return dist[dst] == INT_MAX ? -1 : dist[dst];
}

int main(void) {
    vector<ELEMENT> nums = {'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', 'F','#', '#', 'G', '#', '#'};
    pTree tree;
    createBTree(tree, nums);
    BFS(tree);

    // for_each(nums.begin(), nums.end(), [](int x){cout << x << endl;});

    return 0;
}