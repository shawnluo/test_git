
<!-- 
    This is a comment !
-->

[comment]: <>   (This is a comment, it will not be included)
[//]: <>        (This is a comment)
[//]: #         (This is a comment)


### permute
<details close>
    <summary>code</summary>

```c++
vector<vector<int>> res;
vector<int> path;
void permute(vector<int>& v, vector<bool>& used) {
    if(path.size() == v.size()) {
        res.push_back(path);
        return;
    }
    for(int i = 0; i < v.size(); i++>) {
        if(used[i] == true) continue;
        path.push_back(v[i]);
        permute(v, used);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& v) {
    res.clear();
    path.clear();
    vector<bool> used(v.size(), false);
    permute(v, used);

    return res;
}
```

</details>

### merge two sorted linklists
<details close>
    <summary>code</summary>

```c++
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == nullptr) return list2;
    if(list2 == nullptr) return list1;

    if(list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list2->next, list1);
        return list2;
    }
}
```

</details>

### calculator
<details close>
    <summary>code</summary>

string s = 3 5 6 + *

NO priority!

```c++
int evalRPM(string s) {
    stack<long long> st;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == "+" || s[i] == "-" || s[i] == "*" || s[i] == "/") {
            long long a = st.top();
            st.pop();
            long long b = st.top();
            st.pop();
    
            if(s[i] == "+") st.push(a + b);
            if(s[i] == "-") st.push(a + b);
            if(s[i] == "*") st.push(a * b);
            if(s[i] == "/") st.push(a / b);
        } else {
            string aChar(1, s[i]);  // convert char to string
            st.push(stoll(aChar));  // convert string to long long integer

            // or just use the below
            // st.push(s[i] - '0');
        }
    }
    return to_string(st.top());
}
```

string s = "3+2*2"

Has priority

```c++
int calculate(string& s) {
    char op = '+';
    long long cur = 0;

}
```

</details>

### sort by frequence
<details close>
    <summary>code</summary>

```c++
class comparison {
public:
    bool operator()(const pair<int, int> lhs, const pair<int, int> rhs) {
        return lhs.second > rhs.second;
    }
};

void sortByFreq(vector<int>& nums) {
    // 1. unordered_map save num with freq
    unordered_map<int, int> uMap;
    for(int i = 0; i < nums.size(); i++>) {
        uMap[nums[i]]++;
    }

    // 2. sort by freq, using priority_queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, comparison> pq;
    for(auto ) {

    }
}
```

</details>

### cheapest flights within K stops
<details close>
    <summary>code</summary>

https://leetcode.com/problems/cheapest-flights-within-k-stops/description/?envType=daily-question&envId=2024-02-23

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

`<image src = "pic/cheapest-flights-within-k-stops-3drawio.png" />`

```c++
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : flights) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector<int> dist(n, numeric_limits<int>::max());
        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops = 0;

        while (stops <= k && !q.empty()) {
            int sz = q.size();
            // Iterate on current level.
            while (sz--) {
                auto [node, distance] = q.front();
                q.pop();
                // Iterate over neighbors of popped node.
                for (auto& [neighbour, price] : adj[node]) {
                    if (price + distance >= dist[neighbour]) continue;
                    dist[neighbour] = price + distance;
                    q.push({neighbour, dist[neighbour]});
                }
            }
            stops++;
        }
        return dist[dst] == numeric_limits<int>::max() ? -1 : dist[dst];
    }
};
```

</details>

### Diameter of Binary Tree
<details close>
    <summary>code</summary>

https://leetcode.com/problems/diameter-of-binary-tree/description/

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
`<image src = "pic/diamtree.jpg" />`

Input: root = [1,2,3,4,5]

Output: 3

Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int diameter;

    int longestPath(TreeNode* node) {
        if(node == nullptr) {
            return 0;
        }
        int leftPath = longestPath(node->left);
        int rightPath = longestPath(node->right);

        diameter = max(diameter, leftPath + rightPath);

        return max(leftPath, rightPath) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        longestPath(root);
        return diameter;
    }
};
```

</details>

### breadth first search
<details close>
    <summary>code</summary>

```c++
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
```

</details>