#include "test.hpp"

// TODO: dp

// 0.                            - 01背包
    // 1. 二维数组
    // 2. 一维滚动数组 - 也就是把二维数组数据压缩到只有一行。重复使用这一行数据(就是carl所说的拷贝)：
            // 1. 从上次的数据取值，将本次计算后的值，覆盖掉本行。因为二维数组的行列矩阵数据只被斜下部的单元使用。
            // 2. j需要倒序。因为根据dp[j] = dp[j - weight[i]] + value，dp[j]是一维的，其取值是根据左边的数据来获取的。
                // 如果从左边开始循环，那么左边的取值会被不断重复计入。从而影响结果。
                // 如果从右边开始循环，因为左边的元素都是初始值0。其不会影响计算结果！
                // 对比二维数组，其数据都是独立存在的，没有被重复使用。

// 1. 装满背包的最大价值是多少？    - 纯完全背包
// 2. 装满背包有多少种方法？求组合  - 零钱兑换2
// 3. 装满背包有多少种方法？求排列  - 组合总和4
// 4. 装满背包最少用多少个物品？    - 322零钱兑换

// 5. 最长连续上升子序列
    // 1）. 长度
    // 2）. 打印出上升子序列

// 6. 最长上升子序列
    // 1）. 长度
    // 2）. 打印出上升子序列

// 7. 排序后的单元的序列长度
    // 1). 双指针去重
    // 2). 判断与前一个数不相等
    // 3). 除重后的长度 - dp解
    // 4). 打印除重后的序列 - unordered_set

// 8. 未排序后的单元的序列长度
    // 1）. 除重后的长度
        // 1. dp
        // 2. while loop delete
    // 2）. 打印除重后的序列

// 9. leetcode 1091 - the shortest path in binary matrix
    // 1. BFS - breadth-first search

// 24 完全平方数
// dp[j] = min(dp[j], dp[j - i * i] + 1)


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