/*
    n = 5, k = 2
    1, 2
    1, 3,
    1, 4
    1, 5
    
    2, 3
    2, 4
    2, 5

    3, 4
    3, 5

    4, 5
*/
vector<int> buf;
vector<vector<int>> res;
void permutation_2(int n, int k, int pos) {
     if(buf.size() == k) {
        res.push_back(buf);
        return;
     }
     for(int i = pos; i <= n; i++) {
        buf.push_back(i);
        permutation_2(n, k, i + 1);
        buf.pop_back();
     }
}

int main(void) {
    // string s = "abc";
    permutation_2(5, 2, 1);

    for(auto x : res) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}