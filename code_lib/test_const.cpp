void test_const() {
    char s[20] = "abc";
    const char* p1 = s;
    p1++;           // ok
    p1[0] = 'x';    // ng

    char* const p2 = s;
    p2++;               // ng
    p2[0] = 'y';     // ok

    // cout << p1[0] << endl;
    cout << p2[0] << endl;
}