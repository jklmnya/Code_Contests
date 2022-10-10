class Solution {
public:
	int triangularSum(vector<int>& nums) {
		while (nums.size() >= 2) {
			int f = 0;
			for (int i = 0; i < nums.size() - 1; ++i)
				nums[f++] = (nums[i] + nums[i + 1]) % 10;
			nums.resize(f);
		}
		return nums[0];
	}
};