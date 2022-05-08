class Solution {
    
    const int MOD = 1e9 + 7;
    const int vv[10] = { 0, 0, 3, 3, 3, 3, 3, 4, 3, 4 };
    
public:
    int countTexts(string p) {
        int n = p.size();
        int f[n + 1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (int s = 0;s<n;++s) {
            int cnt = vv[p[s] - '0'];
            int e = s;
            while (e >= 0 && cnt-- && p[s] == p[e]) {
                f[s + 1] = ((long long)f[e] + f[s + 1]) % MOD;
                --e;
            }
        }
        return f[n];
    }
};