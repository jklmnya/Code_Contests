class Solution {
public:
	long long maximumSubsequenceCount(string text, string pattern) {
		long long res = 0ll;
		char c1 = pattern[0], c2 = pattern[1];
		int cnt1 = 0, cnt2 = 0;
		int n = text.size();
		int f1[n], f2[n];
		memset(f1, 0, sizeof f1);
		memset(f2, 0, sizeof f2);
		for (int i = text.size() - 1; i >= 0; --i) {
			if (text[i] == c2)
				++cnt2;
			f2[i] = cnt2;
		}
		for (int i = 0; i < n; ++i) {
			if (text[i] == c1)
				++cnt1;
			f1[i] = cnt1;
		}
		long long now = 0ll;
		for (int i = 0; i < n; ++i) {
			if (text[i] == c1) {
				if (c1 == c2) {
					if (i < n - 1)
						now += f2[i + 1];
				}
				else {
					now += f2[i];
				}
			}
		}

		// cout << now << '\n';

		int add = 0;
		for (int i = 0; i < n; ++i) {
			add = max(add, max(f2[i], f1[i]));
		}
		return now + add;
	}
};