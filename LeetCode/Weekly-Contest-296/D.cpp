class Solution {
    
    const int dx[4] = { -1, 1, 0, 0 };
    const int dy[4] = { 0, 0, -1, 1 };
    
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
         int st[n][m];
        memset(st, 0x3f, sizeof st);
        deque<pair<int, int>> q;
        q.emplace_front(0, 0);
        while (q.size()) {
            auto [k, v] = q.front();
            q.pop_front();
            int x = k / m, y = k % m;
            if (v >= st[x][y])
                continue;
            st[x][y] = v;
            if (x == n - 1 && y == m - 1)
                return v;
            for (int i = 0;i<4;++i) {
                int tx = x + dx[i], ty = y + dy[i];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m)
                    continue;
                if (grid[tx][ty] == 1) {
                    q.emplace_back(tx * m + ty, v + 1);
                } else
                    q.emplace_front(tx * m + ty, v);
                }
        }
        return st[n - 1][m - 1];
    }
};