#include <iostream>
#include <cmath>

using namespace std;

const int N = 200;
int T, n, k;

int ss[N];

int main() {
	cin >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 0; i < k; ++i)
			cin >> ss[i];
		int res = max(ss[0], n - ss[k - 1] + 1);
		for (int i = 0; i < k - 1; ++i)
			res = max(res, (ss[i] + ss[i + 1]) / 2 - ss[i] + 1);
		cout << res << '\n';
	}
	return 0;
}