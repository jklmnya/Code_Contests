#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>

/**
	分类讨论：
	1. x == y   -> x
	2. x > y	-> x + y
	3. x < y	-> n在(x, y)之间，通过画图可得 -> y - (y % x) / 2
**/
using namespace std;

int t;
long long x, y;

int main() {
	cin >> t;
	while (t--) {
		cin >> x >> y;
		if (x == y)
			cout << x << endl;
		else if (x > y)
			cout << x + y << endl;
		else
			cout << y - (y % x) / 2 << endl;
	}
	return 0;
}