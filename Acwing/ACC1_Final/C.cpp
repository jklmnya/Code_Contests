#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 200010;
int n, a, b;
vector<vector<pair<int, bool>>> g;
int f[N];

int dfs(int node, int father) {
    int ans = 0;
    for (auto& [next, c] : g[node]) {
        if (next != father) {
            ans += dfs(next, node);
            if (!c)
                ++ans;
        }
    }
    f[node] = ans;
    return f[node];
} 

void bfs(int& res, vector<int>& ans) {
    queue<pair<int, int>> q;
    q.emplace(1, 0);
    while (q.size()) {
        auto [node, father] = q.front();
        q.pop();
        for (auto& [next, c] : g[node]) {
            if (next != father) {
                q.emplace(next, node);
                if (c) {
                    f[next] = f[node] + 1;
                } else {
                    f[next] = f[node] - 1;
                }
                if (f[next] < res) {
                    res = f[next];
                    ans.clear();
                    ans.push_back(next);
                } else if (f[next] == res) {
                    ans.push_back(next);
                }
            }
        }
    }
}

int main() {
    cin >> n;
    g.resize(n + 1);
    for (int i = 0;i<n-1;++i) {
        cin >> a >> b;
        g[a].emplace_back(b, true);
        g[b].emplace_back(a, false);
    }
    dfs(1, 0);

    // for (int i = 1;i<=n;++i)
    //     cout << f[i] << ' ';
    // cout << '\n';

    int res = f[1];
    vector<int> ans;
    ans.push_back(1);
    bfs(res, ans);
    sort(ans.begin(), ans.end());
    cout << res << '\n';
    for (int a : ans)
        cout << a << ' ';
    cout << '\n';
    return 0;
}

作者：同济大学_第一届ACC决赛
链接：https://www.acwing.com/activity/content/code/content/3028528/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。