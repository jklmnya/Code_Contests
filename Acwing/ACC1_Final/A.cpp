#include <iostream>

using namespace std;

int a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;
    if (d > b) {
        swap(b, d);
        swap(a, c);
    }
    if (b > d) {
        int f1 = (b - d) % c;
        if (f1 == 0) {
            cout << b << '\n';
        } else {
            if (a % 2 == 0 && c % 2 == 0 && f1 % 2) {
                cout << -1 << '\n';
            } else {
                int res = 0;
                for (int k = 1;k<=100;++k) {
                    if (a * k % c == c - f1) {
                        res = a * k;
                        break;
                    }
                }
                if (res == 0)
                    cout << -1 << '\n';
                else
                    cout << res + b << '\n';
            }
        }
    } else {
        cout << b << '\n';
    }
    return 0;
}

作者：同济大学_第一届ACC决赛
链接：https://www.acwing.com/activity/content/code/content/3030763/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。