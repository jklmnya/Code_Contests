#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>

using namespace std;

/*
*	根据题意列不等式即可
*	res <= (a + b) / 4
*	res <= a
*	res <= b
*/

int T;
int a, b;

int main() {
	cin >> T;
	while (T--) {
		cin >> a >> b;
		cout << min((a + b) / 4, min(a, b)) << endl;
	}
	return 0;
}