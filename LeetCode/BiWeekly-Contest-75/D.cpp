class Solution {

	typedef unsigned long long ULL;
	typedef long long LL;
	static constexpr int P = 13331;
	ULL p[100005];
	ULL f[100005];

	inline ULL getHash(int l, int r) {
		return f[r] - f[l - 1] * p[r - l + 1];
	}

public:
	long long sumScores(string ss) {
		int n = ss.size();
		p[0] = 1ull;
		for (int i = 1; i <= n; ++i) {
			f[i] = (f[i - 1]) * P + (ss[i - 1] - 'a' + 1);
			p[i] = p[i - 1] * P;
		}
		LL res = 0ll;
		for (int k = 1; k <= n; ++k) {
			int s1 = 1, s2 = n - k + 1;
			int left = s2, right = n;
			while (left <= right) {
				int mid = (left + right) >> 1;
				int len = mid - s2 + 1;
				if (getHash(s1, s1 + len - 1) == getHash(s2, s2 + len - 1))
					left = mid + 1;
				else
					right = mid - 1;
			}
			res += left - s2;
		}
		return res;
	}
};