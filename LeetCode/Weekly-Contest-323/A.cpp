class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size(), m = grid[0].size();
        for (auto& g : grid) {
            sort(g.begin(), g.end());
        }
        for (int i = m - 1;i>=0;--i) {
            int ans = 0;
            for (int j = 0;j<n;++j) {
                ans = max(ans, grid[j][i]);
            }
            res += ans;
        }
        return res;
    }
};