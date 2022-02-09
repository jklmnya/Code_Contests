#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 110;

int t, n;
int ss[N];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> ss[i];
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			if (i + res < ss[i])
				res += ss[i] - i - res;
		}
		cout << res << endl;
	}
	return 0;
}