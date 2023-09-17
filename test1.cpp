#include "test.hpp"

// void myPrint(void* p, int N) {
//     int(*mat)[N] = p;
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             printf("%d, ", mat[i][j]);
//         }
//         printf("\n");
//     }
// }


// void rotate_matrix(void* p, int N) {
//     int(*mat)[N] = p;

//     myPrint(mat, N);

//     for (int x = 0; x < N / 2; x++) {
//         for (int y = 0; y < N / 2; y++) {
//             int save                  = mat[x][y];
//             mat[x][y]                 = mat[y][N - x - 1];
//             mat[y][N - x - 1]         = mat[N - x - 1][N - y - 1];
//             mat[N - x - 1][N - y - 1] = mat[N - y - 1][x];
//             mat[N - y - 1][x]         = save;
//         }
//     }
//     myPrint(mat, N);
// }
// #endif


void reverse(string& s, int start, int end) {
    int left = start;
    int right;
    int len = s.size();
    
    if(end > len - 1) {
        right = len - 1;
    } else {
        right = end;
    }

    while(left < right) {
        s[left] ^= s[right];
        s[right] ^= s[left];
        s[left] ^= s[right];
        left++, right--;
    }
}

// grep sub in string array
// print from the first matched string to the last matched string
// print the context



// void test(char (*argv)[], char *s, int context) {
void test(int len, char **p, char *s, int context) {
    char *argv[] = {"123", "456", "abc"};
    if(p == nullptr || s == nullptr) {
        return;
    }
    int x = 1;//sizeof(argv);// / sizeof(argv[0]);
    cout << len << endl;
    // for() {

    // }
}

void rotate(string s, int n) {
    reverse(s, 0, n - 1);
    reverse(s, n, s.size() - 1);
    reverse(s, 0, s.size() - 1);
}

void createPre(string s) {
    vector<int> next;
    next.push_back(1);
    int count = 0;
    for(int i = 1; i < s.size(); i++) {
        int left = 0;
        int right = i;
        count = 0;
        while(left <= right) {
            if(s[left] == s[right]) {
                count++;
            } else {
                break;
            }
            left++;
            right--;
        }
        next.push_back(count);
    }

    for(auto x : next) {
        cout << x << " ";
    }
    cout << endl;
}

void findNext(int *next, char* s) {
    int j = 0;
    next[0] = j;

    for(int i = 1; i < strlen(s); i++) {
        while(j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        next[i] = j;
    }
}

int myStrstr(char *s, char *sub, int *next) {
    int j = 0;
    next[0] = j;

    for(int i = 1; i < strlen(s); i++) {
        while(j > 0 && s[i] != sub[j]) {
            j = next[j - 1];
        }
        if(s[i] == sub[j]) {
            j++;
            if(j == strlen(sub)) {
                return i - strlen(sub) + 1;
            }
        }
    }
    return -1;
}

int dp_19(vector<int> coins, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for(int i = 0; i < coins.size(); i++) {
        for(int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[amount];
}

// dp 21
int dp_21(vector<int> nums, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;  // make up 0, has 1 way
    // make up i, has dp[i] ways
    // dp[i] += dp[i - nums[j]]

    // // dp[j]: makeup j, need minimal dp[j] coins
    // // dp[j] = min(dp[j], dp[j - nums[i]] + 1);

    for(int i = 1; i <= amount; i++) {
        for(int j = 0; j < nums.size(); j++) {
            if(i >= nums[j]) {
                dp[i] += dp[i - nums[j]];
            }
        }
    }
    return dp[amount];
}

// dp 22
int dp_22(int n, int m) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    // dp[1] = 0;

    for(int i = 1; i <= n; i++) {       //遍历背包
        for(int j = 1; j <= m; j++) {   //遍历物品
            if(i >= j) {
                dp[i] += dp[i - j];
            }
        }
    }
    return dp[n];
}

// dp 23
int dp_23(vector<int> coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for(int i = 0; i < coins.size(); i++) {
        for(int j = coins[i]; j <= amount; j++) {
            if(j - coins[i] != INT_MAX) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
    }
    if(dp[amount] == INT_MAX) {
        return -1;
    }
    return dp[amount];
}

// dp 24: 给定一个整数n, 返回和为n的完全平方数的最少数量
int dp_24(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = i * i; j <= n; j++) {
            // if(j - i * i != INT_MAX) {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            // }
        }
    }
    if(dp[n] == INT_MAX) {
        return -1;
    }
    return dp[n];
}

// dp 26
bool dp_26(string s, vector<string> wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for(int i = 1; i <= s.size(); i++) {    // 遍历背包
        for(int j = 0; j < i; j++) {        // 遍历物品
            string word = s.substr(j, i - j);
            if(wordSet.find(word) != wordSet.end() && dp[j]) {
                dp[i] = true;
            }
        }
    }
    return dp[s.size()];
}

// dp 29
int dp_29(vector<int> nums) {
    vector<int> dp(nums.size() + 1, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i < nums.size(); i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[nums.size() - 1];
}

// dp 32
int dp_32(vector<int> prices) {
    vector<vector<int>> dp(prices.size(), vector<int> (2, 0));
    // dp[i][0]: have stock
    // dp[i][1]: have no stock
    dp[0][0] = -prices[0];  // 
    dp[0][1] = 0;

    for(int i = 1; i < prices.size(); i++) {
        // 昨天已经有股票了: dp[i - 1][0]
        // 昨天没有股票，今天买股票, : dp[i][1] - prices[i]
        dp[i][0] = max(dp[i - 1][0], -prices[i]);

        // 昨天没有股票: dp[i - 1][1]
        // 今天没有股票: dp[i - 1][0] + price[i]
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }

    return dp[prices.size() - 1][1];
}

// dp 34
int dp_34(vector<int> prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    
}

int main(void) {

    // char *s = "aabaaf";
    // char *sub = "aaf";
    // int next[strlen(sub)] = {0};

    // findNext(next, sub);
    // cout << myStrstr(s, sub, next) << endl;

    // createPre(s);

    // int len = strlen(s);
    // cout << len << endl;
    // int next[len];

    // findNext(next, s);
    // for(auto x : next) {
    //     cout << x << " ";
    // }
    // cout << endl;

    // test(3, argv, s, 2);
    // char *argv[] = {"123", "456", "abc"};
    // cout << sizeof(argv) / sizeof(argv[0]) << endl;


    
    // int mat[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    // rotate_matrix(mat, 3);
    // showMe(mat);

    // string s = "meshowmemeshow";
    // vector<string> sub = {"owme", "show", "show", "me"};
    // cout << dp_26(s, sub) << endl;

    vector<int> nums{1, 2, 6, 3, 9, 0};
    cout << dp_29(nums) << endl;

    return 0;
}