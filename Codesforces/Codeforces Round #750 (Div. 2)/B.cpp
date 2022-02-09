#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

using namespace std;

const int N = 65;

int t, n;
int ss;

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		long long x = 0, y = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> ss;
			if (ss == 1)
				++y;
			else if (ss == 0)
				++x;
		}
		cout << y * (long long)pow(2, x) << endl;
	}
	return 0;
}