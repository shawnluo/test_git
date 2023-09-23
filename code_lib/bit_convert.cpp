

/*
 cracking the coding 5.5
  Write  a  function  to  determine  the  number  of  bits  required  to 
  convert  integer  A  to integer B
  Input: 31, 14       1,1111  0,1110
  Output: 2
*/


int bitSwapRequired(int a, int b) {
    int count = 0;
    for(int x = a ^ b; x != 0; x = x >> 1) {
        cout += x & 1;
    }
    return count;
}