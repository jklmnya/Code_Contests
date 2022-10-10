class Solution {
    
    int n, m;
    const int MOD = 1e9 + 7;
    
    using LL = long long;
    
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();
        
        int f[n][m][k];
        memset(f, 0, sizeof f);
        f[0][0][grid[0][0] % k] = 1;

        for (int i = 1, sum = grid[0][0];i<m;++i) {
            sum += grid[0][i];
            f[0][i][sum % k] = 1;
        }

        for (int i = 1, sum = grid[0][0];i<n;++i) {
            sum += grid[i][0];
            f[i][0][sum % k] = 1;
        }

        for (int i = 1;i<n;++i) {
            for (int j = 1;j<m;++j) {
                int b = grid[i][j] % k;
                for (int p = 0;p<k;++p) {
                    int x = (b + p) % k;
                    f[i][j][x] = ((LL)f[i][j][x] + f[i - 1][j][p]) % MOD;
                    f[i][j][x] = ((LL)f[i][j][x] + f[i][j - 1][p]) % MOD;
                }
            }
        }
        return f[n - 1][m - 1][0];
    }
};