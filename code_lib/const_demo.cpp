


int main(void) {
    // int x = 0b110;
    // string s = "1101.111";
    // double res = binaryFractionToDecimal(s);
    // cout << res << endl;

    // int2Bin(12);

    int m = 500;
    int n = 100;
    
    // const 修饰 *p,  *p不能被修改， p可以被修改
    const int *p = &m;
    p = &n;     // ok
    *p = 15;    // fail
    cout << *p << endl;


    // const 修饰 p2，p2 不能被修改， 但是 *p2 可以被修改
    int* const p2 = &n;
    p2 = m;     // fail
    *p2 = 14;   // ok
    cout << *p2 << endl;

    return 0;
}