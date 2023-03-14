#include <iostream>
#include <string.h>
#include <vector>
#include "common.h"
using namespace std;



int main(void) {
	int i = 0;

	//0.
	vector<int> vec;
	for(i = 0; i < 10; i++) {
		vec.push_back(i);
	}

	//1. 
	for(unsigned int i = 0; i < vec.size(); i++) {
		//cout << vec[i] << endl;
	}

	//2. 
	vector<int>::iterator it;
	for(it = vec.begin(); it != vec.end(); ++it) {
		//cout << *it << endl;
	}

	//3.
	vec.insert(vec.begin() + 4, 0);
	for(unsigned int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}

	return 0;
}
