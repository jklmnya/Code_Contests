class Solution {
public:
	bool divideArray(vector<int>& nums) {
		unordered_map<int, int> vv;
		for (int num : nums)
			++vv[num];
		for (auto& [k, v] : vv) {
			if (v % 2)
				return false;
		}
		return true;
	}
};