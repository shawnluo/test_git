

// map加heap就自动排序了，
// 虽然发小了heap自动排序了，
// 但面试官说还有时间就写了下custom conditions，然后就没问题了

#include "test.hpp"

/*
    如果是int型的数据，优先队列内部已经帮我们写好了
    priority_queue<int, vector<int>, less<int>> pq;  // 最大堆
    priority_queue<int, vector<int>, greater<int>> pq;  // 最小堆
*/




int main(void) {
    string s = "sho/w me";
    char* p = (char*)s.c_str();
    p = strtok(p, "/");

    cout << p << endl;

    return 0;
}
