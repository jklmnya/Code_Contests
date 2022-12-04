class Solution {
    
    vector<int> f;
    
    int find(int node) {
        if (node != f[node]) {
            f[node] = find(f[node]);
        }
        return f[node];
    }
    
public:
    int minScore(int n, vector<vector<int>>& roads) {
        f.resize(n + 1);
        for (int i = 1;i<=n;++i) {
            f[i] = i;
        }
        for (auto& r : roads) {
            int x = r[0], y = r[1];
            f[find(x)] = find(y);
        }
        int res = INT_MAX;
        for (auto& r : roads) {
            int x = r[0], y = r[1], w = r[2];
            if (find(x) == find(1) && find(x) == find(n)) {
                res = min(res, w);
            }
        }
        return res;
    }
};