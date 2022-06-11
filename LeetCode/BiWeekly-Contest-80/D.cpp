class Solution {
public:
	long long countSubarrays(vector<int>& nums, long long k) {
		long long res = 0ll;
		long long sum = 0ll;
		int n = nums.size();
		int s = 0, e = 0;
		while (e < n) {
			sum += nums[e];
			while ((long long)(e - s + 1) * sum >= k) {
				sum -= nums[s];
				++s;
			}
			res += e - s + 1;
			++e;
		}
		return res;
	}
};