#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

/*
*    枚举每两个元素的之差，之后再枚举差值的因数
*	 答案必定在差值的因数中
*/

using namespace std;

const int N = 105;

int t, n;
int ss[N];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		unordered_map<int, int> vv;
		for (int i = 1; i <= n; ++i) {
			cin >> ss[i];
			++vv[ss[i]];
		}
		bool f = true;
		for (auto& [k, v] : vv) {
			if (v >= n / 2) {
				cout << -1 << endl;
				f = false;
				break;
			}
		}
		if (f) {
			int res = 1;
			unordered_set<int> s;
			for (int i = 1; i <= n; ++i) {
				for (int j = i + 1; j <= n; ++j) {
					int diff = abs(ss[i] - ss[j]);
					int x = ss[i];
					if (!s.count(diff)) {
						s.emplace(diff);
						for (int k = 1; k * k <= diff; ++k) {
							if (diff % k)
								continue;
							if (k > res) {
								int cnt = 0;
								for (int m = 1; m <= n; ++m) {
									if (abs(x - ss[m]) % k == 0)
										++cnt;
								}
								if (cnt >= (n + 1) / 2)
									res = k;
							}
							if (diff / k > res) {
								int cnt = 0;
								for (int m = 1; m <= n; ++m) {
									if (abs(x - ss[m]) % (diff / k) == 0)
										++cnt;
								}
								if (cnt >= (n + 1) / 2)
									res = diff / k;
							}
						}
					}
				}
			}
			cout << res << endl;
		}
	}
	return 0;
}