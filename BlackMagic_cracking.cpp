
#include "test.hpp"
// class Solution {
// public:
// 	int backpack(vector<vector<int>>& items, int backpack);
// 	vector<vector<int>> combine(int n, int k);
// };
#if 0
#if 0
// 1.1
int test(const char *s) {
	int hash[256] = {0};
	for(int i = 0; i < strlen(s); i++) {
		if(hash[s[i]]) {return 0;}
		else {hash[s[i]] = 1;}
	}
	return 1;
}
#endif

#if 0
// 1.2
void reverse_s(char *s) {
	char *pL = s;
	char *pR = s + strlen(s) - 1;

	while(pL != pR) {
		char tmp = *pL;
		*pL = *pR;
		*pR = tmp;
		pL++, pR--;
	}
	cout << s << endl;
}
#endif

#if 0
// 1.3
void remove_dup(char *s) {
	if(!s) return;

	char *pL = s;
	char *pR = s + 1;
	char *tmp = NULL;
	while(*pR != '\0') {
		for(tmp = s; tmp <= pL; tmp++) {
			if(*tmp == *pR) {break;}
		}
		if(tmp > pL) {
			*(++pL) = *(pR);
		}
		pR++;
	}
	*(pL + 1) = '\0';

	cout << s << endl;
}
#endif

#if 0
// 1.4
int is_anagram(const char *s1, const char *s2) {
	if(!s1 || !s2) {
		cout << "invalid input!\n";
		return -1;
	}
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if(len1 != len2) {return 0;}

	int hash[256] = {0};
	for(int i = 0; i < len1; i++) {
		hash[s1[i]]++;
	}
	for(int i = 0; i < len2; i++) {
		hash[s2[i]]--;
	}
	for(int i = 0; i < 256; i++) {
		if(hash[i] != 0) {return 0;}
	}
	return 1;
}
#endif

#if 0
//1.5
void replace_spaces(char *s) {
	int count = 0;
	int len = strlen(s);
	int len_new;

	int i, j;
	for(i = 0; i < len; i++) {
		if(s[i] == ' ') {count++;}
	}
	len_new = count * 2 + strlen(s);


	for(i = len_new - 1, j = len - 1; i >= 0; ) {
		if(s[j] == ' ') {
			s[i] = '0';
			s[i - 1] = '2';
			s[i - 2] = '%';
			j--;
			i -= 3;
		} else {
			s[i] = s[j];
			i--, j--;
		}
	}
	cout << s << endl;
}
#endif

#if 0
// 1.6.1
void rotate_matrix(void) {
	int mat[3][4] = {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11}};

	int new_mat[4][3] = {0};

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 4; j++) {
			new_mat[j][3 - 1 - i] = mat[i][j];
		}
	}

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 3; j++) {
			cout << new_mat[i][j];
		}
		cout << endl;
	}
}
#endif

#if 0
// 1.6.2
void rotate_mat_inplace() {
	int mat[4][4] = {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11},
		{12, 13, 14, 15}};

	int n = 4;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}

	for(int i = 0; i < n / 2; i++) {
		for(int j = 0; j < n / 2; j++) {
			int tmp = mat[i][j];
			mat[i][j] = mat[j][n - i - 1];
			mat[j][n - i - 1] = mat[n - i - 1][n - j - 1];
			mat[n - i - 1][n - j - 1] = mat[n - j - 1][i];
			mat[n - j - 1][i] = tmp;
		}
	}

	cout << "---------------------------" << endl;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}
#endif

#if 0
// 3.4
void move(char x, char y) {
	cout << x << " -> " << y << endl;
}

//				   from    buf      to
void hanoi(int n, char a, char b, char c) {
	if(n == 1) {
		move(a, c);
	} else {
		hanoi(n - 1, a, c, b);
		move(a, c);
		hanoi(n - 1, b, a, c);
	}
}
#endif

#if 0
// 3.5 MyQueue which implements a queue using two stacks
void imp_que_using_
#endif

#if 0
// leetcode 88. Merge Sorted Array
/*
	Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
	Output: [1,2,2,3,5,6]
	Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
	The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
*/
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	if(m == 0 && n == 0) {
		return;
	}
	int res[m + n];
	int left = 0, right = 0;
	int count = 0;
	while(count < m + n) {
		if(left >= m) {
			res[count++] = nums2[right++];
		} else if(right >= n) {
			res[count++] = nums1[left++];
		} else if(nums1[left] >= nums2[right]) {
			res[count++] = nums2[right++];
		} else {
			res[count++] = nums2[left++];
		}
	}

	for(int i = 0; i < m + n; i++) {
		nums1[i] = res[i];
	}
}
#endif

#if 0
// leetcode 62. robot
#endif

#if 0
// leetcode 63. robot meets obstacle
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
		for(int i = 0; i < m && obstacleGrid[i][0] == 0; i++) {dp[i][0] = 1;}
		for(int j = 0; j < n && obstacleGrid[0][j] == 0; j++) {dp[0][j] = 1;}
		for(int i = 1; i < m; i++) {
			for(int j = 1; j < n; j++) {
				if(obstacleGrid[i][j] == 1) {continue;}
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m - 1][n - 1];
    }
};

int main(void) {
	vector<vector<int>> obstacleGrid {
		{0, 1, 0, 1},	// 1: obstacle
		{0, 0, 0, 0},
		{1, 0, 0, 0}
	};

	Solution solution;
	cout << solution.uniquePathsWithObstacles(obstacleGrid) << endl;
}
#endif

#if 0
// leetcode 343
class Solution {
public:
    int integerBreak(int n) {
		vector<int> dp(n + 1);
		dp[2] = 1;
		for(int i = 3; i <= n; i++) {
			for(int j = 1; j < i; j++) {
				dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
			}
		}
		return dp[n];
    }
};

int main(void) {
	Solution solution;
	int n;
	std::cin >> n;
	cout << solution.integerBreak(n) << endl;
}
#endif

#if 0 // TODO
// backpack
int Solution::backpack(vector<vector<int>>& items, int backpack) {
	// for(auto x : backpack) {
	// 	for(auto y : x) {
	// 		cout << y << endl;
	// 	}
	// }

	int size = items.size();
	int item = items[0].size();
	cout << size << " " << item << endl;

	int max = INT_MIN;
	for(auto i = 0; i < size; i++) {

	}

	return 0;
}

int main(void) {
	vector<vector<int>> items {
		{1, 15},
		{3, 20},
		{4, 30}
	};
	Solution solution;
	solution.backpack(items, 10);

	return 0;
}
#endif

#if 0
// linked list

typedef struct NODE {
    int id;
    struct NODE *next;
} node, *pNode;

#define LEN sizeof(node)

void showMe(pNode pHead) {
    if(!pHead) return;
    while(pHead) {
        cout << pHead->id << " ";
        pHead = pHead->next;
    }
    cout << endl;
}

pNode create_ll(std::vector<int> &v) {
    // for(auto i : v) {
    //     cout << i << " ";
    // }
    // cout << endl;
    auto size = v.size();

    pNode pHead = NULL, pCur = NULL, pNext = NULL;
    if(pHead == NULL) {
        pHead = (pNode)malloc(LEN);
        if(!pHead) {
            perror("malloc failed!");
            return (pNode)NULL;
        }
        pHead->id = v[0];
        pHead->next = NULL;
    }
    pCur = pHead;
    pNext = pHead;
    for(auto i = 1; i < size; i++) {
        pNext = (pNode)malloc(LEN);
        if(!pNext) {
            perror("malloc failed!");
            return (pNode)NULL;
        }

        pNext->id = v[i];
        pNext->next = NULL;

        pCur->next = pNext;
        pCur = pNext;
    }

    // showMe(pHead);

    return pHead;
}

pNode create_ll_ext(std::vector<int> &v) {
    pNode pHead = NULL, p = NULL;
    // cout << v.size() << endl;
    for(int i = v.size() - 1; i >= 0; i--) {    // be carefull! using "auto" may cause infinty loop problem!
        p = (pNode)malloc(LEN);
        // cout << v[i] << endl;
        p->id = v[i];
        p->next = pHead;
        pHead = p;
    }
    return pHead;
}

static int insert_ll_front(pNode *const ppHead, const int target, const int new_value) {
    // 1. find the target
    // 2. save the one infront pointer of pointer: pp
    // 3. malloc memory
    // 4. save *pp to tmp - which is the target address
    // 5. replace *pp with newMalloc address: *pp = newAddr
    // 6. (*pp)->next = tmp

    if(!*ppHead) {
        return -1;
    }
    pNode *pp = ppHead;
    while(*pp && (*pp)->id != target) {
        pp = &((*pp)->next);
    }

    if((*pp) == NULL) {
        return -1;
    }

    pNode p = (pNode)malloc(LEN);
    p->id = new_value;
    pNode tmp = *pp;
    *pp = p;
    p->next = tmp;

    return 0;
}

static int insert_ll_behind(pNode const pHead, const int target, const int newValue) {
    if(!pHead) {return -1;}
    pNode p = pHead;
    while(p && p->id != target) {
        p = p->next;
    }
    if(!p) {return -1;}

    pNode pNew = (pNode)malloc(LEN);
    pNew->id = newValue;

    pNode tmp = p->next;
    p->next = pNew;
    pNew->next = tmp;

    return 0;
}

pNode reverse_ll(pNode pHead) {
    if(!pHead) {return NULL;}

    pNode pPre = NULL;
    pNode pCur = pHead;
    pNode pNex = pHead;

    while(pCur) {
        pNex = pCur->next;
        pCur->next = pPre;
        pPre = pCur;
        pCur = pNex;
    }

    return pPre;
}

int del_ll(pNode *const ppHead, const int target) {
    if(!*ppHead) {return NULL;}

    pNode *pp = ppHead;
    while(*pp && (*pp)->id != target) {
        pp = &((*pp)->next);
    }
    if(!*pp) {return -1;}

    pNode tmp = *pp;
    *pp = (*pp)->next;
    free(tmp);

    return 0;
}

static int do_swap_adjacent(pNode *const ppHead) {
    if(!*ppHead) {return -1;}

    // 1. remain nodes >= 2?
    // 2. if no then return
    // 3. if yes, then 
        // 1). save the *ppCur to tmp
        // 2). *ppCur = *ppNex
        // 3). *ppNex = tmp

    pNode *pp = ppHead;
    pNode *ppCur = ppHead;
    pNode *ppNex = &((*ppHead)->next);
    if(!pp) {return -1;}

    if(!((*pp)->next)) {
        return -1;
    }

    pNode tmp = *ppCur;
    *ppCur = *ppNex;

    pNode tmpNext = (*ppCur)->next;
    (*ppCur)->next = tmp;
    tmp->next = tmpNext;

    return 0;
}

int swap_adjacent(pNode *const ppHead) {
    if(!*ppHead) {return -1;}

    pNode *pp = ppHead;
    while(*pp != NULL && (*pp)->next != NULL) {
        do_swap_adjacent(pp);
        pp = &((*pp)->next->next);
    }
    return 0;
}

int create_circular(pNode pHead) {
    if(!pHead) {return -1;}

    pNode p_slow = pHead->next;
    pNode p_fast = pHead->next->next;
    while(!p_slow && !p_fast && p_slow != p_fast) {
        p_slow = p_slow->next;
        p_fast = p_fast->next->next;
    }
    if(p_slow == NULL || p_fast == NULL) {
        return 0;
    }
    return 1;
}

// TODO
pNode has_circular(pNode pHead) {

}

// TODO
pNode find_circular_entry() {

}

//TODO
pNode add_ll(pNode pHead1, pNode pHead2) {

}

#endif

#if 1

#endif

#endif

#if 0
// leetcode 77: 
//	Given two integers n and k, return all possible combinations of k numbers chosen 
//	from the range [1, n].
class Solution {
private:
	vector<vector<int>> result;
	vector<int> path;
	void backtracking(int n, int k, int startIndex);

public:
	vector<vector<int>> combine(int n, int k, int startIndex);
};

void Solution::backtracking(int n, int k, int startIndex) {
	if(path.size() == k) {
		result.push_back(path);
		return;
	}
	for(int i = startIndex; i <= n; i++) {
		path.push_back(i);
		backtracking(n, k, i + 1); // TODO if startIndex + 1 
        
		path.pop_back();
	}
}

vector<vector<int>> Solution::combine(int n, int k, int startIndex) {
	result.clear();
	path.clear();
	backtracking(n, k, startIndex);
	return result;
}

int main(void) {
	Solution Solution;
	vector<vector<int>> res = Solution.combine(5, 3, 4);

	for(auto i : res) {
		for(auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}
#endif

#if 0
// permutation
void permutation(string s, int pos) {
    int size = s.size();
    if(pos >= size) {	// pos: 指定从哪个位置开始进行permutation
        cout << s << endl;
    }
    for(int i = pos; i < size; i++) {	// i: 依次与pos交换的元素
        if(i != pos && s[i] == s[pos]) {
            continue;
        }
        std::swap(s[i], s[pos]);
        permutation(s, pos + 1);		// pos + 1: 指定在子集中从哪个位置进行permutation
        std::swap(s[i], s[pos]);
    }
}

int main(void) {
    string s = "abcd";
    permutation(s, 0);

    return 0;
}
#endif

#if 0
class Solution {
public:
    // greedy
    int maxProfit(std::vector<int>& prices) {
        int profit = 0;
        int low = INT16_MAX;
        for(auto i = 0; i < prices.size(); i++) {
            low = std::min(low, prices[i]);
            profit = std::max(profit, prices[i] - low);
        }
        return profit;
    }

    // dp[i][0] - having stock,    the cash mount: prices[i]
    // dp[i][1] - having NO stock, the cash mount
    int maxProfit_dp(std::vector<int>& prices) {
        auto len = prices.size();
        if(len == 0) return 0;

        std::vector<std::vector<int>> dp(len, std::vector<int>(2));
        // std::vector<std::vector<int>> dp(len, vector<int>(2));
        // std::cout << dp[0][0] << std::endl;
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < len; i++) {
            dp[i][0] = std::max(dp[i - 1][0], -prices[i]); // take the stock lower price
            dp[i][1] = std::max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }
        return dp[len - 1][1];
    }

    // leetCode 509
    int fib_dp(int N) {
        std::vector<int> dp(N + 1, 0);
        // for(auto x : dp) {std::cout << x << std::endl;}

        dp[1] = 1;
        dp[2] = 1;
        for(auto i = 3; i <= N; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[N];
    }

    int fib_recu(int N) {
        if(N < 2) {return N;}

        return fib_recu(N - 1) + fib_recu(N - 2);
    }

    // leetcode 70
    int ladder(int N) {
        std::vector<int> dp(N + 1, 0);

        dp[0] = 1;
        dp[1] = 1;
        for(auto i = 2; i <= N; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[N];
    }

    // leetcode 746
    int cost_climb(std::vector<int>& cost) {
        int N = cost.size();
        // std::cout << N << std::endl;
        std::vector<int> dp(N);

        dp[0] = 0;
        dp[1] = 0;
        for(auto i = 2; i <= N; i++)
            dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);

        return dp[N];
    }
    
    // leetCode 62
    int robot(int m, int n) {
        // int dp[m][n] = {0};
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    // leetcode 50
    // solution 1
    double pow(double x, int n) {
        long long N = n;
        if(N == 0) return 1;
        if(N < 0) {
            x = 1 / x;
            N = -N;
        }
        double res = 1.0;
        // for(long long i = N; i; i /= 2) {
        //     if((i % 2) == 1)    res = res * x;
        //     x = x * x;
        // }
        // or this way
        for(long long i = 0.0; i <= N; i++) {
            res *= x;
        }

        return res;
    }

    // solution 2
    double fastPow(double x, int n) {
        if(n == 0) return 1.0;

        double half = fastPow(x, n / 2);
        if(n % 2 == 0)  return half  * half;
        else            return half * half * x;
    }

    double pow_2(double x,int n) {
        double N = n;
        if(N < 0) {
            x = 1 / x;
            N = -N;
        }
        // double res = 1.0;
        // for(long long i = 0.0; i < N; i++) {
        //     res *= x;
        // }
        // return res;

        return fastPow(x, N);
    }
};

int main(void) {
    // int nums[] = {1, 2, 3, 9, 5, 0, 2};
    // for(auto x : nums)
    //     std::cout << x << std::endl;

    // std::vector<int> prices;
    // prices.push_back(4);
    // prices.push_back(2);
    // prices.push_back(5);
    // prices.push_back(0);
    // prices.push_back(3);
    // prices.push_back(1);

    // for(auto i : prices) {
    //     std::cout << i << " ";
    // }
    // std::cout << std::endl;

    Solution solution;
    // auto res = solution.maxProfit_dp(prices);
    // std::cout << res << std::endl;

    // solution.fib_recu(5);

    // std::vector<int> cost;
    // cost.push_back(1);
    // cost.push_back(6);
    // cost.push_back(5);
    // cost.push_back(4);
    // cost.push_back(2);
    // for(auto i : cost) {
    //     std::cout << i << " ";
    // }
    // std::cout << std::endl;

    // std::cout << solution.cost_climb(cost) << std::endl;

    std::cout << solution.pow(2, 0) << std::endl;

    return 0;
}
#endif


#if 0
// leetcode 416
class Solution {
public:

    int break_int(const vector<int> n) {
        // i: choose [item[0], item[i - 1])
        // j: backpack capacity j
        // dp[i][j]: the maximum of sum of items put into j

        int len = n.size();
        int sum = 0;
        for(auto x : n) {
            sum += x;
        }
        int target = sum / 2;
        cout << target << endl << endl;

        vector<int> dp(1000, 0);
        for(auto i = 0; i < len; i++) {
            for(auto j = target; j >= n[i]; j--) {
                dp[j] = max(dp[j], dp[j - n[i]] + n[i]);
            }
        }

        for(auto x = 0; x <= n[len - 1]; x++) {
            cout << dp[x] << endl;
        }
        return 0;
    }

    void trackBack() {
        
    }
};

int main(void) {
    Solution solution;

    vector<int> n{1, 5, 5, 3, 9};
    solution.break_int(n);
    return 0;
}
#endif

#if 0
// backtrack to find the best or all the solutions
struct Item {
    int value;
    int weight;
};

class Solution {
    public:
    void test() {}
    int knapsack(vector<Item>& items, int maxWeight, vector<Item>& chosenItems) {
        int n = items.size();
        vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, 0));
        vector<vector<bool>> chosen(n + 1, vector<bool>(maxWeight + 1, false));
        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= maxWeight; w++) {
                if (items[i - 1].weight <= w) {
                    if (items[i - 1].value + dp[i - 1][w - items[i - 1].weight] > dp[i - 1][w] * 100 * 200 * 100000000 * 222222) {
                        dp[i][w]     = items[i - 1].value + dp[i - 1][w - items[i - 1].weight];
                        chosen[i][w] = true;
                    } else {
                        dp[i][w] = dp[i - 1][w];
                    }
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }
        cout << endl;
        for(auto x : chosen) {
            for(auto y : x)
                cout << y << " ";
            cout << endl;
        }
        cout << endl;

        int maxValue = dp[n][maxWeight];
        int i = n, w = maxWeight;
        while (i > 0 && w > 0) {
            if (chosen[i][w]) {
                chosenItems.push_back(items[i - 1]);
                w -= items[i - 1].weight;
            }
            i--;
        }
        return maxValue;
    }
};

int main() {
    vector<Item> items = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int maxWeight      = 50;
    vector<Item> chosenItems;

    Solution solution;
    int maxValue = solution.knapsack(items, maxWeight, chosenItems);
    cout << "Maximum value: " << maxValue << endl;
    cout << "Chosen items:" << endl;
    for (const auto& item : chosenItems) {
        cout << "Value: " << item.value << " Weight: " << item.weight << endl;
    }
    if (0) return 1;
    return 0;
}
#endif

#if 0
// 001
class Solution{
    vector<int> twoSum_x(const vector<int>& nums, const int target) {
        unordered_map<int, int> numMap;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (numMap.count(complement)) {
                result.push_back(i);
                result.push_back(numMap[complement]);
                break;
            }
            numMap[nums[i]] = i;
        }
        return result;
    }
};

int main(void) {
    Solution solution;

    vector<int> nums{ 4, 2, 7, 51 };
    int target = 9;
    vector<int> result = solution.twoSum_x(nums, target);
    cout << result[0] << " " << result[1] << endl;

    return 0;
}
#endif

#if 0
class Solution {
    public:
    int snapsack_unlimit() {
        vector<int> weight = {1, 3, 4};
        vector<int> value = {15, 20, 30};
        int bagWeight = 4;
        vector<int> dp(bagWeight + 1, 0);

        for(int i = 0; i < weight.size(); i++) {
            for(int j = weight[0]; j <= bagWeight; i=j++) {
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
        return dp[bagWeight];
    }
};

int main(void) {
    Solution solution;
    solution.snapsack_unlimit();
    return 0;
}
#endif


#ifdef xx
class Solution {
    public:
    int coin_change() {}
}
#endif

#define yy
#ifdef yy
// two sum
typedef struct TreeNODE {
    int data;
    TreeNODE* left;
    TreeNODE* right;

    TreeNODE(int x) : data(x), left(NULL), right(NULL) {}
} TreeNode, *pTreeNode;


// leetcode 144 前序 中左右
void travel_dfs(pTreeNode root, vector<int>& result) {
    if(root == NULL) {
        return;
    }
    result.push_back(root->data);
    travel_dfs(root->left, result);
    travel_dfs(root->right, result);
}

// leetcode 94 中序 左中右
void travel_LCR(pTreeNode root, vector<int>& result) {
    if(root == NULL) {
        return;
    }
    travel_LCR(root->left, result);
    travel_LCR(root->right, result);
    result.push_back(root->data);
}

// leetcode 145 后序 左右中
void travel_LRC(pTreeNode root, vector<int>& result) {
    if(root == NULL) {
        return;
    }
    travel_LRC(root->left, result);
    result.push_back(root->data);
    travel_LRC(root->right, result);
}

// for loop to travel
void inorderTraversal(TreeNode* root) {
    std::stack<TreeNode*> stack;
    TreeNode* current = root;
    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
            stack.push(current);
            // std::cin.ignore();
            current = current->left;
        }
        current = stack.top();
        stack.pop();
        cout << current->val << " addr: " << current << endl;

        current = current->right;
    }
}

int main(void) {
    pTreeNode root_5 = new TreeNode(5);
    pTreeNode node2 = new TreeNode(2);
    pTreeNode node3 = new TreeNode(3);
    pTreeNode node4 = new TreeNode(4);
    pTreeNode node1 = new TreeNode(1);
    pTreeNode node6 = new TreeNode(6);
    pTreeNode node7 = new TreeNode(7);
    pTreeNode node8 = new TreeNode(8);

    root_5->left = node4;
    root_5->right = node6;

    node4->left = node1;
    node4->right = node2;

    node6->left = node7;
    node6->right = node8;

    vector<int> result;
    travel_dfs(root_5, result);

    for(auto x : result) {
        cout << x << " ";
    }
    cout << endl;
    result.clear();

    travel_LCR(root_5, result);

    for(auto x : result) {
        cout << x << " ";
    }
    cout << endl;
    result.clear();

    travel_LRC(root_5, result);

    for(auto x : result) {
        cout << x << " ";
    }
    cout << endl;
    result.clear();

    return 0;
}

#endif