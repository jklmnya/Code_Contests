#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200010;

int t, n;
int ss[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &ss[i]);
		int minV = *min_element(ss, ss + n);
		int k = n / 2;
		int idx = 0;
		while (k) {
			if (ss[idx] != minV) {
				printf("%d %d\n", ss[idx], minV);
				--k;
			}
			++idx;
		}
	}
	return 0;
}