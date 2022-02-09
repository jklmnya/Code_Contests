#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

typedef long long LL;

const int N = 200010, MOD = 1e9 + 7;

int T, n, m, l, r;
LL x;

int main() {
	cin >> T;
	while (T--) {
		cin >> n >> m;
		LL res = 0ll;
		while (m--) {
			cin >> l >> r >> x;
			res |= x;
		}
		for (int i = 0; i < n - 1; ++i)
			res = (res * 2) % MOD;
		cout << res % MOD << endl;
	}
	return 0;
}