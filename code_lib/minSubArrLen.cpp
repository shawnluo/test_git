vector<int> minLen(vector<int> nums, int s) {
	int res = INT_MAX;
	int sum = 0;
	int i = 0;
	int subSize = 0;

	for(int j = 0; j< nums.size(); j++) {
		sum += nums[j];
		while(sum >= s) {
			subSize = j - i + 1;
			res = max(res, subSize);
			sum -= nums[i++];
		}
	}
	return res == INT_MAX ? 0 : res;
}