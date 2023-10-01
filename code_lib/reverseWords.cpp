

/* reverse words in a sentence: 
    show me   ->     wohs em
*/


// remove extra spaces: front, mid, end
void removeExtraSpaces(string& s) {
    int fast = 0;   // 在老的字符串中travel
    int slow = 0;   // 指向新的字符串

    for(fast = 0; fast < s.size(); fast++) {
        // 如果遇到空格，fast就向前走越过空格

        // 否则，遇到了非空格
        if(s[fast] != ' ') {
            // 如果是开头，那么新字符串就不用保留空格

            if(slow != 0) {     // 如果不是开头，那么新字符串留一个空格
                s[slow++] = ' ';
            }
            while(fast < s.size() && s[fast] != ' ') { // 不是空格， 那么就拷贝到新字符串中
                s[slow++] = s[fast++];
            }
            // fast 现在指向了空格
        }
    }
    s.resize(slow);
}


void reverse(string& s, int start, int end) {
    if(s.size() <= 1) return;

    int left = start;
    int right = end;
    while(left < right) {
        swap(s[left], s[right]);
    }
}

void reverseWords(string& s) {
    removeSpaces(s);
    int start = 0; 
    int end = 0;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == ' ') {
            end = i + 1;
            reverse(s, start, end);
            start = i - 1;
        }
    }

    reverse(s, 0, s.size() - 1);    // don't forget the last word, not end with space
}

int main(void) {
    string s = "  show   me the    money  ";

    reverseWords(s);
    cout << s << endl;

    return 0;
}