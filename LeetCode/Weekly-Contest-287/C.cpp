class Solution {
public:
	int maximumCandies(vector<int>& c, long long k) {
		long long sum = accumulate(c.begin(), c.end(), 0ll);
		if (sum < k)
			return 0;
		int left = 1, right = *max_element(c.begin(), c.end());
		while (left <= right) {
			int mid = (left + right) >> 1;
			long long f = 0ll;
			for (int num : c)
				f += num / mid;
			if (f >= k)
				left = mid + 1;
			else if (f < k)
				right = mid - 1;
		}
		return left - 1;
	}
};