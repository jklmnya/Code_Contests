#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>

/*
	diff = a1 + a3 - 2 * a2
	每次操作都可以让diff加3或者减3
*/

using namespace std;

int t, a, b, c;

int main() {
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		int diff = abs(a + c - 2 * b);
		if (diff % 3)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}
}