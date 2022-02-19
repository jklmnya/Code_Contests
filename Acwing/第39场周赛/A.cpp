#include <iostream>
#include <algorithm>

using namespace std;

const int N = 105;

int ss[N];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> ss[i];
    int res = 0;
    for (int i = 0; i < n; ++i)
        res += abs(ss[i]);
    // accumulate(ss, ss + n, res);
    cout << res << '\n';
    return 0;
}

作者：Dumhdurum
链接：https ://www.acwing.com/activity/content/code/content/2627073/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。