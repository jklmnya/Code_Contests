class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> f(n + 1);
        unordered_map<int, unordered_set<int>> ss;
        for (const auto& edge : edges) {
            int s1 = edge[0], s2 = edge[1];
            f[s1]++;
            f[s2]++;
            ss[s1].insert(s2);
            ss[s2].insert(s1);
        }
        
        vector<int> vv;
        for (int i = 1;i<=n;++i) {
            if (f[i] % 2) {
                vv.push_back(i);
            }
        }
        
        if (vv.size() > 4) {
            return false;
        } else if (vv.size() == 4) {
            int a = vv[0], b = vv[1], c = vv[2], d = vv[3];
            if (!ss[a].count(b) && !ss[c].count(d)) {
                return true;
            }
            if (!ss[a].count(c) && !ss[b].count(d)) {
                return true;
            }
            if (!ss[a].count(d) && !ss[b].count(c)) {
                return true;
            }
            return false;
        } else if (vv.size() == 3) {
            return false;
        } else if (vv.size() == 2) {
            int x = vv[0], y = vv[1];
            if (!ss[x].count(y)) {
                return true;
            }
            for (int i = 1;i<=n;++i) {
                if (i != x && i != y && !ss[x].count(i) && !ss[y].count(i)) {
                    return true;
                }
            }
            return false;
        } else if (vv.size() == 1) {
            return false;
        } else {
            return true;
        }
    }
};