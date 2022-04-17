class Solution {
public:
	int minimumRounds(vector<int>& tasks) {
		unordered_map<int, int> vv;
		for (int t : tasks)
			++vv[t];
		int res = 0;
		for (auto& [k, v] : vv) {
			if (v < 2)
				return -1;
			if (v % 3 == 0) {
				res += v / 3;
			}
			else if (v % 3 == 1) {
				res += v / 3 - 1 + 2;
			}
			else if (v % 3 == 2) {
				res += v / 3 + 1;
			}
		}
		return res;
	}
};