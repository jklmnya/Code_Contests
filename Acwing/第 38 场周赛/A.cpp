#include <iostream>

using namespace std;

int n, x, y;

int main() {
    cin >> n;
    int left = 0, right = 0;
    for (int i = 0;i<n;++i) {
        cin >> x >> y;
        if (x < 0)
            ++left;
        else
            ++right;
    }
    if (left == n || left == n - 1 || right == n || right == n - 1)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
    return 0;
}

作者：Dumhdurum
链接：https://www.acwing.com/activity/content/code/content/2568460/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。