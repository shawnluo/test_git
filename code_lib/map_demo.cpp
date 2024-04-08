// 1. create
// 2. insert
// 3. delete
// 4. traverse
// 

#include "../test.hpp"
        
void test() {
    // iterate map/unordered_map
    for (auto& [key, val] : myMap) {
        cout << key << " : " << val << endl;
    }
}

vector<int> demo_unordered_map() {
    unordered_map<string, int> unmap = {
        {"show", 4},
        {"me", 1},
        {"the", 5},
        {"money", 2}
    };
    
    // 1. insert pair
    unmap.insert(pair<string, int>("tree", 5));
    unmap["tree"] = 5;

    // 2. using next
    auto it = unmap.begin();
    cout << next(it)->second << endl;

    for(int i = 0; i < unmap.size(); i++) {
        auto iter = unmap.find(i);  // 是找key, 而不是value
        if(iter != unmap.end()) {
            return {i, iter->second};   // return vector
        }
    }

    std::for_each (
        unmap.begin(), 
        unmap.end(), 
        [](std::pair<string, int> p) {
            cout << p.first << " :: " << p.second << endl;
        }
    );    

    for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
    pq.push(*it);
    if (pq.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
        pq.pop();
    }

    return {};  // return empty vector
}