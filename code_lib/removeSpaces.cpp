

/*
    remove extra spaces in a sentence
*/

void removeExtraSpaces(string& s) {
    int size = s.size();
    int fast = 0;   // fast travels along old string
    int slow = 0;   // slow points to new string

    for(int fast = 0; fast < size; fast++) {
        if(s[fast] != ' ') {
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