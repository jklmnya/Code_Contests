#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>

/*
	贪心：尽可能分成1 * 3
*/

using namespace std;

int t, n, m;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		if ((m * n) % 3)
			cout << (m * n) / 3 + 1 << endl;
		else
			cout << (m * n) / 3 << endl;
	}
	return 0;
}