#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010;

int t, n;
int ss[N];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> ss[i];
		if (n % 2 == 0) {
			cout << "YES" << endl;
		}
		else {
			bool f = false;
			for (int i = 1; i < n; ++i) {
				if (ss[i] >= ss[i + 1]) {
					f = true;
					break;
				}
			}
			if (f)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}