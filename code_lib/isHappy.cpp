int calcSum(int n) {
    int sum = 0;
    while(n) {
        sum += pow(n % 10, 2);
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    // save the cal result to set, if find repeated data, then return false
    unordered_set<int> set;

    // int sum = 0;
    while(n != 1) {
        n = calcSum(n);
        if(n == 1) {
            return true;
        }
        if(set.find(n) != set.end()) {
            return false;
        } else {
            set.insert(n);
        }
    }

    // return true;
}

int main(void) {

    cout << isHappy(11) << endl;
    return 0;
}