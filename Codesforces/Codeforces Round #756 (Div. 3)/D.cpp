#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

/*
	dist[i] ���� ��ʾ���i�����ڵ�ľ���
	����p[i]�����p[i]�ĸ��ڵ�f[i]��distû�б����¹���˵�����Ϸ� -> res = -1
	����dist[p[i]] = dist[p[i - 1]] + 1
*/

const int N = 200010;

int T, n, root;

int p[N], b[N], res[N];

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> b[i];
			if (i == b[i])
				root = i;
		}
		for (int i = 1; i <= n; ++i)
			cin >> p[i];
		if (p[1] != root) {
			cout << -1 << endl;
		}
		else {
			bool f = true;
			vector<int> dist(n + 1, 0);
			for (int i = 2; i <= n; ++i) {
				int now = p[i];
				int father = b[now];
				if (father != root && !dist[father]) {
					f = false;
					break;
				}
				dist[now] = dist[p[i - 1]] + 1;
				res[now] = dist[now] - dist[b[now]];
			}
			res[root] = 0;
			if (f) {
				for (int i = 1; i <= n; ++i)
					cout << res[i] << ' ';
				cout << endl;
			}
			else {
				cout << -1 << endl;
			}
		}

	}
	return 0;
}