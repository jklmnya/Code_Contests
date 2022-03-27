#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
int n, m, a1[N], a2[N];

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a1[i];
    for(int i = 0; i < m; i++) cin >> a2[i];

    int i = 1, j = 1, t1 = a1[0], t2 = a2[0], cnt = 0;
    while(i <= n && j <= m)
    {
        if(t1 < t2) t1 += a1[i++];
        else if(t1 > t2) t2 += a2[j++];
        else
        {
            cnt++;
            t1 = a1[i++];
            t2 = a2[j++];
        }
    }

    if(i <= n || j <= m) cnt++; 
    cout << cnt <<endl;
    return 0;
}

作者：同济大学_第一届ACC决赛
链接：https://www.acwing.com/activity/content/code/content/3030066/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。