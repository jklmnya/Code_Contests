#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

const int N = 200010, M = 30;

int ss[N];
int cnt[M];

int t, n;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &ss[i]);
		for (int i = 0; i < n; ++i) {
			int x = ss[i];
			for (int k = 0; k < M; ++k) {
				if ((x >> k) & 1)
					++cnt[k];
			}
		}
		for (int i = 1; i <= n; ++i) {
			bool f = true;
			for (int j = 0; j < M; ++j) {
				if (cnt[j] % i != 0) {
					f = false;
					break;
				}
			}
			if (f)
				printf("%d ", i);
		}
		printf("\n");
		memset(cnt, 0, sizeof cnt);
	}
	return 0;
}