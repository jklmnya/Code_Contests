class Solution {
    
    vector<int> TopoSort(vector<vector<int>>& eds, int k) {
        vector<vector<int>> g(k + 1);
        vector<int> ind(k + 1);
        for (auto& ed : eds) {
            int s = ed[0], e = ed[1];
            g[s].push_back(e);
            ind[e]++;
        }
        vector<int> res;
        queue<int> q;
        for (int i = 1;i<=k;++i) {
            if (ind[i] == 0) {
                res.push_back(i);
                q.emplace(i);
            }
        }
        while (q.size()) {
            int node = q.front();
            q.pop();
            for (int next : g[node]) {
                if (--ind[next] == 0) {
                    q.emplace(next);
                    res.push_back(next);
                }
            }
        }
        return res;
    }
    
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> r = TopoSort(rowConditions, k);
        vector<int> c = TopoSort(colConditions, k);
        if (r.size() < k || c.size() < k)
            return {};
        vector<vector<int>> res(k, vector<int>(k));
        vector<pair<int, int>> vv(k + 1);
        for (int i = 0;i<k;++i) {
            vv[r[i]].first = i;
            vv[c[i]].second = i;
        }
        for (int i = 1;i<=k;++i) {
            int x = vv[i].first, y = vv[i].second;
            res[x][y] = i;
        }
        return res;
    }
};