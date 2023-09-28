void permutation(string s, int pos) {
    int size = s.size();
    if(pos == size){
        cout << s << endl;
    }
    for(int i = pos; i < size; i++) {
        swap(s[i], s[pos]);
        permutation(s, pos + 1);
        swap(s[i], s[pos]);
    }
}