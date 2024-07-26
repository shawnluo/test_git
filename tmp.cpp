
#include "test.hpp"

class Vector {
private:
    double x, y;

public:
    Vector(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {}

    Vector operator+ (const Vector& v) const {
        return Vector(x + v.x, y + v.y);
    }

    double operator() () const {
        return x + y;
    }

    void print() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

// 1, 2, 4, 3
int contigus_longestIncreasing(vector<int>& v) {
    int res = 1;
    vector<int> dp(v.size(), 1);

    for(int i = 1; i < v.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
    }

    for(auto it : dp) {
        cout << it << " ";
    }
    cout << endl;
    // return res;
    return dp[v.size() - 1];
}

int getVal(vector<vector<int>>& v, int m, int n, int size) {
    int res = 0;
    for(int i = m; i < m + size; i++) {
        for(int j = n; j < n + size; j++) {
            res += v[i][j];
        }
    }
    return res;
}

// a: 1, 2, 3, 4, 5
// b. 2, 3, 4, 1, 2
int longestCommonSub(vector<int>& a, vector<int>& b) {
    vector<vector<int>> dp(a.size() + 1, vector<int> (b.size() + 1, 0));
    int res = 0;
    for(int i = 1; i <= a.size(); i++) {
        for(int j = 1; j <= b.size(); j++) {
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            res = max(res, dp[i][j]);
        }
    }
    return res;
}

//contigeus
int longest(vector<int>& a, vector<int>& b) {
    int res = 0;
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 1));
    for(int i = 1; i <= a.size(); i++) {
        for(int j = 1; j <= b.size(); j++) {
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                res = max(res, dp[i][j]);
            }
        }
    }
    return res;
}

/* 
    a a b a a f
    0 1 0 1 2 0
*/
void getNext(vector<char>& next, const string& s) {
    // get next
    next[0] = 0;
    int j = 0;

    for(int i = 1; i < s.size(); i++) {
        while(j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        next[i] = j;
    }
}

int kmp() {

}

int main(void) {
    // Vector v1(1.0, 2.0);
    // v1.print();

    // Vector v2(3.0, 4.0);
    // v2.print();

    // Vector sum = v1 + v2;
    // sum.print();

    // double sum = v1();
    // cout << sum << endl;

    vector<int> v{1, 2, 3, 2, 3, 4, 5, 1, 2, 3, 4, 5, 8, -1, 9, 7};
    cout << contigus_longestIncreasing(v) << endl;

    return 0;
}