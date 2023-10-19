#include "test.hpp"


void removeExtraSpaces(string& s) {
    int slow = 0;

    for(int fast = 0; fast < s.size(); fast++) {
        if(s[fast] != ' ') {
            if(slow > 0) {
                s[slow++] = ' ';
            }
            while(fast < s.size() && s[fast] != ' ') {
                s[slow++] = s[fast++];
            }
        }
    }
    s.resize(slow);
}

void reverseStr(string& s, int start, int end) {
    while(start < end) {
        swap(s[start++], s[end--]);
    }
}

void reverseWords(string& s) {
    int start = 0;
    int end = 0;
    removeExtraSpaces(s);
    // cout << s << endl;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') {
            end = i - 1;
            reverseStr(s, start, end);
            start = i + 1;
        }
    }
    reverseStr(s, 0, s.size() - 1);

    // return s;
}


void context_grep(int argc, char** argv, int context, char* expr) {
    if(argc <= 0 || argv == nullptr || expr == nullptr || context < 0) {
        return;
    }

    int firstTime = -1;
    int lastTime = -1;
    for(int i = 0; i < argc; i++) {
        if(strstr(argv[i], expr) != nullptr) {
            if(firstTime == -1) {
                firstTime = i;
            }
            lastTime = i;
        }
    }
    if(firstTime == -1) return;

    vector<string> res;
    for(int i = context; i > 0 && lastTime-- > 0; i--) {
        res.insert(res.begin(), argv[firstTime]);
    }

    for(int i = 0; i < context && lastTime++ < argc; i--) {
        res.push_back(argv[lastTime]);
    }

    for(auto x : res) {
        cout << x << endl;
    }
}

char *argv[] = {
    "Hello world",
    "Welcome to California",
    "Goodbye",
    "Big sky",
    "Nice job",
    "Blue sky",
    "Hey Joe",
    "great hill",
};

int main() {
    // case 1
    context_grep(6, argv, 2, "sky");
    
    // case 2: no print
    // context_grep(6, argv, -1, "sky");

    // // case 3: 
    // context_grep(6, argv, 1, "sky");

    // // case 4: 
    // context_grep(6, argv, 1, "sy");

    // // case 5: 
    // context_grep(0, argv, 1, "sy");

    // // case 6: 
    // context_grep(-1, argv, 1, "sy");

    // // case 7: 
    // context_grep(6, nullptr, 1, "sy");

    // // case 8: 
    // context_grep(6, argv, 1, nullptr);

    // // case 9: 
    // context_grep(6, argv, 11, "sky");

    // // case 10: 
    // context_grep(6, argv, 0, "sky");

    return 0;
}

// int main(void) {
//     string s = "   show me   the   !   ";
//     reverseWords(s);

//     cout << s << endl;

//     return 0;
// }