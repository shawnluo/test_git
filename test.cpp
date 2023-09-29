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

// void test() {
//     vector<int> nums{-1, 1, 1, 2, 2, 2, 3, 3};

//     int low = 0;
//     for(int i = 0; i < nums.size() - 1; i++) {
//         if(nums[i] != nums[i + 1]) {
//             nums[low++] = nums[i];
//         }
//     }
//     nums[low] = nums.back();
//     cout << nums.back() << endl;

//     for(int i = 0; i <= low; i++) {
//         cout << nums[i] << " ";
//     }
//     cout << endl;
// }

// int lenOfNorep(vector<int>& nums) {
//     int count = 1;

//     for(int i = 1; i < nums.size(); i++) {
//         if(nums[i] != nums[i - 1]) {
//             nums[count] = nums[i];
//             count++;
//         }
//     }
//     return count;
// }

// void permutation(string s, int pos) {
//     int size = s.size();
//     if(pos == size){
//         cout << s << endl;
//     }
//     for(int i = pos; i < size; i++) {
//         swap(s[i], s[pos]);
//         permutation(s, pos + 1);
//         swap(s[i], s[pos]);
//     }
// }

// void removeExtraSpaces(string& s) {
//     int size = s.size();
//     int fast = 0;   // fast travels along old string
//     int slow = 0;   // slow points to new string

//     for(int fast = 0; fast < size; fast++) {
//         if(s[fast] != ' ') {
//             if(slow != 0) {
//                 s[slow++] = ' ';
//             }
//             while(fast < size && s[fast] != ' ') {
//                 s[slow++] = s[fast++];
//             }
//         }
//     }
//     s.resize(slow);
// }

/*
    1: 
    2: a, b, c
    3: d, e, f
    4: g, h, i
    5: j, k, l
    6: m, n, o
    7: p, q, r, s
    8: t, u, v
    9: w, x, y, z

    "23": abc, def -> ad, ae, af, ...
*/
// const string letterMap[10] = {...};
// void bt_5(const string& digits, int index) {
//     if(index == digits.size()) {
//         res.push_back(s);
//         return;
//     }
//     for(int i = 0; i < letters.size(); i++) {
//         s.push_back(letters[i]);
//         bt_5(digits, index + 1);
//         s.pop_back();
//     }
// }


void getNext(vector<int>& next, string s) {
    int left = 0;
    next[0] = 0;
    int size = s.size();

    for(int right = 1; right < size; right++) {
        while(left > 0 && s[right] != s[left]) {
            left = s[left - 1];
        }
        if(s[right] == s[left]) {
            left++;
        }
        s[right] = left;
    }
}

int myStrstr(string s, string t) {
    int j = 0;  // prefix
    vector<int> next(t.size(), 0);
    getNext(next, t);
    for(int i = 0; i < s.size(); i++) { // i: surfix
        while(j > 0 && s[i] != t[j]) {
            j = next[j - 1];
        }
        if(s[i] == t[j]) {
            j++;
        }
        if(j == t.size()) {
            return i - t.size() + 1;
        }
    }
    return - 1;
}

void matRotate(vector<vector<int>>& mat) {
    int size = mat.size();
    for(int i = 0; i < size / 2; i++) {
        for(int j = i; j < size - i - 1; j++) {
            int save = mat[i][j];
            mat[i][j] = mat[j][size - i - 1];
            mat[j][size - i - 1] = mat[size - i - 1][size - j - 1];
            mat[size - i - 1][size - j - 1] = mat[size - j - 1][i];
            mat[size - j - 1][i] = save;
        }
    }
}

int partition(int* nums, int start, int end) {
    int j = start - 1;

    for(int i = start; i < end; i++) {
        if(nums[i] > nums[end]) {
            j++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[j], nums[end]);
    return j;
}

void quickSort() {

}


//TODO nth biggest number


int main(void) {
    // string s = "  abc  d  e ";
    // removeExtraSpaces(s);
    // cout << s << endl;
    // cout << s.size() << endl;

    // string s = "show me";
    // string t = "mpe";

    // cout << myStrstr(s, t) << endl;

    int nums[] = {2, 8, 9, 12, 22, 3, 10};


    return 0;
}