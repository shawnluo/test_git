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

int main()
{
	// Declaring the vector of structs
	struct Author a1 = { "Geek1", 124, 65000 };
	struct Author a2 = { "Geek2", 156, 100000 };
	struct Author a3 = { "Geek3", 10, 200 };

	vector<Author> v;

	// Insertion of elements using push_back()
	v.push_back(a1);
	v.push_back(a2);
	v.push_back(a3);

	cout << "author_name"
		<< " "
		<< "article_count"
		<< " "
		<< "article_views" << endl;

	for (auto& a : v) {
		cout << a.author_name << "			 "
			<< a.article_count << "		 "
			<< a.article_views << endl;
	}

	return 0;
}