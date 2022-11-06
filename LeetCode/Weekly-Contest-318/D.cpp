class Solution {
    
    using LL = long long;
    LL dp[105][105];
    
    vector<int> rs;
    vector<vector<int>> fs;
    
    int n, m;   // n : len(factory), m : len(robot)
    
    // i : factory, j : robot
    LL dfs(int i, int j) {
        if (dp[i][j] > 0) {
            return dp[i][j];
        }
        if (j >= m) {
            return 0ll;
        }
        if (i == n - 1) {
            if (m - j > fs[i][1]) {
                dp[i][j] = LLONG_MAX >> 1;
            } else {
                for (int k = j;k<m;++k) {
                    dp[i][j] += abs(fs[i][0] - rs[k]);
                }
            }
        } else {
            LL sum = 0ll, ans = dfs(i + 1, j);
            for (int k = 1;k<=fs[i][1] && j + k <= m;++k) {
                sum += abs(fs[i][0] - rs[j + k - 1]);
                ans = min(ans, sum + dfs(i + 1, j + k));
            }
            dp[i][j] = ans;
        }
        return dp[i][j];
    }
    
public:
    long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& f) {
        n = f.size(), m = r.size();
        rs = move(r);
        fs = move(f);
        sort(rs.begin(), rs.end());
        sort(fs.begin(), fs.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return v1[0] < v2[0]; 
        });
        memset(dp, 0, sizeof dp);
        return dfs(0, 0);
    }
};