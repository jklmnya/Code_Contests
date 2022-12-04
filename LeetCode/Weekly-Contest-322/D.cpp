class Solution {
    
    vector<int> f;
    vector<vector<int>> g;
    vector<int> color;
    vector<int> st;
    int find(int node) {
        if (node != f[node]) {
            f[node] = find(f[node]);
        } 
        return f[node];
    }
    
    unordered_map<int, vector<int>> kv;
    
    bool foo(int start) {
        queue<int> q;
        q.emplace(start);
        color[start] = 1;
        while (q.size()) {
            int node = q.front();
            q.pop();
            for (int next : g[node]) {
                if (!color[next]) {
                    color[next] = color[node] * -1;
                    q.emplace(next);
                } else {
                    if (color[next] == color[node]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    int bfs(const vector<int>& vec) {
        int res = 0;
        for (int v : vec) {
            queue<int> q;
            q.emplace(v);
            int ans = 0, ss = 1;
            for (int i = 0;i<st.size();++i) {
                st[i] = false;
            }
            st[v] = true;
            while (q.size()) {
                while (ss--) {
                    int node = q.front();
                    q.pop();
                    for (int next : g[node]) {
                        if (!st[next]) {
                            q.emplace(next);
                            st[next] = true;
                        }
                    }
                }
                ss = q.size();
                ++ans;
            }
            res = max(res, ans);
        }
        return res;
    }
    
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        f.resize(n + 1);
        g.resize(n + 1);
        color.resize(n + 1);
        st.resize(n + 1);
        for (int i = 1;i<=n;++i) {
            f[i] = i;
        }
        for (auto& edge : edges) {
            int x = edge[0], y = edge[1];
            g[x].push_back(y);
            g[y].push_back(x);
            f[find(x)] = find(y);
        }
        for (int i = 1;i<=n;++i) {
            kv[find(i)].push_back(i);
        }
        int res = 0;
        for (const auto& [k, v] : kv) {
            if (!foo(v[0])) {
                return -1;
            }
            res += bfs(v);
        }
        return res;
    }
};