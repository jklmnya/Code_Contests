class Solution {
public:
    long long sellingWood(int n, int m, vector<vector<int>>& prices) {
        int A[n + 1][m + 1];
        memset(A, 0, sizeof A);
        long long dp[n + 1][m + 1];
        memset(dp, 0, sizeof dp);
        
        for (const auto& p : prices)
            A[p[0]][p[1]] = p[2];

        for (int i = 1;i<=n;++i) {
            for (int j = 1;j<=m;++j) {
                dp[i][j] = A[i][j];
                for (int k = 1;k<=i;++k)
                    dp[i][j] = max(dp[i][j], dp[k][j] + dp[i - k][j]);
                for (int k = 1;k<=j;++k)
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j - k]);
            }
        }
        return dp[n][m];
    }
};