#include "test.hpp"

#include <cstdio>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <unordered_set>

#include <iostream>
#include <string>

class Solution {
public:
	int oddEvenJumps(const vector<int>& A) {
		int size = A.size();

		set<int> Set;
		Set.insert(A.back());
		unordered_map<int, int> Map;
		Map[A.back()] = size - 1;

		vector<bool> dp_odd(size);
		vector<bool> dp_even(size);

		dp_odd[size - 1] = true;
		dp_even[size - 1] = true;

		for(int i = size - 2; i >= 0; i--) {
			auto it1 = Set.lower_bound(A[i]);
			if(it1 != Set.end()) {
				int num = *it1;
				int j = Map[num];
				dp_odd[i] = dp_even[j];
			}

			auto it2 = Set.upper_bound(A[i]);
			if(it2 != Set.begin()) {
				it2 = prev(it2, 1);
				int num = *it2;
				int j = Map[num];
				dp_even[i] = dp_odd[j];
			}
		}

		int res = 0;
		for(auto x : dp_odd) {
			res += (x == true ? 1 : 0);
		}
		for(auto x : dp_even) {
			res += (x == true ? 1 : 0);
		}

		return res;
	}
};