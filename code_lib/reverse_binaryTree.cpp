// binary tree
struct treeNode {
    int val;
    treeNode* left;
    treeNode* right;

    treeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

    // 0. create
treeNode* insertTree(treeNode* root, int value) {
    if(root == nullptr) {
        // cout << "11" << endl;
        return new treeNode(value);
    }

    if(value < root->val) {
        root->left = insertTree(root->left, value);
    } else if(value > root->val) {
        root->right = insertTree(root->right, value);
    }

    return root;
}

void insert2(treeNode** root, int val) {
    if(*root == nullptr) {
        *root = new treeNode(val);
    }
    if(val < (*root)->val) {
        insert2(&((*root)->left), val);
    } else if(val > (*root)->val) {
        insert2(&((*root)->right), val);
    }
}

    // 1. travel
void travelTree(treeNode* root) {
    if(root == nullptr) {
        // cout << "empty" << endl;
        return;
    }
    // cout << root->val << endl;
    travelTree(root->left);
    // cout << root->val << endl;
    travelTree(root->right);
    cout << root->val << endl;
}

    // 2. reverse
treeNode* reverse(treeNode* root) {
    if(root == nullptr) {
        return root;
    }
    swap(root->left, root->right);

    reverse(root->left);
    reverse(root->right);

    return root;
}
    // 3. search - simple
bool search(treeNode* root, int val) {
    if(root == nullptr) {
        return false;
    }
    if(root->val == val) {
        return true;
    }

    if(val < root->val)
        search(root->left, val);
    else
        search(root->right, val);

    return false;
}