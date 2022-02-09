#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

typedef long long LL;

int T;
LL k, x;

int main() {
	cin >> T;
	while (T--) {
		cin >> k >> x;
		LL l = 1ll, r = 2 * k - 1;
		LL hh = (1 + k) * k / 2;
		LL sum = hh + (k - 1) * k / 2;
		if (x >= sum) {
			cout << 2 * k - 1 << endl;
		}
		else {
			while (l <= r) {
				LL mid = (l + r) >> 1;
				LL now;
				if (mid <= k) {
					now = (mid * (1 + mid)) / 2;
				}
				else {
					LL t = mid - k;
					now = hh + (k - 1 + k - t) * t / 2;
				}
				if (now > x) {
					r = mid - 1;
				}
				else if (now < x) {
					l = mid + 1;
				}
				else {
					l = mid;
					break;
				}
			}
			cout << l << endl;
		}


	}
	return 0;
}