/*
201. Bitwise AND of Numbers Range
Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: left = 5, right = 7
Output: 4
Example 2:

Input: left = 0, right = 0
Output: 0
Example 3:

Input: left = 1, right = 2147483647
Output: 0
 

Constraints:

0 <= left <= right <= 231 - 1

*/


/* 
    inclusive means including left and right 包括左和右
    [26 30]
    26   11 010
    27   11 011
    28   11 100
    29   11 101
    30   11 110

    规律就是找到左边公共部分 - 公共部分是 1 的部分
    那么就是left和right共同右移，记下右移的次数，直到left和right相等。然后再将此时的left左移移动次数。
*/
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;

        while(left != right) {
            left >>= 1;
            right >>= 1;
            count++;
        }
        return left << count;
    }
};