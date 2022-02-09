#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

/*
	bfsÄ£Äâ¼´¿É
*/

using namespace std;

int t, n, k, x, y;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		vector<vector<int>> g(n + 1);
		vector<int> cnt(n + 1);
		for (int i = 0; i < n - 1; ++i) {
			scanf("%d%d", &x, &y);
			++cnt[x], ++cnt[y];
			g[x].emplace_back(y);
			g[y].emplace_back(x);
		}
		if (k >= (ceil)(double(n) / 2)) {
			printf("%d\n", 0);
		}
		else {
			int res = n;
			queue<int> q;
			for (int i = 1; i <= n; ++i) {
				if (cnt[i] == 1)
					q.emplace(i);
			}
			int ss = q.size() + 1;
			while (res && k && q.size()) {
				while (--ss) {
					int node = q.front();
					q.pop();
					--res;
					for (int next : g[node]) {
						if (--cnt[next] == 1)
							q.emplace(next);
					}
				}
				ss = q.size() + 1;
				--k;
			}
			printf("%d\n", res);
		}
	}
	return 0;
}