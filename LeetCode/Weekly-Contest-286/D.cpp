class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = static_cast<int>(piles.size());
        int dp[k + 1];
        memset(dp, 0x00, sizeof dp);
        int cnt = 0;
        vector<int> prefix;
        for (int i = 1;i<=n;++i) {
            cnt += piles[i - 1].size();
            prefix.clear();
            prefix.push_back(0);
            for (int j = 0;j<piles[i - 1].size();++j)
                prefix.push_back(prefix.back() + piles[i - 1][j]);
            for (int j = min(k, cnt);j>=1;--j) {
                for (int l = min(j, (int)prefix.size() - 1);l>=0;--l)
                        dp[j] = max(dp[j], dp[j - l] + prefix[l]);
            }
        }
        return dp[k];
    }
};