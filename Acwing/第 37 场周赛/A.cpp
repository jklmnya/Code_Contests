#include <iostream>

using namespace std;

int n, a, b;

int main() {
    cin >> n >> a >> b;
    bool f = false;
    for (int x = 0;x<=n;++x) {
        if ((n - a * x) % b == 0 && (n - a * x) >= 0) {
            cout << "YES" << '\n';
            cout << x << ' ' << (n - a * x) / b << '\n';
            f = true;
            break;
        }
    }
    if (!f)
        cout << "NO" << '\n';
    return 0;   
}

作者：Dumhdurum
链接：https://www.acwing.com/activity/content/code/content/2508735/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。