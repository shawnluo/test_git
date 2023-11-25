


#include "test.hpp"

/*
975. Odd Even Jump
Hard
Topics
Companies
You are given an integer array arr. From some starting index, you can make a series of jumps. The (1st, 3rd, 5th, ...) jumps in the series are called odd-numbered jumps, and the (2nd, 4th, 6th, ...) jumps in the series are called even-numbered jumps. Note that the jumps are numbered, not the indices.

You may jump forward from index i to index j (with i < j) in the following way:

During odd-numbered jumps (i.e., jumps 1, 3, 5, ...), you jump to the index j such that arr[i] <= arr[j] and arr[j] is the smallest possible value. If there are multiple such indices j, you can only jump to the smallest such index j.
During even-numbered jumps (i.e., jumps 2, 4, 6, ...), you jump to the index j such that arr[i] >= arr[j] and arr[j] is the largest possible value. If there are multiple such indices j, you can only jump to the smallest such index j.
It may be the case that for some index i, there are no legal jumps.
A starting index is good if, starting from that index, you can reach the end of the array (index arr.length - 1) by jumping some number of times (possibly 0 or more than once).

Return the number of good starting indices.

 

Example 1:

Input: arr = [10,13,12,14,15]
Output: 2
Explanation: 
From starting index i = 0, we can make our 1st jump to i = 2 (since arr[2] is the smallest among arr[1], arr[2], arr[3], arr[4] that is greater or equal to arr[0]), then we cannot jump any more.
From starting index i = 1 and i = 2, we can make our 1st jump to i = 3, then we cannot jump any more.
From starting index i = 3, we can make our 1st jump to i = 4, so we have reached the end.
From starting index i = 4, we have reached the end already.
In total, there are 2 different starting indices i = 3 and i = 4, where we can reach the end with some number of
jumps.
Example 2:

Input: arr = [2,3,1,1,4]
Output: 3
Explanation: 
From starting index i = 0, we make jumps to i = 1, i = 2, i = 3:
During our 1st jump (odd-numbered), we first jump to i = 1 because arr[1] is the smallest value in [arr[1], arr[2], arr[3], arr[4]] that is greater than or equal to arr[0].
During our 2nd jump (even-numbered), we jump from i = 1 to i = 2 because arr[2] is the largest value in [arr[2], arr[3], arr[4]] that is less than or equal to arr[1]. arr[3] is also the largest value, but 2 is a smaller index, so we can only jump to i = 2 and not i = 3
During our 3rd jump (odd-numbered), we jump from i = 2 to i = 3 because arr[3] is the smallest value in [arr[3], arr[4]] that is greater than or equal to arr[2].
We can't jump from i = 3 to i = 4, so the starting index i = 0 is not good.
In a similar manner, we can deduce that:
From starting index i = 1, we jump to i = 4, so we reach the end.
From starting index i = 2, we jump to i = 3, and then we can't jump anymore.
From starting index i = 3, we jump to i = 4, so we reach the end.
From starting index i = 4, we are already at the end.
In total, there are 3 different starting indices i = 1, i = 3, and i = 4, where we can reach the end with some
number of jumps.
Example 3:

Input: arr = [5,1,3,4,2]
Output: 3
Explanation: We can reach the end from starting indices 1, 2, and 4.
 

Constraints:

1 <= arr.length <= 2 * 104
0 <= arr[i] < 105
*/

/*
题解
先理下题意，就是从某个位置x开始，只能往[x+1,n]这个区间跳，奇数跳只能往比arr[x]大于等于的数字跳，如果有多个大于等于arr[x]的，找最小的那个，如果最小的那个有多个相同的，找下标最小的那个。反过来偶数跳也比较好理解了。

直接反向遍历，set储存查询提速，然后用map标记每个元素的位置，再利用动态规划的思想，dp[x][0]表示位置x出发奇数跳能否到达的情况，dp[x][1]表示从位置x出发偶数跳能否到达的情况。
*/


class Solution {
public:
	int oddEvenJumps(const vector<int>& A) {
		int size = A.size();

		set<int> Set;
		Set.insert(A.back());
		unordered_map<int, int> Map;
		Map[A.back()] = size - 1;

		vector<bool> dp_odd(size);
		vector<bool> dp_even(size);

		dp_odd[size - 1] = true;
		dp_even[size - 1] = true;

		for(int i = size - 2; i >= 0; i--) {
			auto it1 = Set.lower_bound(A[i]);
			if(it1 != Set.end()) {
				int num = *it1;
				int j = Map[num];
				dp_odd[i] = dp_even[j];
			}

			auto it2 = Set.upper_bound(A[i]);
			if(it2 != Set.begin()) {
				it2 = prev(it2, 1);
				int num = *it2;
				int j = Map[num];
				dp_even[i] = dp_odd[j];
			}

            Set.insert(A[i]);
            Map[A[i]] = i;
		}

		int res = 0;
        for(int i = 0; i < size; i++) {
            if(dp_odd[i]) {
                res++;
            }
        }

		return res;
	}
};


// the same as above
class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        memset(dp, 0, sizeof(dp));
        dp[arr.size() - 1][0] = dp[arr.size() - 1][1] = 1;
        q.insert(arr[arr.size() - 1]);
        pos[arr[arr.size() - 1]] = arr.size() - 1;
        set<int>::iterator iter;

        for (int i = arr.size() - 2; i >= 0; i--) {
            iter = q.lower_bound(arr[i]); // 找大于等于，对应奇数跳
            if (iter != q.end()) {
                dp[i][0] = dp[pos[*iter]][1];
                // cout<<arr[i]<<" "<<*iter<<" "<<dp[i][0]<<endl;
            }
            iter = q.upper_bound(arr[i]); // 找大于，对应偶数跳
            if (iter != q.begin()) {
                iter--; // 等于小于等于
                dp[i][1] = dp[pos[*iter]][0];
                // cout<<arr[i]<<" "<<*iter<<" "<<dp[i][1]<<endl;
            }

            q.insert(arr[i]);
            pos[arr[i]] = i; // 更新为最小的下标
        }

        int res = 0;
        for (uint i = 0; i < arr.size(); i++) {
            if (dp[i][0] == true) // 一开始只能奇数跳
                res++;
        }
        return res;
    }

private:
    set<int> q;
    map<int, int> pos;
    bool dp[20005][2];  // dp[x][0]表示从位置x奇数跳,dp[x][1]表示从位置x偶数跳
};

int main(void) {
    Solution sol;
    // vector<int> arr = {10,13,12,14,15};
    vector<int> arr = {2,3,1,1,4};
    cout << sol.oddEvenJumps(arr) << endl;

    return 0;
}