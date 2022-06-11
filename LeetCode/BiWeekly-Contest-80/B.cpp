class Solution {
public:
	vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long su) {
		int n = s.size(), m = p.size();
		vector<int> res(n);
		sort(p.begin(), p.end());
		for (int i = 0; i < n; ++i) {
			int x = s[i];
			long long y = ceil((double)su / x);
			if (y <= INT_MAX) {
				auto iter = lower_bound(p.begin(), p.end(), (int)y);
				res[i] = p.end() - iter;
			}
		}
		return res;
	}
};