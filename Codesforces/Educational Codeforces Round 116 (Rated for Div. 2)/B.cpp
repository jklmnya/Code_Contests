#include <iostream>
#include <cmath>

/*
	cnt : 当前时间能够传输的计算机数量，若cnt > k(传输线的数量），则1小时只能给k台电脑传输数据
	cnt * 2 -> 下一时刻获得数据的计算机数量，若cnt * 2 > n，则需退出循环
*/

using namespace std;

typedef long long LL;

int t;
LL n, k;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> k;
		LL res = 0ll;
		LL now = 0ll, cnt = 1ll;
		while (true) {
			if (cnt <= k && cnt * 2 <= n) {
				cnt *= 2;
				++now;
			}
			else {
				break;
			}
		}
		res += now;
		res += ceil(double(n - cnt) / min(cnt, k));
		cout << res << endl;
	}
	return 0;
}