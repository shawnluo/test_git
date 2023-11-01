#include "test.hpp"

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <unordered_set>

using namespace std;

int main() {
	unordered_set<string> myset = {"Mercury","Venus","Earth","Mars","Jupiter","Saturn","Uranus","Neptune", "Mercury"};
	for (auto it = myset.begin(); it != myset.end(); ++it)
		cout << *it << endl;
	return 0;
}
