bool st[50005];

class Solution {
public:
	int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
		int n = static_cast<int>(scores.size());
		vector<vector<int>> g(n);
		for (auto& e : edges) {
			int s1 = e[0], s2 = e[1];
			g[s1].push_back(s2);
			g[s2].push_back(s1);
		}
		for (int i = 0; i < n; ++i) {
			sort(g[i].begin(), g[i].end(), [&scores](int x, int y) {
				return scores[x] > scores[y];
				});
		}
		int res = -1;
		for (auto& edge : edges) {
			int s1 = edge[0], s2 = edge[1];
			int ans = scores[s1] + scores[s2];
			int f = 2;
			int s3 = -1, s4 = -1;
			st[s1] = st[s2] = true;
			for (int next : g[s1]) {
				if (!st[next]) {
					ans += scores[next];
					s3 = next;
					st[s3] = true;
					++f;
					break;
				}
			}
			for (int next : g[s2]) {
				if (!st[next]) {
					ans += scores[next];
					s4 = next;
					st[s4] = true;
					++f;
					break;
				}
			}
			if (f == 4)
				res = max(res, ans);
			ans = scores[s1] + scores[s2];
			f = 2;
			if (s3 >= 0)
				st[s3] = false;
			if (s4 >= 0)
				st[s4] = false;
			for (int next : g[s2]) {
				if (!st[next]) {
					ans += scores[next];
					s3 = next;
					st[s3] = true;
					++f;
					break;
				}
			}
			for (int next : g[s1]) {
				if (!st[next]) {
					ans += scores[next];
					s4 = next;
					st[s4] = true;
					++f;
					break;
				}
			}
			if (f == 4)
				res = max(res, ans);
			if (s3 >= 0)
				st[s3] = false;
			if (s4 >= 0)
				st[s4] = false;
			st[s1] = st[s2] = false;
		}
		return res;
	}
};