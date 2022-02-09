#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <climits>
#include <cmath>

using namespace std;

int t, n;
string ss;

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> ss;
		int ans = INT_MAX;
		for (int i = 0; i < 26; ++i) {
			char de = (char)(i + 'a');
			bool f = true;
			int cnt = 0;
			int s = 0, e = n - 1;
			while (s <= e) {
				if (ss[s] != ss[e]) {
					if (ss[s] == de) {
						++cnt;
						++s;
					}
					else if (ss[e] == de) {
						++cnt;
						--e;
					}
					else {
						f = false;
						break;
					}
				}
				else {
					++s, --e;
				}
			}
			if (f)
				ans = min(ans, cnt);
		}
		if (ans == INT_MAX)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}
	return 0;
}