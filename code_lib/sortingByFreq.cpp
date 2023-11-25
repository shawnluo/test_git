

// map加heap就自动排序了，
// 虽然发小了heap自动排序了，
// 但面试官说还有时间就写了下custom conditions，然后就没问题了

#include "test.hpp"

/*
    如果是int型的数据，优先队列内部已经帮我们写好了
    priority_queue<int, vector<int>, less<int>> pq;  // 最大堆
    priority_queue<int, vector<int>, greater<int>> pq;  // 最小堆
*/


class mycomparison {
public:
    // 对操作符“()”进行重载
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second > rhs.second;     // 从小到大排序
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    // 要统计元素出现频率
    unordered_map<int, int> map; // map<nums[i],对应出现的次数>
    for (int i = 0; i < nums.size(); i++) {
        map[nums[i]]++;
    }

    // 对频率排序
    // 定义一个小顶堆，大小为k
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pq;

    // 用固定大小为k的小顶堆，扫面所有频率的数值
    for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
        pq.push(*it);
        if (pq.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
            pq.pop();
        }
    }

    // while(pq.size() != 0) {
    //     res.push_back(pq.top().first);
    //     pq.pop();
    // }

    // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
    vector<int> result(k);
    for (int i = k - 1; i >= 0; i--) {
        result[i] = pq.top().first;
        pq.pop();
    }
    return result;
}

void showMe(vector<int> res) {
    for(auto it : res) {
        cout << it << " ";
    }
    cout << endl;
}

int main(void) {
    vector<int> nums = {2, 4, 5, 7, 0, 2, 7, 7, 0};
    vector<int> res = topKFrequent(nums, 3);

    showMe(res);

    return 0;
}
