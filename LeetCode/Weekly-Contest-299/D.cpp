class Solution {
    
    vector<vector<int>> g;
    vector<int> f;
    vector<vector<int>> ug;
    vector<vector<bool>> st;
    
    int dfs(int node, int father, vector<int>& nums) {
        int val = nums[node];
        for (int next : g[node]) {
            if (next != father) {
                ug[node].push_back(next);
                val ^= dfs(next, node, nums);
            }
        }
        f[node] = val;
        return val;
    }
    
    void bfs(int start) {
        queue<int> q;
        q.emplace(start);
        while (q.size()) {
            int node = q.front();
            // cout << node << '\n';
            q.pop();
            st[start][node] = true;
            for (int next : ug[node])
                q.emplace(next);
        }
    }
    
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        g.resize(n);
        f.resize(n);
        st.resize(n, vector<bool>(n));
        ug.resize(n);
        for (auto& ed : edges) {
            int s1 = ed[0], s2 = ed[1];
            g[s1].push_back(s2);
            g[s2].push_back(s1);
        }
        
        dfs(0, -1, nums);
        
        edges.clear();
        for (int i = 0;i<n;++i)
            for (int k : ug[i])
                edges.push_back( { i, k } );
        
        for (int i = 0;i<n;++i)
            bfs(i); 

        int res = INT_MAX;
        for (int i = 0;i<edges.size();++i) {
            int s1 = edges[i][0], e1 = edges[i][1];
            for (int j = i + 1;j<edges.size();++j) {
                int s2 = edges[j][0], e2 = edges[j][1];
                int x = f[e1], y = f[e2];
                if (st[e1][e2])
                    x ^= y;
                if (st[e2][e1])
                    y ^= x;
                int z = f[0] ^ x ^ y;
                res = min(res, max(x, max(y, z)) - min(x, min(y, z)));
            }
        }
        return res;
    }
};