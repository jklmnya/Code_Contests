#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

const int N = 200005;
int T, n, q;
int ss[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> n >> q;
		for (int i = 0; i < n; ++i)
			cin >> ss[i];

		int s = 0, e = 0;
		int now = 0;
		int res = 0x3f3f3f3f;
		while (e < n) {
			now += ss[e];

			// cout << e << ' ' << now << '\n';

			if (now == q)
				res = min(res, s + n - e - 1);
			while (now > q) {
				now -= ss[s];
				++s;
			}
			++e;
		}
		if (res == 0x3f3f3f3f)
			cout << -1 << '\n';
		else
			cout << res << '\n';
	}
	
	
	return 0;
}