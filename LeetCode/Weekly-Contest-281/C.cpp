class Solution {

public:
	string repeatLimitedString(string s, int repeatLimit) {
		int f[26];
		memset(f, 0, sizeof f);
		for (char ch : s)
			++f[ch - 'a'];
		string res = "";
		char lastChar = '.';
		while (1) {
			char maxChar = '.';
			int idx = -1;
			for (int i = 25; i >= 0; --i) {
				if (f[i]) {
					maxChar = (char)(i + 'a');
					idx = i;
					break;
				}
			}
			if (maxChar == '.' || maxChar == lastChar)
				break;
			lastChar = maxChar;
			while (f[idx]) {
				if (f[idx] > repeatLimit) {
					string s(repeatLimit, maxChar);
					res += s;
					bool ff = false;
					f[idx] -= repeatLimit;
					for (int i = idx - 1; i >= 0; --i) {
						if (f[i]) {
							res += (char)(i + 'a');
							--f[i];
							ff = true;
							break;
						}
					}
					if (!ff)
						break;
				}
				else {
					string s(f[idx], maxChar);
					f[idx] = 0;
					res += s;
				}
			}
		}
		return res;
	}
};