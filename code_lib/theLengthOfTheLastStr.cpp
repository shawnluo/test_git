int lengthOfLastWord_x(string s) {
    int n = s.size();
    int i = n - 1;
    int count = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] != ' ') {
            while(i >= 0 && s[i] != ' ') {
                count++;
                i--;
            }
            return count;
        }
    }
    return 0;
}