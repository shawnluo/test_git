

vector<vector<int>> res;

res.push_back(vector<int>{v[i], v[j], v[k]});

// first element
cout << v.front() << endl;

// last element
cout << v.back() << endl;

/* access the first element */
cout << v.at(0);

/* access the last element */
cout << v.at(v.size() - 1);

bool findInVec(int n) {
    vector<int> v = {1, 2, 3};
    if(std::find(v.begin(), v.end(), 3) != v.end()) {
        // cout << 1 << endl;
        return true;
    }
    return false;
}
