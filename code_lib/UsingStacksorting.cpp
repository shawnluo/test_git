void sortSt(vector<int>& nums) {
    st.push(nums[0]);
    for(int i = 1; i < nums.size(); i++) {
        while(!st.isEmpty() && nums[i] > st.peek()) {
            bak.push(st.top());
            st.pop();
        }
        st.push(nums[i])
        while(!bak.isEmpty()) {
            st.push(bak.top());
            bak.pop();
        }
    }
    int i = 0;
    while(!st.isEmpty()) {
        nums[i++] = st.top();
        st.pop();
    }
}