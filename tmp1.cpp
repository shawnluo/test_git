#include "test.hpp"

#include <functional>
#include <semaphore.h>
#include <thread>
using namespace std;


// string s combination

int minSum = INT_MAX;
vector<int> path;
vector<vector<int>> res;
void dfs(string s, int pos) {
    int n = s.size();
    if(pos == n) {
        cout << s << endl;
        // return;
    }
    for(int i = pos; i < n; i++) {
        swap(s[i], s[pos]);
        dfs(s, i + 1);
        swap(s[i], s[pos]);
    }
}

void permutation(string s, int pos) {
    int size = s.size();
    if(pos == size){
        cout << s << endl;
    }
    for(int i = pos; i < size; i++) {
        swap(s[i], s[pos]);
        permutation(s, pos + 1);
        swap(s[i], s[pos]);
    }
}


int findMinFallingPathSum(vector<vector<int>>& matrix, int row, int col) {
    if(col < 0 || col > matrix.size()) {
        return INT_MAX;
    }
    if(row == matrix.size() - 1) {
        return matrix[row][col];
    }
    int left = findMinFallingPathSum(matrix, row + 1, col - 1);
    int mid = findMinFallingPathSum(matrix, row + 1, col);
    int right = findMinFallingPathSum(matrix, row + 1, col + 1);

    return min({left, mid, right}) + matrix[row][col];
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    int minFallingSum = INT_MAX;

    for(int startCol = 0; startCol < matrix.size(); startCol++) {
        minFallingSum = min(minFallingSum, findMinFallingPathSum(matrix, 0, startCol));
    }
    return minFallingSum;
}

int main(void) {
    string s = "abc";
    dfs(s, 0);

    return 0;
}

// To execute C, please define "int main()"

/* return the 2's complement of an input integer 
   - without using arithmetic ops (+, -, *, /).   */

/*
1 (0x0001) <-> -1 (0xFFFF) 
2 (0x0002) <-> -2 (0xFFFE)
0b00010 -> ~0b00010 -> 0b1111101 -> 0b1111101 + 1 ->   0b11111111 10  <unkonwn>  -> 0b111110
3 (0x0003) <-> -3 (0xFFFD)
0b00011 -> ~0b00011 -> 0b1111100 -> 0b1111100 + 1 ->   0b11111111 10  <unkonwn>  -> 0b111101
*/
// 0x0001 -> 0xFFFF  ~(x - 1)
// 0xFFFF -> 0x0001  ~(x + 1)
/* int n;
    int res = ~(n + 1)  >>  << 
 */

int getComplementOfTwo(int num) {
  // 00000,0000,0000,0011 -> 00000,0000,0000,0010
  // 00000,0000,0000,0011 >> 1
  int res = ~(num);
  for(int i = 0; i < 8; i++) {
    
  }
}


int main() {
  for (int i = 0; i < 5; i++) {
    printf("Hello, World\n");
  }
  return 0;
}


// Your previous Plain Text content is preserved below:

// This is just a simple shared plaintext pad, with no execution capabilities.

// When you know what language you'd like to use for your int