
void swapXOR() {
    int a = 1;
    int b = 2;

    a = a ^ b;
    b = a ^ b;  // b = a ^ b ^ b = a
    a = a ^ b;  // a = a ^ b ^ a = b
}
