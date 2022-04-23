class Solution {
    
    int res = -1;
    
    void dfs(vector<int>& m, vector<vector<int>>& c, vector<vector<int>>& a, int limit, int idx, int now, int ans) {
        if (idx == c.size()) {
            if (now >= limit)
                res = max(res, ans);
            return;
        }
        dfs(m, c, a, limit, idx + 1, now, ans);
        bool f = true;
        for (int i = 0;i<5;++i) {
            if (m[i] < c[idx][i]) {
                f = false;
                break;
            }
        }
        if (f) {
            for (int i = 0;i<5;++i)
                m[i] -= c[idx][i];
            dfs(m, c, a, limit, idx + 1, now + a[idx][1], ans + a[idx][0]);
            for (int i = 0;i<5;++i)
                m[i] += c[idx][i];
        }
    }
    
public:
    int perfectMenu(vector<int>& m, vector<vector<int>>& c, vector<vector<int>>& a, int limit) {
        dfs(m, c, a, limit, 0, 0, 0);
        return res;
    }
};