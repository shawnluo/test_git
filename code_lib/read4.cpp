/* =======================================================================================================
    [147] - Read N Characters Given Read4

Given a file and assume that you can only read the file using a given method read4, implement a method to read_n_characters.
Method read4:
The API read4reads 4 consecutive characters from the file, then writes those characters into the buffer arraybuf.
The return value is the number of actual characters read.
Note that read4()has its own file pointer, much likeFILE *fpin C.
Definition of read4:
    Parameter:  char[] buf
    Returns:    int

Note: buf[] is destination not source, the results from read4 will be copied to buf[]
Below is a high level example of howread4works:
File file("abcdefghijk"); // File is "abcdefghijk", initially file pointer (fp) points to 'a'
char[] buf = new char[4]; // Create buffer with enough space to store characters
read4(buf); // read4 returns 4. Now buf = "abcd", fp points to 'e'
read4(buf); // read4 returns 4. Now buf = "efgh", fp points to 'i'
read4(buf); // read4 returns 3. Now buf = "ijk", fp points to end of file
Method read:
By using theread4method, implement the method readthat readsncharacters from the file and store it in the buffer array buf. Consider that you cannot manipulate the file directly.
The return value is the number of actual characters read.
Definition of read:
    Parameters:    char[] buf, int n
    Returns:    int

Note: buf[] is destination not source, you will need to write the results to buf[]
*/

int read(char *buf, int n) {
    int copiedChars = 0;
    int readChars = 4; // 初始化为4，为while循环提供条件
    char buf4[4];
    
    while (copiedChars < n && readChars == 4) { // 巧妙！readChars != 4，读取的字节数小于4，代表上一次已经读到了文件尾部
                                                // 上次的for循环中已经处理了剩余的小于4个字节的文件。所以此次无需处理。
        readChars = read4(buf4);
        
        for (int i = 0; i < readChars; ++i) {
            if (copiedChars == n)
                return copiedChars;
            buf[copiedChars] = buf4[i];
            ++copiedChars;    
        }    
    }
    return copiedChars;
}