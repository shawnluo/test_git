
#include "test.hpp"
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

// TODO 
// 1. meeting
// 2. memory alignment - memory copy
// 3. memory alignment - memory move
// 4. sortBy freq
// 5. calculator
// 6. longest uniq characters length

class Solution {
public:
    /* 实现任务的最优调度
        1. 通过贪心算法结合最大堆（优先队列）来实现任务的最有调度，以尽可能减少总执行时间；
        2. 相同任务之间至少需要间隔“n”个单位时间。
     */
    int leastInterval(vector<char>& tasks, int n) {
        // Building frequency map
        int freq[26] = {0};
        for (char &ch : tasks) {
            freq[ch - 'A']++;
        }

        // Max heap to store frequencies
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(freq[i]);
            }
        }

        int time = 0;
        // Process tasks until the heap is empty
        while (!pq.empty()) {
            int cycle = n + 1;
            vector<int> store;
            int taskCount = 0;
            // Execute tasks in each cycle
            while (cycle-- && !pq.empty()) {
                if (pq.top() > 1) {
                    store.push_back(pq.top() - 1);
                }
                pq.pop();
                taskCount++;
            }
            // Restore updated frequencies to the heap
            for (int &x : store) {
                pq.push(x);
            }
            // Add time for the completed cycle
            // 如何pq已经是空的了，那么增加的时间是taskCount，否则是n + 1
            time += (pq.empty() ? taskCount : n + 1);
        }
        return time;
    }
};

int main() {
    
    
    return 0;
}