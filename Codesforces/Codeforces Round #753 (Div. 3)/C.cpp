#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200010;

int t, n;
int ss[N];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> ss[i];
		sort(ss, ss + n);
		int res = -0x3f3f3f3f, sum = 0;
		for (int i = 0; i < n; ++i) {
			ss[i] -= sum;
			res = max(res, ss[i]);
			sum += ss[i];
		}
		cout << res << endl;
	}
	return 0;
}