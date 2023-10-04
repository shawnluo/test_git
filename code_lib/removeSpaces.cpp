

/*
    remove extra spaces in a sentence
    略过空格，
    直到遇到非空格，则添加一个空格。然后拷贝，直到遇到空格
*/

void removeExtraSpaces(string& s) {
    int size = s.size();
    int fast = 0;   // fast travels along old string
    int slow = 0;   // slow points to new string

    for(int fast = 0; fast < size; fast++) {
        if(s[fast] != ' ') { // 巧妙！if[fast] == ' '，则对slow无任何操作。其实就是略过空格
            if(slow != 0) {
                s[slow++] = ' ';
            }
            while(fast < size && s[fast] != ' ') {
                s[slow++] = s[fast++];
            }
        }
    }
    s.resize(slow);
}