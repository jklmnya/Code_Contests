#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

/*
* 看每一步走后 (maxup + maxdown >= n || maxleft + maxright >= m), 此时不合法，跳出循环
* 最后答案为 ( maxup + 1, maxleft + 1)
*/

using namespace std;

int t, n, m;
string ss;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cin >> ss;
		int mu = 0, md = 0, ml = 0, mr = 0;	// 向上，下，左，右走的最大步数
		int u = 0, d = 0, l = 0, r = 0;		// 当前的步数
		for (auto op : ss) {
			if (op == 'U') {
				++u;
				--d;
				if (max(mu, u) + md >= n)
					break;
				mu = max(mu, u);
			}
			else if (op == 'D') {
				++d;
				--u;
				if (max(md, d) + mu >= n)
					break;
				md = max(md, d);
			}
			else if (op == 'L') {
				++l;
				--r;
				if (max(ml, l) + mr >= m)
					break;
				ml = max(ml, l);
			}
			else {
				++r;
				--l;
				if (max(mr, r) + ml >= m)
					break;
				mr = max(mr, r);
			}
		}
		cout << mu + 1 << ' ' << ml + 1 << endl;
	}
	return 0;
}