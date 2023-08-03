#include "test.hpp"

// 9.2 "abc", "xyz", "acb", "zyx" -> "abc", "acb", "xyz", "zyx"

void test() {
    vector<string> arr = {"abc", "aaa"};
    cout << arr[0] << endl;
    cout << arr[1] << endl;

    char s[] = "abc";
    char x[] = "abc";

    int res = arr[0].compare(arr[1]);
    cout << res << endl;
}


int search_(const vector<string> strings, int left, int right, string target) {
    while(left <= right) {
        while(left <= right && (strings[right] == "")) {
            right--;
        }

        if(left > right) {
            return -1;
        }

        int mid = (left + right) / 2;
        while(strings[mid] == "") {
            mid++;
        }
        int res = target.compare(strings[mid]);
        if(res == 0) {
            return mid;
        } else if(res < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int search(const vector<string> strings, string str) {
    if(strings.empty() == 1 || str.empty() == 1) {
        return -1;
    }
    if(str == "") {
        for(int i = 0; i < strings.size(); i++) {
            if(strings[i].compare(str) == 0) {
                return i;
            }
        }
    }
    return search_(strings, 0, strings.size() - 1, str);
}


// you cannot put the 2GB file into memory
// 1. split the data into k chunks. sort each part, and 

int main(void) {
    vector<string> s = {"abc", "", "xy", "", "", "kgb"};
    string q = "kgb";
    cout << search(s, q) << endl;

    return 0;
}