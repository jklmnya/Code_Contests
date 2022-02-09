#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

/*
* f[i][j] —— 表示前i个数，通过合法的运算得到结果为j末尾最小的数字
* 动态转移方程：选第i个数，不选第i个数
* f[i][j] = min(f[i - 1][j], ss[i]) f[i - 1][j ^ ss[i]] < ss[i]
*/

using namespace std;

const int N = 100005, M = 512;

int n;
int ss[N];
int f[2][M];

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> ss[i];
	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < M; ++j) {
			f[i % 2][j] = f[(i - 1) % 2][j];
			if (f[(i - 1) % 2][j ^ ss[i]] < ss[i])
				f[i % 2][j] = min(f[i % 2][j], ss[i]);
		}
	}
	int cnt = 0;
	for (int i = 0; i < M; ++i) {
		if (f[n % 2][i] < M)
			++cnt;
	}
	cout << cnt << endl;
	for (int i = 0; i < M; ++i) {
		if (f[n % 2][i] < M)
			cout << i << ' ';
	}
	cout << endl;
	return 0;
}