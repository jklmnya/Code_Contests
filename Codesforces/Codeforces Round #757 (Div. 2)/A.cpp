#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

/*
	ÅÅÐò + Ì°ÐÄ
*/

const int N = 110;

int T, n, l, r, k;

int ss[N];

int main() {
	cin >> T;
	while (T--) {
		cin >> n >> l >> r >> k;
		for (int i = 0; i < n; ++i)
			cin >> ss[i];
		sort(ss, ss + n);
		int res = 0;
		int s = 0;
		while (s < n && ss[s] < l)
			++s;
		while (s < n && ss[s] <= r && k >= ss[s]) {
			++res;
			k -= ss[s];
			++s;
		}
		cout << res << endl;
	}
	return 0;
}