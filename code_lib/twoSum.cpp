
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map; // key是数组元素，data是元素的下标

    for(int i = 0; i < nums.size(); i++) {

        // 遍历当前元素，并在map中查找是否有匹配的key
        auto iter = map.find(target - nums[i]);
        if(iter != map.end()) {
            return {iter->second, i};
        }

        // 如果没找到匹配对，就把访问过的元素和下标加入到map中。以供下次查找
        map.insert(pair<int, int>(nums[i], i));
    }
    return {};
}