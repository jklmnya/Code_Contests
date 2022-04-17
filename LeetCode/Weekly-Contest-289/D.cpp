class Solution {
public:
	int longestPath(vector<int>& parent, string s) {
		int n = parent.size();
		int dp[n][2];
		memset(dp, 0, sizeof dp);
		vector<int> f(n);
		for (int p : parent) {
			if (p != -1)
				f[p]++;
		}
		int res = 1;
		queue<int> q;
		for (int i = 0; i < n; ++i) {
			if (f[i] == 0)
				q.emplace(i);
		}
		while (q.size()) {
			int node = q.front();
			q.pop();
			res = max(res, dp[node][0] + dp[node][1] + 1);
			if (parent[node] != -1) {
				int v;
				if (s[parent[node]] != s[node])
					v = dp[node][0] + 1;
				else
					v = 0;
				if (v > dp[parent[node]][0]) {
					dp[parent[node]][1] = dp[parent[node]][0];
					dp[parent[node]][0] = v;
				}
				else if (v > dp[parent[node]][1]) {
					dp[parent[node]][1] = v;
				}
				if (--f[parent[node]] == 0)
					q.emplace(parent[node]);
			}
		}
		return res;
	}
};