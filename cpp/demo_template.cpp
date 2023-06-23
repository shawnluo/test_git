#include <iostream>
#include <string.h>
#include <vector>
#include <memory>
#include "common.h"
#include "test.hpp"
#include "complex.hpp"

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

typedef unsigned long BankAccount;
class BankAccout {
public:
	void MakeDeposit(float amount);
	float WithDraw();
	bool Transfer(BankAccount& to, float amount);
	float GetBalance() const;
private:
	float balance;
	float interestYTD;
	char* owner;
	int account_number;
};


int main() {
	vector<vector<int>> mat {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
	printVector(mat);

	return 0;
}