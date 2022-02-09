#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 110;

int t, n;
LL h;
int ss[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%lld", &n, &h);
		for (int i = 0; i < n; ++i)
			scanf("%d", &ss[i]);
		LL left = 1ll, right = 1e18;
		while (left <= right) {
			LL mid = (left + right) >> 1;
			LL t = 0ll;
			for (int i = 0; i < n - 1; ++i) {
				if (ss[i] + mid < ss[i + 1])
					t += mid;
				else
					t += ss[i + 1] - ss[i];
			}
			t += mid;
			if (t < h) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		printf("%lld\n", left);
	}
	return 0;
}