




int lenLongest(const string s) {
    int pos = -1;
    int res = 0;
    std::unordered_map<int, int> numMap;

    for(int i = 0; i < s.size(); i++) {
        // 1. save[s[i]] - 当前元素是否重复，与pos比较.
        // 2. pos - 记录没有重复元素的最后位置
        pos = max(pos, numMap[s[i]]);
        res = max(res, i - pos);
        numMap[s[i]] = i;
    }
    return res;
}

int main(void) {
    string s = "abcab";
    cout << lenLongest(s) << endl;
    return 0;
}