

/*
    remove extra spaces in a sentence
*/

void removeSpaces(string& s) {
    int slow = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != ' ') {
            if(slow != 0) {
                s[slow++] = ' ';
            }
            while(i < s.size() && s[i] != ' ') {
                s[slow++] = s[i++];
            }
        }
    }
    s.resize(slow);
}