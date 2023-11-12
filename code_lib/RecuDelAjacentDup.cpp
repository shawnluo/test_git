class Solution1 {
public:
    // 递归删除两个相邻相同的元素  eg.  abbax -> x
    string recuDelAjacentDup(string s) {
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