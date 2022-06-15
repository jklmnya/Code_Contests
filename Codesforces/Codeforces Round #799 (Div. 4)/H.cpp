#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <cstring>

using namespace std;

const int N = 200005;
int T, n, num;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_map<int, vector<int>> vv;

	cin >> T;
	while (T--) {
		cin >> n;
		vv.clear();
		int a = -1, l = 0, r = 0, cnt = 1;
		for (int i = 0; i < n; ++i) {
			cin >> num;
			if (i == 0)
				a = num;
			vv[num].push_back(i);
		}
		
		for (auto& [k, v] : vv) {
			if (v.size()) {
				int now = 1, nl = v[0];
				for (int i = 1; i < v.size(); ++i) {
					int sub = v[i] - v[i - 1] - 1;
					now = now + 1 - sub;

					// cout << now << '\n';

					if (now <= 0) {
						nl = v[i];
						now = 1;
					}
					else {
						if (now > cnt) {
							cnt = now;
							a = k;
							l = nl;
							r = v[i];

							// cout << l << ' ' << r << '\n';
						}
					}
				}
			}
		}

		cout << a << ' ' << l + 1 << ' ' << r + 1 << '\n';
		
	}
	

	return 0;
}