class Solution {
public:
    int largestCombination(vector<int>& c) {
        int res = 1, n = c.size();
        int f[n][31];
        memset(f, 0, sizeof f);
        for (int i = 0;i<n;++i) {
            for (int j = 0;j<31;++j)
                f[i][j] = (c[i] >> j) & 1;
        }
        for (int j = 0;j<31;++j) {
            int ans = 0;
            for (int i = 0;i<n;++i) {
                if (f[i][j] == 1)
                    ++ans;
            }
            res = max(res, ans);
        }
        return res;
    }
};