class Solution {
public:
	int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
		int n = static_cast<int>(floor.size());
		if (numCarpets * carpetLen >= n)
			return 0;
		int f[n + 1];
		f[0] = 0;
		while (numCarpets--) {
			for (int i = 1; i <= n; ++i) {
				if (floor[i - 1] == '1')
					f[i] = f[i - 1] + 1;
				else
					f[i] = f[i - 1];
			}
			int fl = 0, fr = -1;
			int cnt = 0;
			for (int s = 1, e; (e = s + carpetLen - 1) <= n; ++s) {
				int now = f[e] - f[s - 1];
				if (now > cnt) {
					cnt = now;
					fl = s - 1;
					fr = e - 1;
				}
			}
			if (fr >= 0) {
				while (fl <= fr)
					floor[fl++] = '0';
			}
			else {
				break;
			}
		}
		int res = 0;
		for (char c : floor) {
			if (c == '1')
				++res;
		}
		return res;
	}
};