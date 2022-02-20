class Solution {

	typedef long long LL;

	int gcd(int x, int y) {
		return y ? gcd(y, x % y) : x;
	}

public:
	LL coutPairs(vector<int>& nums, int k) {
		LL res = 0ll;
		int n = static_cast<int>(nums.size());
		unordered_map<int, int> vv;
		for (int num : nums) {
			if (num > k)
				++vv[gcd(num, k)];
			else
				++vv[gcd(k, num)];
		}
		for (int num : nums) {
			int x;
			if (num > k)
				x = gcd(num, k);
			else
				x = gcd(k, num);
			for (auto& [y, v] : vv) {
				if ((LL)x * y % k == 0) {
					if (x == y)
						res += v - 1;
					else
						res += v;
				}
			}
		}
		return res >> 1;
	}
};