#include "../test.hpp"

class Solution {
public:
    int reverse(int x) {
        int res = 0;

        while(x) {
            int cur = x % 10;
            x /= 10;
            
            if(res < INT_MIN / 10 || (res == INT_MIN / 10 && cur < -8)) {
                return 0;
            }
            
            if(res > INT_MAX / 10 || (res == INT_MAX / 10 && cur > 7)) {
                return 0;
            }
            
            res = res * 10 + cur;
        }
        return res;
    }
};