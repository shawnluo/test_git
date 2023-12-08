

// zox


/*
Steering Problem
  
A controls engineer has collected test data for a black box steering system to
determine the amount of voltage that needs to be applied to hold the vehicle at a
given steering angle. The data below shows that the voltage (V)
required is a function of the steering angle (a).
  
Test Data:
a = -22,  -11, 0, 10,  20 degrees
V = -1.5, -1,  0, 1.2, 1.8 volts
  
The controls engineer would like to use this data as a feed forward term for the
steering controller. Your job is to write a function to determine
the best estimate for voltage (V) given a steering angle (a). aka. V = f(a).
 
Example output:
For a = 10; V = 1.2
For a = 5; V = 0.6
For a = 15; V = 1.5

This problem uses a unit test framework called Catch. Use the example tests at the
bottom of the file to test voltageEstimate, and feel free to add your own as well.
*/

// Unit testing framework
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// Standard includes
#include <iostream>
#include <stdint.h>

// y1 = m * x1 + c
// y2 = m * x2 + c
// m = (y1 - y2) / (x1 - x2)

float voltageEstimate(const float a, const float *a_data, float *v_data, size_t size /* TODO */) {
  // TODO

    float ratio;
    // float c = 0;
    for(int i = 0; i < size - 1; i++) {
        if(a >= a_data[i] && a <= a_data[i + 1]) {
            ratio = (v_data[i + 1] - v_data[i]) / (a_data[i + 1] - a_data[i]);
            // c = v_data[i]; 
            break;
        }
    }
    // return a * ratio + c;
    return a * ratio;
}


TEST_CASE( "Steering Problem Test" ) {
  const float a_data[]  =  {-22,  -11, 0, 10,  20}; // x-axis data
  const float v_data[] =   {-1.5, -1,  0, 1.2, 1.8}; // y-axis data
  const int size = 5;
  float a, v_expected, v_test;

  SECTION( "Example 1" ) {
    // input angle
    a = 10.0;
    // expected output voltage
    v_expected = 1.2;
    // call function under test
    v_test = voltageEstimate(a, a_data, v_data, size);
    
    // check that our result is correct (within floating point error)
    REQUIRE(v_expected == Approx(v_test));
  }
  
  SECTION( "Example 2" ) {
    // input angle
    a = 15.0;
    // expected output voltage
    v_expected = 1.5;
    // call function under test
    v_test = voltageEstimate(a, a_data, v_data, size);
    
    // check that our result is correct (within floating point error)
    REQUIRE(v_expected == Approx(v_test));
  }
  
  // TODO: Add any new test sections here
}










S
Convert Temperature Sensor Data



Shawn Luo


Convert Temperature Sensor Data
Description
We have a temperature sensor connected to an MCU via an I2C bus. The temperature sensor provides data in one of two measurement modes - standard mode or extended mode. In standard mode, the sensor can measure temperature in the range from 0°C to 127°C, and in the extended mode, it can measure temperature in the range from -64°C to 191°C.

In any mode, the MCU receives 24-bits of data.  A description of the data is given below:

 
 

The high byte, bits 15 to 8, contains the integer portion of the temperature in °C, and the low byte, bits 7 to 0, contains the decimal fraction of the temperature in °C.

In standard mode, temperatures lower than 0°C are reported as 0°C by the sensor; similarly, temperatures higher than 127°C are reported as 127°C. In extended mode, the sensor reports temperatures from -64°C to 191°C.

 

Function Description

The goal of this question is to populate the function convert_to_temp. This function takes in one argument input_val and returns the converted temperature value in degrees centigrade.

 

Constraints

The input decimal value will be within the conversion range of the sensor.
 

Input Format For Custom Testing
Sample Case 0
Sample Case 1
C

        res = input_val >> 8;
        res &= (~((1 << 16) - 1));
        FracPart = calFract(input_val);
    } else {
        res = input_val >> 8;
        res &= (~((1 << 15) - 1));
        uint32_t low = (1 << 8) - 1;
        uint32_t high = (1 << 16) - 1;
        uint32_t mask = high - low;
        int intPart = (input_val & mask) >> 15;

Line: 65 Col: 26

Run Code

Run Tests

Input / Output

Test Cases


Input
29552
Run Code to see your output here.

double __y, hint


// google


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

// ----------------
typedef struct data {
    char x;
    int y;
} Data;

Data a, b;
assert(a.x == b.x); // pass
assert(a.y == b.y); // pass
assert(a == b);     // failed.  why?


