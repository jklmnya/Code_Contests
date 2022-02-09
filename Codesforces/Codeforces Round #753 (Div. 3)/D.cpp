#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

/*
	贪心，将所有的B放到左边，R放到右边，看是否合法
*/

using namespace std;

const int N = 200010;

int t, n;
int ss[N];
string str;

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> ss[i];
		cin >> str;
		vector<int> r, b;
		for (int i = 0; i < n; ++i) {
			if (str[i] == 'R')
				r.emplace_back(ss[i]);
			else
				b.emplace_back(ss[i]);
		}
		sort(r.begin(), r.end());
		sort(b.begin(), b.end());
		bool f = true;
		for (int i = 0; i < b.size(); ++i) {
			if (b[i] < i + 1) {
				f = false;
				break;
			}
		}
		if (f) {
			for (int i = 0; i < r.size(); ++i) {
				if (r[i] > (int)b.size() + 1 + i) {
					f = false;
					break;
				}
			}
		}
		if (f)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}