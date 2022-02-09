#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
	核心 ： 判断结点x到根结点的距离是否大于到朋友所在节点的距离
*/

const int N = 200010, INF = 1000000;

int T, n, k, u, v, x;

unordered_set<int> fri;
unordered_map<int, int> vv;

int dfs(int node, int father, vector<vector<int>>& g) {
	if (fri.count(node))
		return 1;
	int ans = INF;
	for (int next : g[node]) {
		if (next != father)
			ans = min(ans, dfs(next, node, g));
	}
	vv.emplace(node, ans);
	return ans + 1;
}

bool dfs(int node, int father, int depth, vector<vector<int>>& g) {
	if (fri.count(node) || depth >= vv[node])
		return false;
	if (vv[node] >= INF)
		return true;
	for (int next : g[node]) {
		if (next != father && dfs(next, node, depth + 1, g))
			return true;
	}
	return false;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> n >> k;
		fri.clear();
		vv.clear();
		vector<vector<int>> g(n + 1);
		while (k--) {
			cin >> x;
			fri.emplace(x);
		}
		for (int i = 0; i < n - 1; ++i) {
			cin >> u >> v;
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		for (int next : g[1])
			dfs(next, 1, g);
		bool f = false;
		for (int next : g[1]) {
			if (dfs(next, 1, 1, g)) {
				f = true;
				break;
			}
		}
		if (f)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}