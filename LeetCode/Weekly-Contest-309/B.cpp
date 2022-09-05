class Solution {
    
    const int MOD = 1e9 + 7;
    
public:
    int numberOfWays(int startPos, int endPos, int k) {
        int f[k + 1][3010];
        memset(f, 0, sizeof f);
        f[0][startPos + 1000] = 1;
        
        for (int i = 1;i<=k;++i) {
            for (int j = 1;j<=3005;++j) {
                f[i][j] = ((long long)f[i][j] + f[i - 1][j - 1] + f[i - 1][j + 1]) % MOD;
            }
        }
        
        return f[k][endPos + 1000];
    }
};