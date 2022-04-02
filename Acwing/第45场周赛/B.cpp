#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 500010, M = N << 1;
int n, k;
int ss[N];
int f[M];

int main() {
    cin >> n >> k;
    for (int i = 1;i<=n;++i)
        scanf("%d", &ss[i]);
    int left = 0, right = -1;
    int s = 1, e = 1;
    int cnt = 0;
    while (e <= n) {
        if (f[ss[e]] == 0)
            ++cnt;
        ++f[ss[e]];
        if (cnt > k) {
            while (s <= e) {
                if (--f[ss[s]] == 0) {
                    --cnt;
                    ++s;
                    break;
                }
                ++s;
            }
        }
        if (e - s > right - left) {
            right = e;
            left = s;
        }
        ++e;
    }
    printf("%d %d\n", left, right);
	return 0;
}