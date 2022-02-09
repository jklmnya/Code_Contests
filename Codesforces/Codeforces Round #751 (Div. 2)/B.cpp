#include <iostream>
#include <cstring>

using namespace std;

const int N = 2005;

int t, n, q, x, k, num;

int ans[N][N];
int cnt[2][N];

int main() {
	cin >> t;
	while (--t >= 0) {
		cin >> n;
		int j = 0;
		memset(cnt[0], 0, sizeof cnt[0]);
		for (int i = 1; i <= n; ++i) {
			cin >> num;
			ans[0][i] = num;
			++cnt[0][num];
		}
		while (true) {
			++j;
			memset(cnt[j % 2], 0, sizeof cnt[j % 2]);
			for (int i = 1; i <= n; ++i) {
				ans[j][i] = cnt[(j - 1) % 2][ans[j - 1][i]];
				++cnt[j % 2][ans[j][i]];
			}
			bool f = true;
			for (int i = 1; i <= n; ++i) {
				if (cnt[j % 2][i] != cnt[(j - 1) % 2][i]) {
					f = false;
					break;
				}	
			}
			if (f)
				break;
		}
		cin >> q;
		while (--q >= 0) {
			cin >> x >> k;
			if (k >= j)
				cout << ans[j][x] << endl;
			else
				cout << ans[k][x] << endl;
		}
		memset(ans, 0, sizeof ans);
	}
	return 0;
}