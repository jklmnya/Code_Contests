#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
#include <functional>
#include <cstring>

using namespace std;

const int N = 200005;
int T, n, k;
int ss[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 0; i < n; ++i)
			cin >> ss[i];
		int s = 0, res = 0;
		while (s < n) {
			int e = s + 1;
			while (e < n && 2 * ss[e] > ss[e - 1])
				++e;
			res += max(0, e - s - k);
			s = e;
		}
		cout << res << '\n';
	}
	

	return 0;
}