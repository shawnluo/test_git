#include "test.hpp"

#include <cstdio>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <unordered_set>

class Solution {
public:
	static int findLHS(vector<int> nums) {
		// 哈希表法

		// 定义集合map，保存数组中每个数字出现的次数
		unordered_map<int, int> map;

		// 遍历数组，统计数组中每个数字出现的次数
		for (int num : nums) {
			map[num]++;
		}

		// 定义最长的和谐子序列的长度
		int maxLength = 0;

		// 遍历集合map中的key
		for(int i = 0; i < map.size(); i++) {
			
		}

		for (auto key : map) {
			// 寻找是否存在比当前key大1的key，因为和谐子序列是最大值和最小值的差正好是1
			if (map.containsKey(key + 1)) {
				// 当前和谐子序列的长度是key的次数和key+1的次数之和，因为子序列不一定连续，所以任意两个最大值和最小值都可以去构造出和谐子序列
				maxLength = Math.max(maxLength, map.get(key) + map.get(key + 1));
			}
		}

		// 返回最长的和谐子序列的长度
		return maxLength;
	}
};

int main(void) {
    vector<int> nums{ 2, 3, -2, 4 };
    cout << Solution::findLHS(nums) << endl;

    return 0;
}