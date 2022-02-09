#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100010;

int T;
int n;
int ss[N];

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> ss[i];
		vector<bool> st(n + 1);
		vector<int> vv;
		for (int i = 0; i < n; ++i) {
			if (ss[i] <= n && !st[ss[i]]) {
				st[ss[i]] = true;
			}
			else {
				vv.emplace_back(ss[i]);
			}
		}
		sort(vv.begin(), vv.end());
		int s = -1;
		bool ok = true;
		for (int i = 1; i <= n; ++i) {
			if (!st[i]) {
				if (++s < vv.size()) {
					int v;
					if (vv[s] % 2)
						v = vv[s] / 2;
					else
						v = vv[s] / 2 - 1;
					if (v < i) {
						ok = false;
						break;
					}
				}
			}
		}
		if (ok)
			cout << vv.size() << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}