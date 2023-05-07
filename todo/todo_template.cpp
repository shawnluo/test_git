#include <iostream>
#include <string.h>
#include <vector>
#include <memory>
#include "common.h"
using namespace std;

template<class T>
void printVector(vector<vector<T>> const &matrix) {
    for (vector<T> row: matrix) {
        for (T val: row) {
            cout << val << " ";
        }
        cout << endl;
    }
}


int main() {
	vector<vector<int>> mat {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
	printVector(mat);

	return 0;
}
