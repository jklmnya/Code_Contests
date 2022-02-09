#include <iostream>
#include <algorithm>
#include <unordered_set>

/*
	特殊情况：若数组中所有元素相同，则k可以无限大
	一般情况：将数组排序，找出两两之间的差，求出所有差的最大公约数即为k
*/

using namespace std;

const int N = 45;

int t, n;
int ss[N];

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> ss[i];
		sort(ss + 1, ss + 1 + n);
		if (ss[1] == ss[n]) {
			cout << -1 << endl;
		}
		else {
			unordered_set<int> s;
			for (int i = 1; i <= n; ++i) {
				for (int j = i + 1; j <= n; ++j) {
					if (ss[j] - ss[i] > 0 && !s.count(ss[j] - ss[i]))
						s.emplace(ss[j] - ss[i]);
				}
			}
			int res = *s.begin();
			auto iter = s.begin();
			while (++iter != s.end())
				res = gcd(*iter, res);
			cout << res << endl;
		}
	}
	return 0;
}