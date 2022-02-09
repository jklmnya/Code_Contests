#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>

/*
	分析：第i位上的数字nums[i]可以在其位于下标为1，2，3，4...i时被删除
	那么如果nums[i]同时是2, 3, 4, ..., i + 1的倍数，那么其不能被删除

	算法：从前往后遍历，递推求出2，3，4，...， i + 1的最小公倍数lcm，判断
	lcm % nums[i] == 0
*/

using namespace std;

typedef long long LL;

const int N = 100010;

int t, n;
LL ss[N];

LL gcd(LL x, LL y) {
	return y ? gcd(y, x % y) : x;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> ss[i];
		bool f = true;
		LL lcm = 1ll;
		for (LL i = 1; i <= n; ++i) {
			lcm = lcm * (i + 1) / gcd(lcm, i + 1);
			if (ss[i] % lcm == 0) {
				f = false;
				break;
			}
		}
		if (f)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}