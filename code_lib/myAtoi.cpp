/*
题目：字符串转换整数 (atoi)
请你来实现一个 atoi 函数，使其能将字符串转换成整数。

首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。

当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。

该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。

注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。

在任何情况下，若函数不能进行有效的转换时，请返回 0。

说明：

假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，qing返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。

示例1：

输入: "42"
输出: 42
示例 2：

输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
示例 3：

输入: "4193 with words"
输出: 4193
解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字
示例 4：

输入: "words and 987"
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
     因此无法执行有效的转换。
示例 5：

输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。
     因此返回 INT_MIN (−231) 。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/string-to-integer-atoi/
*/

/*#解题思路
1.首先设置变量:

i:当前遍历位置
isNegative: 判断转化结果是否为负数
2.先从判断字符串前面有没有空格开始，如果有则一直遍历下去，i一直加1
3.当检测到有加减符号后，如果是减号，isNegative为true
4.利用字符串编码的性质,比如字符串0的编码为48，1的编码为49，2的编码为50，以此类推，那么可以得出0-9的编码是48-57，因此可以根据str.charCodeAt(i)-48得出差值计算当前字符是否可以转换为数字，如下:

假设str='13a12',i从0开始遍历，str.charCodeAt(i)-48=1，0<1<9,当前字符符合要求，i加1，结果值res*10后与当前字符相加
i=1，str.charCodeAt(i)-48=3，0<3<49，符合要求，同上操作
i=2时，str.charCodeAt(i)-48=49，49>9，不符合要求，转换停止
5.通过isNegative判断是否需要给res转化为负数

#代码实现
*/

// library function: string to integer
string s = "12"; 
int a = atoi(s.c_str());

// library function: integer to string
std::string pi = "pi is " + std::to_string(3.1415926);
std::string perfect = std::to_string(1+2+4+7+14) + " is a perfect number";
std::cout << pi << '\n';
std::cout << perfect << '\n';


class Solution {
public:
    int myAtoi(string input) {
        int sign = 1;
        int res = 0;
        int index = 0;
        int n = input.size();

        while(index < n && input[index] == ' ') {
            index++;
        }

        if(index < n && input[index] == '+') {
            sign = 1;
            index++;
        } else if(index < n && input[index] == '-') {
            sign = -1;
            index++;
        }

        while(index < n && isdigit(input[index])) {
            int digit = input[index] - '0';
            if((res > INT_MAX / 10) || (res == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + digit;
            index++;
        }

        return sign * res;
    }
};