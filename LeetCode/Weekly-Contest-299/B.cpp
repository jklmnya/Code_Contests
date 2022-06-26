class Solution {
    
    const int MOD = 1e9 + 7;
    
public:
    int countHousePlacements(int n) {
        int f[n + 1][2];
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1;i<=n;++i) {
            f[i][0] = ((long long)f[i - 1][0] + f[i - 1][1]) % MOD;
            f[i][1] = f[i - 1][0] % MOD;
        }
        int res = ((long long)f[n][0] + f[n][1]) % MOD;
        res = ((long long)res * res) % MOD;
        return res;
    }
};