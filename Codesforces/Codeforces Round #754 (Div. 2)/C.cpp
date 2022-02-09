#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

/*
	����̸��

	Case 1: substring�к���2��a -> "aa", "aba", "aca"
	Case 2: substring�к���3��a -> "abbacca", "accabba"
	�������ж���3��a�����

*/


using namespace std;

int t, n;
string ss;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> ss;
		int res = 1e9;
		for (int i = 0; i < n; ++i) {
			vector<int> v(3);
			++v[ss[i] - 'a'];
			for (int j = i + 1; j < min(n, i + 7); ++j) {
				++v[ss[j] - 'a'];
				if (v[0] > v[1] && v[0] > v[2])
					res = min(res, j - i + 1);
			}
		}
		if (res == 1e9)
			cout << -1 << endl;
		else
			cout << res << endl;
	}
	return 0;
}