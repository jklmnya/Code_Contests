class Solution {
public:
	int minBitFlips(int start, int goal) {
		int res = 0;
		for (int i = 0; i < 31; ++i) {
			int x = (start >> i) & 1;
			int y = (goal >> i) & 1;
			if (x != y)
				++res;
		}
		return res;
	}
};