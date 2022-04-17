class Solution {
public:
	int findClosestNumber(vector<int>& nums) {
		int res = INT_MAX;
		int d1 = INT_MAX;
		for (int num : nums) {
			int d2 = abs(num);
			if (d1 == d2) {
				res = max(res, num);
			}
			else if (d1 > d2) {
				d1 = d2;
				res = num;
			}
		}
		return res;
	}
};