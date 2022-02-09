
#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

/*
	分类讨论：
	1. n是偶数 -> res = 0;
	2. n是奇数 -> n的最高位为偶数,反转整个数字 -> res = 1
			  -> n中每一位都为奇数 -> res = -1
			  -> n中最高位为奇数，后面某位为偶数 -> res = 2
*/

int T, n;
int ss[100];

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		if (n % 2 == 0) {
			cout << 0 << endl;
		}
		else {
			int cnt = -1;
			while (n) {
				ss[++cnt] = n % 10;
				n /= 10;
			}
			if (ss[cnt] % 2 == 0) {
				cout << 1 << endl;
			}
			else {
				bool f = false;
				for (int i = 0; i <= cnt; ++i) {
					if (ss[i] % 2 == 0) {
						f = true;
						break;
					}
				}
				if (f)
					cout << 2 << endl;
				else
					cout << -1 << endl;
			}
		}
	}
	return 0;
}