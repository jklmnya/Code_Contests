#include <iostream>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    if (m <= n) {
        cout << n - m << '\n';
    } else {
        int res = 0;
        while (m != n) {
            if (m > n) {
                if (m % 2)
                    ++m;
                else
                    m >>= 1;
                ++res;
            } else {
                res += n - m;
                break;
            }
        }
        cout << res << '\n';
    }
    return 0;
}

作者：Dumhdurum
链接：https://www.acwing.com/activity/content/code/content/2569384/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。