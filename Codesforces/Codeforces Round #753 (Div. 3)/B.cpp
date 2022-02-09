#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

typedef long long LL;

int t;
LL a, b;

int main() {
	cin >> t;
	while (t--) {
		cin >> a >> b;
		if (a % 2 == 0) {
			if (b % 4 == 0) {
				cout << a << endl;
			}
			else if (b % 4 == 1) {
				cout << a - b << endl;
			}
			else if (b % 4 == 2) {
				cout << a + 1 << endl;
			}
			else {
				cout << a + b + 1 << endl;
			}
		}
		else {
			if (b % 4 == 0) {
				cout << a << endl;
			}
			else if (b % 4 == 1) {
				cout << a + b << endl;
			}
			else if (b % 4 == 2) {
				cout << a - 1 << endl;
			}
			else {
				cout << a - b - 1 << endl;
			}
		}
	}
	return 0;
}