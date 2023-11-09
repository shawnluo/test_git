### place

1. basis
2. nearby basis with rest
3. west branch - sjpl
4. central park
5. central park library
6. Milpitas library

### new

1. [strtok/myStrtok](code_lib/chapter_1_String/1_12_strtok.cpp)
2. [227. Basic Calculator II](code_lib/basicCal.c)
3. [71. Simplify Path](https://leetcode.com/problems/simplify-path/)
4. sort by frequency
5. [1047. Remove All Adjacent Duplicates In String](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)
6. [55. Jump Game](https://leetcode.com/problems/jump-game/)
7. multithread programming
   1. pthread_cancel
   2. sigaddset, pthread_sigmask
   3. pthread_cond_signal, pthread_cond_wait
8. multiprocess programming
9. popen vs system

### snakpack

1. 二维数组
2. 一维滚动数组 - 也就是把二维数组数据压缩到只有一行。重复使用这一行数据(就是carl所说的拷贝)
   1. 从上次的数据取值，将本次计算后的值，覆盖掉本行。因为二维数组的行列矩阵数据只被斜下部的单元使用。
   2. j需要倒序。因为根据dp[j] = dp[j - weight[i]] + value，dp[j]是一维的，其取值是根据左边的数据来获取的。
   3. 如果从左边开始循环，那么左边的取值会被不断重复计入。从而影响结果。
   4. 如果从右边开始循环，因为左边的元素都是初始值0。其不会影响计算结果！
   5. 对比二维数组，其数据都是独立存在的，没有被重复使用。
3. 装满背包的最大价值是多少？    - 纯完全背包
4. 装满背包有多少种方法？求组合  - 零钱兑换2
5. 装满背包有多少种方法？求排列  - 组合总和4
6. 装满背包最少用多少个物品？    - 322零钱兑换

### array

1. photo blur
2. spiral mat
3. mat rotate
4. 返回不重复元素
5. 删除多余的空格
6. find the nth element in an array
7. meeting room

### string

1. reverse word
2. kmp strstr
3. longest increasing substring
4. context grep - google
5. longestUniqSub(s)
6. 赎金信

### sorting

1. quick sorting, partition
2. is rectangle?

### subsequence/substring

1. 最长连续上升子序列
   1. 长度
   2. 打印出上升子序列
2. isPalindrome - 是否回文
3. 排序后的单元的序列长度
4. 双指针去重
5. 判断与前一个数不相等
6. 除重后的长度 - dp解
7. 打印除重后的序列 - unordered_set
8. 未排序后的单元的序列长度
9.  除重后的长度
    1.  dp
    2.  while loop delete
    3.  打印除重后的序列
10. leetcode 1091 - the shortest path in binary matrix
11. 最短的大于某数的非连续子集和

### dp

1) BFS - breadth-first search
2) 完全平方数
3) 最长连续上升子序列
4) longest increasing items 最长上升子序列
5) leetcode 862 凑成k的最少硬币
6) 最长palindrome - 最长回文

### backTracking/recusion

1) sink island
2) permutation
3) cellphone, combination
4) 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合

### binary tree

1. binary tree travel
2. binray tree reverse
3. binary tree insert

### linkedlist

1. create linked list
2. insert ll
3. del ll
4. sort LL
5. linked list reverse
6. merge 2 sorted arrays
7. remove duplicated node from LL
8. add 2 linked lists

### bits manipulate

1. calculat 1s in a int
2. volatile register bit operation
3. print int as binary

### embedded

1. code - small ending?
2. pcie
   1. enumoration
   2. BAR

### double pointers

1. 环形链表
2. sum of shortest consective array items, which larger than given value (连续子集和大于某数，求其中最短的连续子集长度)

### others

1. read4()

### c++

1. exception: http://c.biancheng.net/view/2332.html

### hash

1. 两个数组的交集
2. 赎金
3. 两数和
4. 求组合：四个数组中分别选取一个数，其四数之和等于0
5. 一个数组中，三数之和等于0，无重

### c++

1. friend
2. unordered_heap 最大堆/最小堆

### system design

1. IPC
2. interrupt - top half - bottom half
3. PCI-e enumuration
4. network device driver
5. design a firmware DoIP system
6. DoIP
7. Parking
8. Hash collision
