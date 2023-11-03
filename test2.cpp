#include "test.hpp"

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <unordered_set>

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if(st.empty() || s[i] != st.top()) {
                st.push(s[i]);
            } else {
                st.pop();
            }
        }

        string res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

int main(void) {
	vector<int> nums = {0, 1, 1, 2, 2, 2};
	vector<int> res = sortByFre(nums);
	for(auto it : res) {
		cout << it << " ";
	}
	cout << endl;

	return 0;
}