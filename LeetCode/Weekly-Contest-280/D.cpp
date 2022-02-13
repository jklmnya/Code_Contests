class Solution {

public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = static_cast<int>(nums.size()), m = 1;
        for (int i = 0;i<numSlots;++i)
            m *= 3;
        int f[n + 1][m];
        memset(f, 0, sizeof f);
        for (int i = 1;i<=n;++i) {
            for (int mask = 0;mask<m;++mask) {
                int t = mask, w = 1;
                for(int k = 1; k <= numSlots; ++k) {
                    if(t % 3 < 2)
                        f[i][mask + w] = max(f[i][mask + w], f[i - 1][mask] + (k & nums[i - 1]));
                    t /= 3;
                    w *= 3;
                }
            }
        }
        int res = 0;
        for (int i = 0;i<m;++i)
            res = max(res, f[n][i]);
        return res;
    }
};