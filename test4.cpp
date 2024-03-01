#include "test.hpp"


// C++ Program to initialize
// vector of struct
// Individual insertion
#include <bits/stdc++.h>

using namespace std;

// Declaring a structure
struct Author {
	string author_name;
	int article_count;
	int article_views;
};

int main() {
	string s = "612530";
	const int n = s.size();

	char* s1 = new char[n + 1];
	strcpy(s1, s.c_str());
	sort(s1, s1 + n);
	cout << s1 << endl;

	return 0;
}