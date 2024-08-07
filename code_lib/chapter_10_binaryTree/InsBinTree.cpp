
// 3. Write functions to insert and search for an element in a binary search tree
struct treeNode {
    int value;
    treeNode* left;
    treeNode* right;

    treeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to insert a value into the BST
treeNode* insert(treeNode* root, int value) {
    if (root == nullptr) {
        return new treeNode(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to search for a value in the BST
bool search(treeNode* root, int value) {
    if (root == nullptr) {
        return false;
    }

    if (value == root->value) {
        return true;
    } else if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// leetcode 144 前序 中左右
void travel_dfs(treeNode* root, vector<int>& result) {
    if(root == NULL) {
        return;
    }
    result.push_back(root->val);
    travel_dfs(root->left, result);
    travel_dfs(root->right, result);
}

// leetcode 94 中序 左中右
void travel_LCR(treeNode* root, vector<int>& result) {
    if(root == NULL) {
        return;
    }
    travel_LCR(root->left, result);
    travel_LCR(root->right, result);
    result.push_back(root->val);
}

// leetcode 145 后序 左右中
void travel_LRC(treeNode* root, vector<int>& result) {
    if(root == NULL) {
        return;
    }
    travel_LRC(root->left, result);
    result.push_back(root->val);
    travel_LRC(root->right, result);
}

int main() {
    treeNode* root = nullptr;

    // case 1: Insert values into the BST
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    // case 2: Search for values in the BST
    std::cout << "Searching for 6: " << (search(root, 6) ? "Found" : "Not found") << std::endl;

    // case 3: Search for values in the BST
    std::cout << "Searching for -1: " << (search(root, -1) ? "Found" : "Not found") << std::endl;

    // case 4: Search for values in the BST
    std::cout << "Searching for 9: " << (search(root, 9) ? "Found" : "Not found") << std::endl;

    return 0;
}