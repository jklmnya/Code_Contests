#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int T;
int n;

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		if ((n - 1) % 2) {
			cout << 2 << ' ' << n - 3 << ' ' << 1 << endl;
		}
		else {
			int x = (n - 1) / 2;
			if (x % 2) {
				cout << x - 2 << ' ' << x + 2 << ' ' << 1 << endl;
			}
			else {
				cout << x - 1 << ' ' << x + 1 << ' ' << 1 << endl;
			}
		}
	}
	return 0;
}