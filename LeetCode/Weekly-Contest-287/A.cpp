class Solution {
public:
	int convertTime(string current, string correct) {
		int h1 = (int)(current[0] - '0') * 10 + (int)(current[1] - '0');
		int m1 = (int)(current[3] - '0') * 10 + (int)(current[4] - '0');
		int h2 = (int)(correct[0] - '0') * 10 + (int)(correct[1] - '0');
		int m2 = (int)(correct[3] - '0') * 10 + (int)(correct[4] - '0');
		m1 = h1 * 60 + m1, m2 = h2 * 60 + m2;
		int ss[] = { 60, 15, 5, 1 };
		int res = 0;
		for (int i = 0; i < 4; ++i) {
			while (m2 - m1 >= ss[i]) {
				++res;
				m1 += ss[i];
			}
		}
		return res;
	}
};