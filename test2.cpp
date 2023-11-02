#include "test.hpp"

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <unordered_set>

class myComparison {
public:
	bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
		return lhs.second < rhs.second;
	}
};

vector<int> sortByFre(vector<int> nums) {
	int size = nums.size();
	unordered_map<int, int> map;

	for(int i = 0; i < size; i++) {
		map[nums[i]]++;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, myComparison> pq;
	
	for(auto it = map.begin(); it != map.end(); it++) {
		pq.push(*it);
	}

	vector<int> res;
	while(!pq.empty()) {
		res.push_back(pq.top().first);
		pq.pop();
	}

	return res;
}

int main(void) {
	vector<int> nums = {0, 1, 1, 2, 2, 2};
	vector<int> res = sortByFre(nums);
	for(auto it : res) {
		cout << it << " ";
	}
	cout << endl;

	return 0;
}