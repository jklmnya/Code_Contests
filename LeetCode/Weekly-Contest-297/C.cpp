class Solution {
    
    int res = INT_MAX;
    vector<int> vv;
    
    void dfs(vector<int>& c, int i, int k) {
        if (i == c.size()) {
            int ans = 0;
            for (int num : vv)
                ans = max(ans, num);
            res = min(res, ans);
            return;
        }
        for (int j = 0;j<k;++j) {
            if (vv[j] + c[i] < res) {
                vv[j] += c[i];
                dfs(c, i + 1, k);
                vv[j] -= c[i];
            }
        }
    }
    
public:
    int distributeCookies(vector<int>& cookies, int k) {
        if (k == cookies.size())
            return *max_element(cookies.begin(), cookies.end());
        vv.resize(k);
        dfs(cookies, 0, k);
        return res;
    }
};