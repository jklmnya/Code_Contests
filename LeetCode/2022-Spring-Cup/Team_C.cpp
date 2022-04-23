
class Solution {
public:
    int getMaximumNumber(vector<vector<int>>& moles) {
        map<int, unordered_set<int>> vv;
        for (auto& mole : moles) {
            int t = mole[0], x = mole[1], y = mole[2];
            vv[t].insert(x * 3 + y);
        }
        int n = vv.size();
        int dp[n + 1][3][3];
        memset(dp, -0x3f, sizeof dp);
        if (vv.count(0) && vv[0].count(4))
            dp[0][1][1] = 1;
        else
            dp[0][1][1] = 0;
        dp[0][0][1] = dp[0][1][0] = dp[0][1][2] = dp[0][2][1] = 0;
        // dp[0][0][0] = dp[0][0][2] = dp[0][2][0] = dp[0][2][2] = -1e6;
        int idx = 1;
        int lastT = 0;
        for (auto& [k, v] : vv) {
            if (k == 0)
                continue;
            int maxT = k - lastT;
            for (int x = 0;x<3;++x) {
                for (int y = 0;y<3;++y) {
                    for (int lx = 0;lx<3;++lx) {
                        for (int ly = 0;ly<3;++ly) {
                            int len = abs(x - lx) + abs(y - ly);
                            if (len > maxT) {
                                // dp[idx][x][y] = -1e6;
                            } else {
                                if (v.count(x * 3 + y))
                                    dp[idx][x][y] = max(dp[idx][x][y], dp[idx - 1][lx][ly] + 1);
                                else
                                    dp[idx][x][y] = max(dp[idx][x][y], dp[idx - 1][lx][ly]);
                            } 
                        }
                    }
                }
            }
            lastT = k;
            ++idx;
        }
        int res = 0;
        if (vv.count(0)) {
            for (int i = 0;i<3;++i) {
                for (int j = 0;j<3;++j)
                    res = max(res, dp[n - 1][i][j]);
            }
        } else {
            for (int i = 0;i<3;++i) {
                for (int j = 0;j<3;++j)
                    res = max(res, dp[n][i][j]);
            }
        }
        return res;
    }
};