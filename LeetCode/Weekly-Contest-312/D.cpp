class Solution {
public:
    int n;
    vector<vector<int>> g;
    vector<int> w, p;
    
    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        n = vals.size();
        w = vals;
        g = vector<vector<int>>(n);
        for (auto& e: edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        
        vector<int> q(n);
        p = vector<int>(n);
        for (int i = 0; i < n; i ++ ) q[i] = p[i] = i;
        
        sort(q.begin(), q.end(), [&](int x, int y) {
            return w[x] < w[y];
        });
        
        int res = 0;
        vector<int> fs;
        for (int i = 0; i < n; i ++ ) {
            int j = i + 1;
            while (j < n && w[q[j]] == w[q[i]]) j ++ ;
            for (int k = i; k < j; k ++ ) {
                for (int u: g[q[k]]) {
                    if (w[q[k]] >= w[u]) {
                        int x = find(q[k]), y = find(u);
                        if (x != y) p[x] = y;
                    }
                }
            }
            fs.clear();
            for (int k = i; k < j; k ++ )
                fs.push_back(find(q[k]));
            sort(fs.begin(), fs.end());
            
            for (int x = 0; x < fs.size(); x ++ ) {
                int y = x + 1;
                while (y < fs.size() && fs[y] == fs[x]) y ++ ;
                int len = y - x;
                res += len * (len - 1) / 2 + len;
                x = y - 1;
            }
            
            i = j - 1;
        }
        
        return res;
    }
};