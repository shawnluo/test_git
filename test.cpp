#include "test.hpp"

/*
    如果是int型的数据，优先队列内部已经帮我们写好了
    priority_queue<int, vector<int>, less<int>> pq;  // 最大堆
    priority_queue<int, vector<int>, greater<int>> pq;  // 最小堆
*/


void rmDup(pNode pHead) {
    pNode cur = pHead->next;
    pNode pRunner = pHead;
    pNode pPre = pHead;

    while(cur) {
        for(pRunner = pHead; pRunner != cur; ) {
            if(pRunner->data == cur->data) {
                pre->next = cur->next;
                cur = cur->next;
                break;
            }
        }
        // if dup, then skip. pPre = pPre->next;
        if(pRunner == cur) {
            pPre = cur;
            cur = cur->next;
        } else {
            pNode tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
}

int main(void) {
    rotate();

    return 0;
}