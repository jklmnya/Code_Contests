#include <iostream>
#include <algorithm>

/*
*   贪心：考虑Cat走到n-1后就可以抓到前面的老鼠
*/

using namespace std;

const int N = 400010;

int t, n, k;
int ss[N];

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= k; ++i)
            cin >> ss[i];
        int now = 0;
        int res = 0;
        sort(ss + 1, ss + 1 + k);
        for (int i = k; i > 0; --i) {
            now += (n - ss[i]);
            if (now >= n)
                break;
            ++res;
        }
        cout << res << endl;
    }
    return 0;
}