#define  _CRT_SECURE_NO_WARNINGS

/*
	枚举a，b，c为奇，偶数共8种情况
*/

#include <iostream>

using namespace std;

const int N = 100010;

int t, a, b, c;

int main() {
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		bool f3 = c % 2 == 0, f2 = b % 2 == 0, f1 = a % 2 == 0;
		if (f3) {
			if (f1)
				cout << 0 << endl;
			else
				cout << 1 << endl;
		}
		else {
			if (f1)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
	}
	return 0;
}