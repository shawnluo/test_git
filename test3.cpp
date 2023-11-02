#include "test.hpp"

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <unordered_set>

class myComp {
public:
	bool operator()(const pair<int, int> lhs, const pair<int, int> rhs) {
		return lhs.second > rhs.second;
	}
};

vector<int> sortByFre(vector<int> nums) {
	vector<int> res(100, 0), res1;
	unordered_map<int, int> map;
	for(auto it : nums) {
		map[it]++;
		// cout << map[it] << endl;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> pq;
	for(auto it = map.begin(); it != map.end(); it++) {
		pq.push(*it);
	}

	while(pq.size() != 0) {
		int i = 0;
		res[i++] = pq.top().first;
		res1.push_back(pq.top().first);
		pq.pop();
	}

	for(int i = 0; i < res1.size(); i++) {
		cout << res[i] << " - " << res1[i] << endl;
	}

	return res;
}

int main(void) {
	vector<int> nums = {0, 1, 1, 2, 2, 2};
	vector<int> res = sortByFre(nums);

	return 0;
}