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

���ߣ�Dumhdurum
���ӣ�https ://www.acwing.com/activity/content/code/content/2627073/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������