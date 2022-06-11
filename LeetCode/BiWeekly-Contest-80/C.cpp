class Solution {

	unordered_map<char, unordered_set<char>> ss;

public:
	bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
		ss.clear();
		for (const auto& m : mappings) {
			char x = m[0], y = m[1];
			ss[x].emplace(y);
		}
		int n = s.size(), m = sub.size();
		for (int left = 0, right; (right = left + m - 1) < n; ++left) {
			bool f = true;
			for (int i = left, j = 0; i <= right; ++i, ++j) {
				if (s[i] != sub[j] && (!ss.count(sub[j]) || !ss[sub[j]].count(s[i]))) {
					f = false;
					break;
				}
			}
			if (f)
				return true;
		}
		return false;
	}
};