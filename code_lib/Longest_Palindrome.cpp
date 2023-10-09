
#include "test.hpp"


/*
    409. Longest Palindrome

    我们先来看一看回文子串的规律，如果回文子串的长度为偶数，那么其中所有的每个元素都出现了偶数次；
    如果回文子串的长度为奇数，那么有一个元素出现了奇数次而其余每个元素都出现了偶数次。

    所以我们需要做的就是遍历一遍字符串，统计每个元素出现的次数。这里只有大写字母和小写字母，我们用一个大小为 52 的数组充当散列表即可。

    最后我们就可以得出偶数的元素有多少个，再看看有没有多余的一个奇数元素就得到了能组成的最长回文序列。

*/

int longestPalindrome(string s) {
    int hash[256] = {0};
    for(int i = 0; i < s.size(); i++) {
        hash[s[i]]++;
    }
    int even = 0;
    int odd = 0;

    for(int i = 0; i < 256; i++) {
        even += hash[i] / 2 * 2;
        odd += hash[i] % 2;
    }
    odd = odd > 0 ? 1 : 0;
    return even + odd;
}

int main(void) {
    string s = "aaaaa";
    cout << longestPalindrome(s) << endl;

    return 0;
}