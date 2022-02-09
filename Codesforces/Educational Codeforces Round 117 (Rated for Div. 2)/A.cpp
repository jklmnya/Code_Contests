#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int T, a, b;

int main() {
	cin >> T;
	while (T--) {
		cin >> a >> b;
		int sum = a + b;
		if (sum % 2) {
			cout << -1 << ' ' << -1 << endl;
		}
		else {
			if (a >= b) {
				cout << (sum / 2) - b << ' ' << b << endl;
			}
			else {
				cout << a << ' ' << (sum / 2) - a << endl;
			}
		}
	}
	return 0;
}