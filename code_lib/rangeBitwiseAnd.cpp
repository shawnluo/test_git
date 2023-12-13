
int rangeBitwiseAnd(int lhs, int rhs) {
    int count = 0;

    // 只要找到lhs 和 rhs 的共同部分。- 因为递增数，除了共同高位之外，其他部分相与的结果一定是0。
    for(; lhs != rhs; ) {
        lhs >>= 1;
        rhs >>= 1;
        count++;
    }
    return lhs << count; // lhs和rhs已经只剩下共同位了。那么左移count，就得到与的结果了。
}