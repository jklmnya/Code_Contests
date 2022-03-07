class Solution {
public:
	vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
		vector<set<int>> vv(n);
		vector<vector<int>> g(n);
		vector<int> ind(n);
		for (auto& edge : edges) {
			int s = edge[0], e = edge[1];
			g[s].push_back(e);
			ind[e]++;
		}
		queue<int> q;
		for (int i = 0; i < n; ++i) {
			if (!ind[i])
				q.push(i);
			vv[i].emplace(i);
		}
		while (q.size()) {
			int node = q.front();
			q.pop();
			for (int next : g[node]) {
				if (--ind[next] == 0)
					q.push(next);
				for (auto rt : vv[node])
					vv[next].emplace(rt);
			}
		}
		vector<vector<int>> res(n);
		for (int i = 0; i < n; ++i) {
			for (int node : vv[i]) {
				if (node != i)
					res[i].push_back(node);
			}
		}
		return res;
	}
};