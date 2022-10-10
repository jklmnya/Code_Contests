class Solution {

	typedef long long LL;

public:
	long long numberOfWays(string s) {
		LL res = 0ll;
		int n = s.size();
		int l1[n], l2[n], r1[n], r2[n];
		memset(l1, 0, sizeof l1);
		memset(l2, 0, sizeof l2);
		memset(r1, 0, sizeof r1);
		memset(r2, 0, sizeof r2);
		for (int i = 0, x = 0, y = 0; i < n; ++i) {
			if (s[i] == '1') {
				l1[i] = x;
				++y;
			}
			else {
				l2[i] = y;
				++x;
			}
		}
		for (int i = n - 1, x = 0, y = 0; i >= 0; --i) {
			if (s[i] == '1') {
				r1[i] = x;
				++y;
			}
			else {
				r2[i] = y;
				++x;
			}
		}
		for (int i = 0; i < n; ++i)
			res += (LL)(l1[i] * r1[i]) + (LL)(l2[i] * r2[i]);
		return res;
	}
};