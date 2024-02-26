

### 计算器
string s = 3 5 6 + *

```c++
int evalRPM(string s) {
    stack<long long> st;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == "+" || s[i] == "-" || s[i] == "*" || s[i] == "/") {
            long long a = st.top();
            st.pop();
            long long b = st.top();
            st.pop();
        
            if(s[i] == "+") st.push(a + b);
            if(s[i] == "-") st.push(a + b);
            if(s[i] == "*") st.push(a * b);
            if(s[i] == "/") st.push(a / b);
        } else {
            st.push(stoll(s[i]));
        }
    }
    return st.top();
}
```

### sort by frequence

```c++

class comparison {
public:
    bool operator()(const pair<int, int> lhs, const pair<int, int> rhs) {
        return lhs.second > rhs.second;
    }
};

void sortByFreq(vector<int>& nums) {
    // 1. unordered_map save num with freq
    unordered_map<int, int> uMap;
    for(int i = 0; i < nums.size(); i++>) {
        uMap[nums[i]]++;
    }

    // 2. sort by freq, using priority_queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, comparison> pq;
    for(auto ) {

    }
}
```
