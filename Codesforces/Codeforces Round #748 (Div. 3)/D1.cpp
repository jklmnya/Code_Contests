#include <iostream>
#include <algorithm>
#include <unordered_set>

/*
	���������������������Ԫ����ͬ����k�������޴�
	һ������������������ҳ�����֮��Ĳ������в�����Լ����Ϊk
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