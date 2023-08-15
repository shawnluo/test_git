#include "test.hpp"


// 1, 2, 5, 10, 20
// dp[j] 从0_i中选择，一共有多少中组合
// dp[j] = 
// int change(int amount, vector<int>& coins, int mount) {
//     vector<int> dp(coins.size() + 1, 0);

//     dp[j] = dp[j] + dp[j - coins[i]];   // 等式右边的 1. dp[j]:            是当取上一个i时dp[j]的值。
//                                         //           2. dp[j - coins[i]]: 不取当前硬币，减去当前硬币面试的dp[j]的值
// }

#if 0
// 有n件物品，和一个容量为BAG的背包
// 第i件物品：重量是weight[i], 价值是value[i]。
// 将物品装入背包里，得到物品价值总和最大
// - 每件物品只能用一次
// 1. 得到的最大重量，二维数组/一维数组
// 2. 哪些物品

int bag(vector<int> weight, vector<int> value, int bagSize) {
    vector<vector<int>> dp(weight.size(), vector<int> (weight.size(), 0));
    // 定义：    dp[j]: 背包容量为j时，装入的物品的最大价值
    // 推导公式：dp[i][j] = dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]
    for()
}
#endif


// 从[0, num]之中取值，组成 k个元素的组合，获取所有的组合
vector<vector<int>> res;
vector<int> buf;
// int sum = 0;
void combination(int num, int k, int startIndex) {
    if(k == 0) {
        res.push_back(buf);
        return;
    }

    // 0. 弄清楚解法思路：第一层循环
    // n = 7, k = 3: 
    for(int i = startIndex; i < num; i++) {  // 1. 为什么i从0开始，对比string combination()
        // sum += i;
        buf.push_back(i);
        combination(num, k - 1, startIndex + 1);  // 2. 为什么是i + 1，而不是startIndex + 1
                                                  // startInndex + 1, 那么子集就会从 startIndex + 1开始。
                                                  // 这里startIndex = 0, 那么每次就是从1开始
                                                  // 如果是i + 1，那么子集都会从i++开始，也就是1, 2, 3,...
        buf.pop_back();
    }
}


// house robber
// roober, house, don't break into two ajacent house, the maximum amount of money
int rob(vector<int> nums) {
    // 不偷 : dp[i - 1]
    // 偷   : dp[i - 2] + nums[i]
    // dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])

    int len = nums.size();
    if(len == 0) {
        return 0;
    }
    if(len == 1) {
        return nums[0];
    }
    vector<int> dp(len);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < nums.size(); i++) {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[len - 1];
}

int partition(vector<int>& nums, int left, int right) {
    int save = nums[left];
    while(left < right) {
        while(left < right && nums[right] <= save) {
            right--;
        }
        if(left < right) {
            nums[left++] = nums[right];
        }
        while(left < right && nums[left] >= save) {
            left++;
        }
        if(left < right) {
            nums[right--] = nums[left];
        }
    }
    num[left] = save;
    return left;
}

int quickSort(vector<int>& nums, int left, int right, int k) {
    // if(left < right) {
        int pivot = partition(nums, left, right);
        if(pivot == k) {
            return pivot;
        }
        if(mid > key) {
            quickSort(nums, left, pivot - 1, k);
        } else {
            quickSort(nums, mid + 1, right, k);
        }
}

int findKthLargest(vector<int>& nums, int k) {
    // left, right, mid
    quickSort(nums, 0, nums.size(), k);
}

int main(void){
    combination(3, 2, 0);
    
    for(auto i : res) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}


// TODO: 1. n件物品，装满容量为bagSize的背包的所有物品的最大价值
// TODO: 2. n件物品，不重复取，是否能装满容量为bagSize的背包
// TODO: 3. n件物品，重复取，装满容量为bagSize的背包的物品组合

int partition(int* nums, int start, int end) {
    int save = nums[start];
    while(start < end) {
        while(start < end && nums[end] <= save) {
            end--;
        }
        if(start < end) {
            nums[start++] = nums[end];
        }
        while(start < end && nums[start] >= save) {
            start++;
        }
        if(start < end) {
            nums[end--] = nums[start];
        }
    }
    nums[start] = save;
    return start;
}

int findIt(int *nums, int numsSize, int start, int end, int key) {
    //if(start >= end) return;
    int mid = partition(nums, start, end);
    if(mid == key) return mid;

    if(mid > key)   findIt(nums, numsSize, start, mid - 1, key);
    else            findIt(nums, numsSize, mid + 1, end, key);

    return;
}


int findKthLargest(int* nums, int numsSize, int k){
    int res = findIt(nums, numsSize, 0, numsSize - 1, k - 1);
    return nums[res];
}