#include "test.hpp"

// abccefa
int longestUniqSub(string s) {
    int hash[256];
    for(int i = 0; i < 256; i++) {
        hash[i] = -1;
    }

    int pos = -1;
    int len = 0;
    int res = -1;
    for(int i = 0; i < s.size(); i++) {
        pos = max(pos, hash[s[i]]);
        len = i - pos;
        res = max(res, len);
        hash[s[i]] = i;
    }
    return res;
}

void sinkIsland() {
    if(x, y outof border) {
        return;
    }
    if(nums[x, y] == 0) {
        return;
    }
    sinkIsland(x + 1, y, width, length);
    sinkIsland(x - 1, y, width, length);
    sinkIsland(x, y + 1, width, length);
    sinkIsland(x, y - 1, width, length);
}

int findIsland() {
    for(x) {
        for(y) {
            if(nums[x, y] == 1){
                sinkIsland();
                count++;
            }
        }
    }
    return count;
}

dp[i]: 将i分拆，得到乘积的最大值
dp[0] = 0;
dp[1] = 0;
dp[2] = 1;
for(int i = 3; i <= n; i++) {
    for(int j = 0; j < i; j++) {
        dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
    }
}

dp[i][j]: 从[0, i]中选择，放入j容量的背包，最大价值
for(int j = weight[0]; j <= BAG; j++) {
    dp[0][j] = value[0];
}
for(int i = 0; i < weight.size(); i++) {
    for(int j = 0; j <= BAG; j++) {
        if(j >= weight[i]) {
            dp[i][j] = max(dp[i - 1][j], dp[i - weight[i]][j] + value[i]);
        } else {
            dp[i][j] = dp[i - 1][j];
        }
    }
}

dp[i]: 
for(int i = 0; i < weight.size(); i++) {
    for(int j = BAG; j >= weight[i]; j--) {
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
}

// find the sum, if sum % 2 == 1, return false
// find half, if 


// sink island
done
// binary tree travel
done
// binray tree reverse
done
// binary tree insert
done
// linked list reverse
done
// merge 2 sorted arrays
done

------------ bits manipulate
// calculat 1s in a int
done

------------ LL
// sort LL
done
// 2 linked lists merge
done
// remove duplicated node from LL
done
// 2 linked lists add
done

------------ string
// reverse word
done
// kmp strstr
done
// longest increasing substring
done
// volatile register bit operation
done
// small ending?
done

// context grep
done

// longestUniqSub(s)
done

// . 最长连续上升子序列
done

// . bit manipulate (cracking the code)

// leetcode 862 凑成k的最少硬币

// 滑动窗口

// . strstr
    // 1. brute force
    // 2. kmp

// . sum of shortest consective array items, which larger than given value (连续子集和大于某数，求其中最短的连续子集长度)
    
// . print int as binary

// . 最短的大于某数的非连续子集和

// . create linked list
// . insert ll
// . del ll

// . 最长palindrome
    // . isPalindrome
// . permutation
// . zerocopy mmap
// . longest increasing items 最长上升子序列




// ioremap

--------------------- pcie
// enume
// BAR