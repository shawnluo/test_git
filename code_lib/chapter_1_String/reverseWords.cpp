// 2. reverse the order of words in a string
void reverseStr(string& s, int left, int right){
    for (int i = left, j = right; i < j; i++, j--) {
        swap(s[i], s[j]);
    }
}

void removeSpaces(string& s) {
    int slow = 0;
    for (int i = 0; i < s.size(); ++i) { //
        if (s[i] != ' ') {
            if (slow != 0) {
                s[slow++] = ' ';
            }
            while (i < s.size() && s[i] != ' ') {
                s[slow++] = s[i++];
            }
        }
    }
    s.resize(slow);
}

string reverseWords(string s) {
    if(s.empty()) {
        return "";
    }

    removeSpaces(s);
    reverseStr(s, 0, s.size() - 1);
    int start = 0;
    for (int i = 0; i <= s.size(); ++i) {
        if (i == s.size() || s[i] == ' ') {
            reverseStr(s, start, i - 1);
            start = i + 1;
        }
    }
    return s;
}

int main(void) {
    // case 1
    string s1 = "I love San Diego";

    // case 2
    string s2 = "I love San Diego ";

    // case 3
    string s3 = " I love San Diego!";

    // case 4
    string s4 = "";

    // case 5
    string s5 = " I love San   Diego!"

    string s = reverseWords(s3);
    cout << s << endl;
}
