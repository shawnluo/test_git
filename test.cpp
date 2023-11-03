#include "test.hpp"

class myComp {
public:
    bool operator()(const pair<char, int> lhs, const pair<char, int> rhs) {
        return lhs.second < rhs.second;
    }
};

string sortByFre(string s) {
    string res;
    int size = s.size();
    
    unordered_map<char, int> map;
    for(int i = 0; i < size; i++) {
        map[s[i]]++;
    }

    priority_queue<pair<char, int>, vector<pair<char, int>>, myComp> pq;
    for(auto it = map.begin(); it != map.end(); it++) {
        pq.push(*it);
    }

    while(pq.size()) {
        res.push_back(pq.top().first);
        pq.pop();
    }
    return res;
}

// int maxRec(void* mat, int row, int col) {
int maxRec(vector<vector<int>> mat) {
    // vector<vector<int>> dp(weight.size(), vector<int>(BAG + 1, 0));
    int maxRow = 0;
    int maxCol = 0;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {

        }
    }
}

string s;
for(char* token = strtok(s, needle); token; token = strtok(nullptr, needle)) {
    cout << token << endl;
    s.push_back(token);
    for(auto it : s) {
        if(isdigit(it)) {

        }
    }
}

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

int main(void) {
    string s = "1211234444";
    cout << sortByFre(s) << endl;

    return 0;
}