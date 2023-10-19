
#include "test.hpp"

vector<vector<int>> generateMatrix(int n) {
    int half = n >> 1;
    int startX = 0;
    int startY = 0;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    int count = 1;
    int offset = 1;

    while(half--) {
        int x = startX;
        int y = startY;

        for( ; y < n - offset; y++) {
            mat[x][y] = count++;
        }
        for( ; x < n - offset; x++) {
            mat[x][y] = count++;
        }
        for( ; y > startY; y--) {
            mat[x][y] = count++;
        }
        for( ; x > startX; x--) {
            mat[x][y] = count++;
        }
        startX++;
        startY++;
        offset += 1;
    }

    if(n % 2) {
        mat[n / 2][n / 2] = count;
    }
    return mat;
}

pListNode swapPairs(pNode pHead) {
    pNode pDummy = new ListNode(0);
    pDummy->next = pHead;
    pCur = pDummy;

    while(pCur->next != nullptr && pCur->next->next != nullptr) {
        pListNode p1 = pCur->next;
        pListNode p2 = pCur->next->next;
        pListNode p3 = pCur->next->next->next;

        pCur-next = p2;
        p2->next = p1;
        p1->next = p3;

        pCur = pCur->next->next;
    }
    return pDummy->next;
}

int main() {
    vector<vector<int>> res = generateMatrix(3);
    for(auto x : res) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    // pNode pHead = nullptr;
    // createLL(pHead, nums);
    // showMe(pHead);

    // insertLL_Left(&pHead, 3, 299);
    // insertLL_Right(pHead, 3, 301);
    // showMe(pHead);

    return 0;
}