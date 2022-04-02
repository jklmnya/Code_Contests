#include <iostream>
#include <climits>

using namespace std;

typedef long long LL;

const int N = 2005;

int n, m, x, a, b;
LL f1[N], f2[N];
LL m1[N], m2[N];

int main() {
    cin >> n >> m;
    for (int i = 1;i<=n;++i) {
        cin >> a;
        f1[i] = f1[i - 1] + a;
    }
    for (int i = 1;i<=m;++i) {
        cin >> b;
        f2[i] = f2[i - 1] + b;
    }
    cin >> x;
    for (int len = 1;len<=n;++len) {
        m1[len] = LLONG_MAX;
        for (int left = 1;(left + len - 1)<=n;++left)
            m1[len] = min(m1[len], f1[left + len - 1] - f1[left - 1]);
    }
    for (int len = 1;len<=m;++len) {
        m2[len] = LLONG_MAX;
        for (int left = 1;(left + len - 1)<=m;++left)
            m2[len] = min(m2[len], f2[left + len - 1] - f2[left - 1]);
    }
    int res = 0;
    for (int len1 = 1;len1<=n;++len1) {
        for (int len2 = 1;len2<=m;++len2) {
            if (m1[len1] * m2[len2] <= x)
                res = max(res, len1 * len2);
        }
    }
    cout << res << '\n';
	return 0;
}