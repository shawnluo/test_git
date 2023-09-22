
// 3. Write functions to insert and search for an element in a binary search tree
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to insert a value into the BST
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to search for a value in the BST
bool search(TreeNode* root, int value) {
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

int main() {
    TreeNode* root = nullptr;

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