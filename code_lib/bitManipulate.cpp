

// ----------------- solution 1: 使用异或操作符 ---------------------------
/* 
    question:
        create a mask, from start to end, set to 1
        start: 1, end: 2   ->   0000,0110

    solution: 使用异或
        1. get a left
            set [0, end] to all 1
        2. get a right
            set [0, start] to all 1
        3. return left ^ right  (exclusive operation)
*/
uint32_t setMask_AllOne(uint32_t start, uint32_t end) {
    if(start >= 31 || end >= 31) {
        return 0;
    }
    uint32_t left = (1 << start) - 1;
    uint32_t right = (1 << end) - 1;

    return left ^ right;
}

/*
    question:
        create a mask, from start to end, set to 0
        start: 1, end: 2  -> 1111,1001

    solution:
        直接将setMask取反。
*/
uint32_t setMask_AllZero(uint32_t start, uint32_t end) {
    return ~setMask(start, end);
}


// ----------------- solution 2: 使用~0这个max来对left和right 来进行操作---------------------------
uint32_t setMask_AllZero(uint32_t start, uint32_t end) {
    int max = ~0;

    int left = max - ((1 << j) - 1);
    int right = ((1 << i) - 1);

    int mask = lef | right; //i和j之间，全0

    return mask;
}

/*
    You  are  given  two  32-bit  numbers,  N  and  M,  and  two  bit  positions,  
    i  and  j  Write  a method to set all bits between i and j in N equal to M 
    (e g  , M becomes a substring of N located at i and starting at j)   
    EXAMPLE:Input: N = 10000000000, M = 10101, i = 2, j = 6Output: N = 10001010100
*/
uint32_t updateBits(int n, int m, int i, int j) {
    uint32_t mask = setMask_AllZero(i, j);

    return (n & mask) | (m << i);
}
