#include <iostream>
#include <string>
#include <cmath>

/*
	符合条件的数字以00 / 25 / 50 / 75结尾
	分类讨论 + 贪心
*/

using namespace std;

int t;
string ss;

int main() {
	cin >> t;
	while (t--) {
		cin >> ss;
		int res = 1000;
		int now = 0;
		int idx = ss.size();
		while (--idx >= 0 && ss[idx] != '5')
			++now;
		while (--idx >= 0 && !(ss[idx] == '2' || ss[idx] == '7'))
			++now;
		if (idx >= 0)
			res = min(res, now);
		idx = ss.size();
		now = 0;
		while (--idx >= 0 && ss[idx] != '0')
			++now;
		while (--idx >= 0 && !(ss[idx] == '0' || ss[idx] == '5'))
			++now;
		if (idx >= 0)
			res = min(res, now);
		cout << res << endl;
	}
	return 0;
}