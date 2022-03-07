class Solution {
public:
	int minMovesToMakePalindrome(string ss) {
		int res = 0, cnt = 0, n = static_cast<int>(ss.size());
		bool st[n];
		memset(st, 0, sizeof st);
		int s = 0;
		while (cnt != n) {
			if (!st[s]) {
				int e = n - 1, un_vis = 0;
				while (e >= s && (ss[e] != ss[s] || (ss[e] == ss[s] && st[e]))) {
					if (!st[e])
						++un_vis;
					--e;
				}
				if (s == e) {
					res += un_vis >> 1;
					++cnt;
				}
				else {
					res += un_vis;
					cnt += 2;
				}
				st[s] = st[e] = true;
			}
			++s;
		}
		return res;
	}
};