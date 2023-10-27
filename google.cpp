

// 1. implement context grep
#include <iostream>
#include <string>

char *argv[] = {
    "Hello world",
    "Welcome to California",
    "Goodbye",
    "Big sky",
    "Nice job",
    "Blue sky",
    "Hey Joe",
};


void context_grep(int argc, char **argv, int context, char *expr) {
    if(argc <= 0 || \
            argv == nullptr || \
            expr == nullptr || \
            context < 0) {
        cout << "Invalid input!" << endl;
        return;
    }

    int firstTime = -1;
    int lastTime = -1;
    for(int i = 0; i < argc; i++) {
        if(strstr(argv[i], expr) != nullptr) {
            if(firstTime == -1) {
                firstTime = i;
            }
            lastTime = i;
        }
    }

    if(firstTime == - 1) return;

    // copy the strings
    vector<string> res;
    for(int i = firstTime; i <= lastTime; i++) {
        string tmp = argv[i];
        res.push_back(tmp);
    }

    // copy the front context
    for(int i = context; i > 0 && firstTime-- > 0; i--) {
        res.insert(res.begin(), argv[firstTime]);
    }

    // copy the rear context
    for(int i = 0; i < context && lastTime++ < argc; i--) {
        res.push_back(argv[lastTime]);
    }

    for(auto x : res) {
        cout << x << endl;
    }
}

int main() {
    // case 1
    context_grep(6, argv, 2, "sky");
    
    // case 2: no print
    context_grep(6, argv, -1, "sky");

    // case 3: 
    context_grep(6, argv, 1, "sky");

    // case 4: 
    context_grep(6, argv, 1, "sy");

    // case 5: 
    context_grep(0, argv, 1, "sy");

    // case 6: 
    context_grep(-1, argv, 1, "sy");

    // case 7: 
    context_grep(6, nullptr, 1, "sy");

    // case 8: 
    context_grep(6, argv, 1, nullptr);

    // case 9: 
    context_grep(6, argv, 11, "sky");

    // case 10: 
    context_grep(6, argv, 0, "sky");

    return 0;
}



// 2. reverse the order of words in a string
void reverseStr(string& s, int left, int right){
    for (int i = left, j = right; i < j; i++, j--) {
        swap(s[i], s[j]);
    }
}

void removeSpaces(string& s) {
    int slow = 0;
    for (int i = 0; i < s.size(); ++i) { //
        if (s[i] != ' ') {
            if (slow != 0) {
                s[slow++] = ' ';
            }
            while (i < s.size() && s[i] != ' ') { // 不等于空格的情况
                s[slow++] = s[i++];
            }
        }
    }
    s.resize(slow);
}

string reverseWords(string s) {
    if(s.empty()) {
        return "";
    }

    removeSpaces(s);
    reverseStr(s, 0, s.size() - 1);
    int start = 0;
    for (int i = 0; i <= s.size(); ++i) {
        if (i == s.size() || s[i] == ' ') {
            reverseStr(s, start, i - 1);
            start = i + 1;
        }
    }
    return s;
}

int main(void) {
    // case 1
    string s1 = "I love San Diego";

    // case 2
    string s2 = "I love San Diego ";

    // case 3
    string s3 = " I love San Diego!";

    // case 4
    string s4 = "";

    // case 5
    string s5 = " I love San   Diego!"

    string s = reverseWords(s3);
    cout << s << endl;
}


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






/*
Implement a blurring effect on an image that is represented as a MxN matrix of Pixels.
Blurring a single pixel is done by averaging values in surrounding area. Neighborhood area AxB

Example:
Neighborhood area: 3X5

Input:
 ___ ___ ___ ___ ___ ___ ___ _...
|_1_|_5_|_2_|_3_|_5_|_6_|_1_|_...
|_2_|_1_|_1_|_9_|_4_|_8_|_3_|_...
|_1_|_1_|_2_|_3_|_5_|_2_|_9_|_...
|___|___|___|___|___|___|___|_...
|...|...|...|...|...|...|...|_...

Output (only few pixels are blurred)
0_|_ ___ ___ ___ ___ ___ ___ _
0 |_x_|___|___|___|___|___|___|_...
0 |_ _|___|_3_|_4_|___|___|___|_...
0 |___|___|___|___|___|___|___|_...
  |___|___|___|___|___|___|___|_...
0 |...|...|...|...|...|...|...|_...
*/


int sum(int **arr, int row, int col, int posX, int posY, int a, int b) {
    int i, j, sum = 0;
    int coutX = 0;
    int coutY = 0;
    a = a >> 1;
    b = b >> 1;
    for(i = posX - a; i <= posX + a; i++) {
      coutX = 0;
      coutY = 0;
      for(j = posY - b; j <= posY + b; j++) {
        if(i < 0 || i >= row || j < 0 || j >= col) {
          continue;
          // arr[i][j] = 0; // arr[-1][-2] = 0;
        }
        coutX++;
        sum += arr[i][j];
      }
      coutY++;
    }
    sum /= (coutX * coutY);
    return sum;
}

// 0x00   0x01
// 0x 
int blurring(void *arr, void *res, int row, int col, int a, int b) {
    if(!arr) {
      return -1;
    }
    // int res[row][col] = {0};

    int (*arr_)[col] = arr;
    int (*res_)[col] = res;

    // 3 X 5
    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
          res_[i][j] = sum(arr_, row, col, i, j, a, b);
      }
    }
    return 0;
}