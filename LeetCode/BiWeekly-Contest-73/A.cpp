class Solution {
public:
	int mostFrequent(vector<int>& nums, int key) {
		unordered_map<int, int> vv;
		int n = static_cast<int>(nums.size());
		for (int i = 0; i < n - 1; ++i) {
			if (nums[i] == key)
				vv[nums[i + 1]]++;
		}
		int res = -1, cnt = 0;
		for (auto&& [k, v] : vv) {
			if (v > cnt) {
				cnt = v;
				res = k;
			}
		}
		return res;
	}
};