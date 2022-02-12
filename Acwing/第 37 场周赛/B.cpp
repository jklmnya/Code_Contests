#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200010;
int n;
int ss[N];

typedef long long LL;

LL p2[N];

int main() {
    cin >> n;
    for (int i = 0;i<n;++i)
        cin >> ss[i];
    if (n == 1) {
        cout << 0 << '\n';
    }
    else {
        for (int i = 1;i<=n;++i)
            p2[i] = p2[i - 1] + ss[n - i];
        LL res = 0ll, now = 0ll;
        for (int i = 0;i<n;++i) {
            now += ss[i];
            auto iter = lower_bound(p2 + 1, p2 + 1 + n, now);
            int sp = iter - p2;
            if (i + sp < n && *iter == now)
                res = now;
        }
        cout << res << '\n';
    }

    return 0;   
}

作者：Dumhdurum
链接：https://www.acwing.com/activity/content/code/content/2510275/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。