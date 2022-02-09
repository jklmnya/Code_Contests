#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

/*
	ÅÅÐò + Ì°ÐÄ
*/

using namespace std;

const int N = 110;

int t, n;
int a[N], b[N];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		for (int i = 0; i < n; ++i)
			cin >> b[i];
		sort(a, a + n);
		sort(b, b + n);
		bool f = true;
		for (int i = 0; i < n; ++i) {
			if (b[i] < a[i] || b[i] - a[i] > 1) {
				f = false;
				break;
			}
		}
		if (f)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}