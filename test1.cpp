#include "test.hpp"

void myPrint(void* p, int N) {
    int(*mat)[N] = p;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d, ", mat[i][j]);
        }
        printf("\n");
    }
}


void rotate_matrix(void* p, int N) {
    int(*mat)[N] = p;

    myPrint(mat, N);

    for (int x = 0; x < N / 2; x++) {
        for (int y = 0; y < N / 2; y++) {
            int save                  = mat[x][y];
            mat[x][y]                 = mat[y][N - x - 1];
            mat[y][N - x - 1]         = mat[N - x - 1][N - y - 1];
            mat[N - x - 1][N - y - 1] = mat[N - y - 1][x];
            mat[N - y - 1][x]         = save;
        }
    }
    myPrint(mat, N);
}
#endif


void reverse(string& s, int start, int end) {
    int left = start;
    int right;
    int len = s.size();
    
    if(end > len - 1) {
        right = len - 1;
    } else {
        right = end;
    }

    while(left < right) {
        s[left] ^= s[right];
        s[right] ^= s[left];
        s[left] ^= s[right];
        left++, right--;
    }
}

// grep sub in string array
// print from the first matched string to the last matched string
// print the context



// void test(char (*argv)[], char *s, int context) {
void test(int len, char **p, char *s, int context) {
    char *argv[] = {"123", "456", "abc"};
    if(p == nullptr || s == nullptr) {
        return;
    }
    int x = 1;//sizeof(argv);// / sizeof(argv[0]);
    cout << len << endl;
    // for() {

    // }
}

void rotate(string s, int n) {
    reverse(s, 0, n - 1);
    reverse(s, n, s.size() - 1);
    reverse(s, 0, s.size() - 1);
}

void createPre(string s) {
    vector<int> next;
    next.push_back(1);
    int count = 0;
    for(int i = 1; i < s.size(); i++) {
        int left = 0;
        int right = i;
        count = 0;
        while(left <= right) {
            if(s[left] == s[right]) {
                count++;
            } else {
                break;
            }
            left++;
            right--;
        }
        next.push_back(count);
    }

    for(auto x : next) {
        cout << x << " ";
    }
    cout << endl;
}

void findNext(int *next, char* s) {
    int j = 0;
    next[0] = j;

    for(int i = 1; i < strlen(s); i++) {
        while(j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        next[i] = j;
    }
}

int main(void) {
    char *s = "aabaaf";
    createPre(s);

    int len = strlen(s);
    cout << len << endl;
    int next[len];

    findNext(next, s);
    for(auto x : next) {
        cout << x << " ";
    }
    cout << endl;

    // test(3, argv, s, 2);
    // char *argv[] = {"123", "456", "abc"};
    // cout << sizeof(argv) / sizeof(argv[0]) << endl;


    
    int mat[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    rotate_matrix(mat, 3);
    // showMe(mat);

    return 0;
}