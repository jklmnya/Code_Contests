#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>

/*
* 数组长度为偶数：交换相邻两个数，添负号即可
* 数组长度为奇数：对前三个数做特殊处理，其余偶数个数两两交换即可
*/

using namespace std;

const int N = 100010;

int t, n;
int ss[N];
int ans[N];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> ss[i];
		if (n % 2 == 0) {
			for (int i = 1; i <= n; i += 2) {
				ans[i] = -ss[i + 1];
				ans[i + 1] = ss[i];
			}
		}
		else {
			if (ss[1] + ss[2] != 0) {
				ans[1] = ans[2] = -ss[3];
				ans[3] = ss[1] + ss[2];
			}
			else if (ss[1] + ss[3] != 0) {
				ans[1] = ans[3] = -ss[2];
				ans[2] = ss[1] + ss[3];
			}
			else {
				ans[2] = ans[3] = -ss[1];
				ans[1] = ss[2] + ss[3];
			}
			for (int i = 4; i <= n; i += 2) {
				if (ss[i] == ss[i + 1]) {
					ans[i] = -1;
					ans[i + 1] = 1;
				}
				else {
					ans[i] = -ss[i + 1];
					ans[i + 1] = ss[i];
				}
			}
		}
		for (int i = 1; i <= n; ++i)
			cout << ans[i] << ' ';
		cout << endl;
	}
	return 0;
}