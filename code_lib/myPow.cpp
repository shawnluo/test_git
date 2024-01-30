uint64_t myPow(int base, int n) {
    if(base == 0) return 0;
    if(n == 0) return 1;

    if(n < 0) {
        base = 1 / base;
        n = -n;
    }

    uint64_t res = 1.0;
    for(int i = 1; i <= n; i++) {
        res *= base;
    }
    return res;
}