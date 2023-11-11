#include "test.hpp"

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <unordered_set>

class Solution1 {
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

class comp {
    public:
        bool operator()(pair<int, int>lhs, pair<int, int>rhs) {
            return lhs.second < rhs.second;
        }
    };

class solution {
public:
    static vector<int> sortByFre(vector<int> nums) {
        unordered_map<int, int> map;
        for(auto it : nums) {
            map[it]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> que;
        for(auto it = map.begin(); it != map.end(); it++) {
            que.push(*it);
        }
        vector<int> res;
        for( ; que.size() != 0; ) {
            res.push_back(que.top().first);
            que.pop();
        }
        return res;
    }
};


vector<int> sortByF(string s) {
    
}

int main(void) {
	vector<int> nums = {0, 1, 1, 2, 2, 2};
	vector<int> res = solution::sortByFre(nums);
	for(auto it : res) {
		cout << it << " ";
	}
	cout << endl;

	return 0;
}