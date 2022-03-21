#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;

const int N = 5010;
int n, m, k;
int ss[N];
LL f[N];
LL dp[N][N];

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		cin >> ss[i];
	for (int i = 1; i <= n; ++i)
		f[i] = f[i - 1] + ss[i - 1];
	LL res = 0ll;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			dp[i][j] = dp[i - 1][j];
			if (i - m >= 0)
				dp[i][j] = max(dp[i][j], dp[i - m][j - 1] + f[i] - f[i - m]);
		}
	}
	cout << dp[n][k] << '\n';
	return 0;
}
