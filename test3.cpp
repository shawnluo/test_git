#include "test.hpp"

#include <cstdio>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <unordered_set>

#include <iostream>
#include <string>

void rotate(vector<vector<int>>& mat) {
	int size = mat.size();
	for(int i = 0; i < size / 2; i++) {
		for(int j = i; j < size - i - 1; j++) {
			int tmp = mat[i][j];
			mat[i][j] = mat[j][size - i - 1];
			mat[j][size - i - 1] = mat[size - i - 1][size - j - 1];
			mat[size - i - 1][size - j - 1] = mat[size - j - 1][i];
			mat[size - j - 1][i] = tmp;
		}
	}
}

void getNext(int* next, char* s) {
	int j = 0;
	next[0] = 0;
	for(int i = 1; i < size; i++) {
		while(j > 0 && s[i] != s[j]) {
			j = next[j - 1];
		}
		if(s[i] == s[j]) {
			j++;
		}
		next[i] = j;
	}
}

int myStrstr() {
	int j = 0;
	getNext(next, t);
	for(int i = 0; i < s.size(); i++) {
		while(j > 0 && s[i] != t[j]) {
			j = next[j - 1];
		}
		if(s[i] == t[j]) {
			j++;
		}
	}
}

while(num > 0) {
	if(res.size() > 32) {
		return re;
	}
	num = num * 2;
	if(num >= 1) {
		res = res + "1";
		nums -= 1.0;
	} else {
		res = res + "0";
	}
}