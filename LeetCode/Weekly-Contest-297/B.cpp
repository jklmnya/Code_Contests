class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size(), m = grid[0].size();
        int f[n][m];
        memset(f, 0x3f, sizeof(f));
        for (int i = 0;i<m;++i)
            f[0][i] = grid[0][i];
        
        for (int i = 1;i<n;++i) {
            for (int j = 0;j<m;++j) {
                for (int k = 0;k<m;++k) {
                    int x = grid[i - 1][k];
                    f[i][j] = min(f[i][j], f[i - 1][k] + moveCost[x][j] + grid[i][j]);
                }
            }
        }
        
        int res = INT_MAX;
        for (int i = 0;i<m;++i)
            res = min(res, f[n - 1][i]);
        return res;
    }
};