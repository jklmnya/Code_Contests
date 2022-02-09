#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1000005;

int t, n, m;

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

vector<string> g(N);
vector<int> xx(4), yy(4);

PII getL() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (g[i][j] == 'L') {
				return { i, j };
			}
		}
	}
	return { 0, 0 };
}

int main() {
	cin >> t;
	while (t--) {
		std::ios::sync_with_stdio(false);
		cin.tie(0);
		cin >> n >> m;
		PII pii;
		bool ok = false;
		for (int i = 0; i < n; ++i) {
			cin >> g[i];
			if (!ok) {
				for (int j = 0; j < m; ++j) {
					if (g[i][j] == 'L') {
						ok = true;
						pii = { i, j };
						break;
					}
				}
			}
		}
		queue<PII> q;
		for (int i = 0; i < 4; ++i) {
			int tx = pii.first + dx[i], ty = pii.second + dy[i];
			if (tx < 0 || tx >= n || ty < 0 || ty >= m || g[tx][ty] == '#')
				continue;
			q.emplace(tx, ty);
		}
		while (q.size()) {
			auto [x, y] = q.front();
			q.pop();
			int cnt = 0;
			for (int i = 0; i < 4; ++i) {
				int tx = x + dx[i], ty = y + dy[i];
				if (tx < 0 || tx >= n || ty < 0 || ty >= m || g[tx][ty] != '.')
					continue;
				xx[cnt] = tx, yy[cnt] = ty;
				++cnt;
			}
			if (cnt <= 1) {
				g[x][y] = '+';
				for (int i = 0; i < cnt; ++i)
					q.emplace(xx[i], yy[i]);
			}
		}
		for (int i = 0; i < n; ++i)
			cout << g[i] << "\n";
	}
	return 0;
}