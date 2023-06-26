#include <iostream>
#include <string.h>
#include <vector>
#include <memory>
#include "common.h"
#include "test.hpp"
#include "complex.hpp"

using namespace std;
using std::cout;
using std::endl;
using std::string;


vector <int> v[5];
void insertionInArrayOfVectors() {
	for(auto i = 0; i < 5; i++) {
		for(auto j = i + 1; j < 5; j++) {
			v[i].push_back(j);
		}
	}
}


void printElements() {
	for(auto i = 0; i < 5; i++) {
		cout << "Elements at index " << i << ": ";

		for(auto it = v[i].begin(); it != v[i].end(); it++) {
			cout << *it << ' ';
		}
		cout <<endl;
	}
}


void arrayOfVectors() {
	insertionInArrayOfVectors();
	printElements();
}


int main(void) {
	// char *s = nullptr;
	// arrayOfVectors();

	// vector <string> vec;
	// vec.push_back("hello ");
	// vec.push_back("cpp !");
	// for(vector <string>::iterator i = vec.begin(); i != vec.end(); i++) {
	// 	cout << *i;
	// }
	// cout << endl;

	string s = "12345";
	cout << *(s.begin()) << endl;
	cout << *(s.end()) << endl;
	cout << s.size() << endl;

	return 0;
}