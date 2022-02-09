#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

/*
* ��ÿһ���ߺ� (maxup + maxdown >= n || maxleft + maxright >= m), ��ʱ���Ϸ�������ѭ��
* ����Ϊ ( maxup + 1, maxleft + 1)
*/

using namespace std;

int t, n, m;
string ss;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cin >> ss;
		int mu = 0, md = 0, ml = 0, mr = 0;	// ���ϣ��£������ߵ������
		int u = 0, d = 0, l = 0, r = 0;		// ��ǰ�Ĳ���
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