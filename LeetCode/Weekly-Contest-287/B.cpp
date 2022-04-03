class Solution {
public:
	vector<vector<int>> findWinners(vector<vector<int>>& matches) {
		vector<vector<int>> res(2);
		int n = matches.size();
		unordered_map<int, int> vv;
		unordered_set<int> ss;
		for (auto& m : matches) {
			int w = m[0], l = m[1];
			++vv[l];
			ss.insert(w);
			ss.insert(l);
		}
		for (auto& [k, v] : vv) {
			if (v == 1)
				res[1].push_back(k);
		}
		for (int p : ss) {
			if (vv.count(p) == 0)
				res[0].push_back(p);
		}
		sort(res[0].begin(), res[0].end());
		sort(res[1].begin(), res[1].end());
		return res;
	}
};