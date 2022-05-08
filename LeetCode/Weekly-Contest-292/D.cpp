class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (grid[0][0] == ')' || grid[n - 1][m - 1] == '(' || (n + m - 1) % 2)
            return false;
        bool f[n][m][105];
        memset(f, 0, sizeof f);
        f[0][0][1] = true;
        for (int i = 0;i<n;++i) {
            for (int j = 0;j<m;++j) {
                if (i - 1 >= 0) {
                    if (f[i - 1][j][1] && grid[i][j] == ')')
                        f[i][j][0] = true;
                    for (int k = 1;k<=(n + m) / 2;++k) {
                        if (f[i - 1][j][k - 1] && grid[i][j] == '(')
                            f[i][j][k] = true;
                        if (f[i - 1][j][k + 1] && grid[i][j] == ')')
                            f[i][j][k] = true;
                    }
                }
                if (j - 1 >= 0) {
                    if (f[i][j - 1][1] && grid[i][j] == ')')
                        f[i][j][0] = true;
                    for (int k = 1;k<=(n + m) / 2;++k) {
                        if (f[i][j - 1][k - 1] && grid[i][j] == '(')
                            f[i][j][k] = true;
                        if (f[i][j - 1][k + 1] && grid[i][j] == ')')
                            f[i][j][k] = true;
                    }
                }
            }
        }
        return f[n - 1][m - 1][0];
    }
};