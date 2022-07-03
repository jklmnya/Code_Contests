class Solution {
    
    const int MOD = 1e9 + 7;
    const int dx[4] = { -1, 1, 0, 0 };
    const int dy[4] = { 0, 0, -1, 1 };
    
    int res = 0;
    int n, m;
    vector<vector<int>> g;
    vector<vector<int>> st;
    
    int dfs(int x, int y) {
        if (st[x][y] > 0)
            return st[x][y];
        int ans = 0;
        for (int i = 0;i<4;++i) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 0 || tx >= n || ty < 0 || ty >= m || g[tx][ty] <= g[x][y])
                continue;
            ans = ((long long)ans + dfs(tx, ty)) % MOD;
        }
        st[x][y] = ((long long)ans + 1) % MOD;
        return st[x][y];
    }
    
public:
    int countPaths(vector<vector<int>>& grid) {
        g = std::move(grid);
        n = g.size(), m = g[0].size();
        st.resize(n, vector<int>(m, 0));
            
        for (int i = 0;i<n;++i) {
            for (int j = 0;j<m;++j) {
                int len = dfs(i, j);
                res = ((long long)res + len) % MOD;
            }
        }
        
        return res;
    }
};