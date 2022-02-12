#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m;
int b[N], g[N];

int main() {
    cin >> n;
    for (int i = 1;i<=n;++i)
        cin >> b[i];
    cin >> m;
    for (int i = 1;i<=m;++i)
        cin >> g[i];
    sort(b + 1, b + 1 + n);
    sort(g + 1, g + 1 + m);
    int f[n + 1][m + 1];
    memset(f, 0, sizeof f);
    for (int i = 1;i<=n;++i) {
        for (int j = 1;j<=m;++j) {
            if (abs(b[i] - g[j]) <= 1)
                f[i][j] = f[i - 1][j - 1] + 1;
            else
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            // cout << f[i][j] << ' ';
        }
        // cout << '\n';
    }
    cout << f[n][m] << '\n';
    return 0;
}

作者：Dumhdurum
链接：https://www.acwing.com/activity/content/code/content/2511418/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。