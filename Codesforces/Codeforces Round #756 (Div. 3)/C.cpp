#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

/*
	结论，思维题
*/

const int N = 200010;

int T, n;

int s1[N], s2[2 * N], s3[2 * N];

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> s1[i];
		int s = 0, e = n - 1;
		int l1 = N, r1 = N + 1, l2 = N, r2 = N + 1;
		while (s < e) {
			if (s1[s] > s1[e]) {
				s2[r1] = s1[e];
				++r1;
				--e;
			}
			else {
				s2[l1] = s1[s];
				--l1;
				++s;
			}
		}
		s2[l1] = s1[s];
		--r1;
		s = l1, e = r1;
		while (l1 < r1) {
			if (s2[l1] > s2[r1]) {
				s3[r2] = s2[r1];
				++r2;
				--r1;
			}
			else {
				s3[l2] = s2[l1];
				--l2;
				++l1;
			}
		}
		--r2, ++l2;
		bool f1 = true, f2 = true;
		for (int i = 0, j = l2; i < n - 1; ++i, ++j) {
			if (s1[i] != s3[j]) {
				f1 = false;
				break;
			}
		}
		for (int i = 1, j = l2; i < n; ++i, ++j) {
			if (s1[i] != s3[j]) {
				f2 = false;
				break;
			}
		}
		if (f1 || f2) {
			while (s <= e) {
				cout << s2[s] << ' ';
				++s;
			}
			cout << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	return 0;
}