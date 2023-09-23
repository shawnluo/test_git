
/*
cracking the coding 5.6

Write a program to swap odd and even bits in an integer with as few instructions as possible (e g  , bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, etc)
SOLUTIONMask
    all odd bits with 10101010 in binary (which is 0xAA), then shift them left to put them in the even bits   
    Then, perform a similar operation for even bits   This takes a total 5 instructions
*/
int swapOddEvenBits(int x) {    
    // a: 1010
    // 5: 0101 
    return ( ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1) );
} 
