class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> g(n);
        for (auto& edge : edges) {
            int s = edge[0], e = edge[1];
            g[s].push_back(e);
            g[e].push_back(s);
        }
        unordered_set<int> ss(restricted.begin(), restricted.end());
        
        vector<bool> st(n);
        queue<int> q;
        q.emplace(0);
        
        while (q.size()) {
            int node = q.front();
            q.pop();
            if (st[node] || ss.count(node))
                continue;
            st[node] = true;
            for (int next : g[node])
                q.emplace(next);
        }
        
        int res = 0;
        for (bool f : st) {
            if (f)
                ++res;
        }
        return res;
    }
};