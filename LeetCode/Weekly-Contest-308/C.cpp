class Solution {
    
public:
    int garbageCollection(vector<string>& g, vector<int>& t) {
        int res = 0, n = g.size();
        vector<vector<bool>> f(n, vector<bool>(3));
        
        unordered_map<char, int> ss;
        ss.emplace('M', 0);
        ss.emplace('P', 1);
        ss.emplace('G', 2);
        for (auto& [ch, idx] : ss) {
            for (int i = n - 1;i>=0;--i) {
                bool ok = false;
                for (char c : g[i]) {
                    if (c == ch) {
                        ok = true;
                        break;
                    }
                }
                if (ok) {
                    for (int j = i;j>=0;--j) {
                        f[j][idx] = true;
                    }
                    break;
                }
            }
        }
        reverse(t.begin(), t.end());
        t.push_back(0);
        reverse(t.begin(), t.end());
        
        for (auto& [ch, idx] : ss) {
            int ans = 0;
            for (int i = 0;i<n;++i) {
                if (f[i][idx]) {
                    ans += t[i];
                    for (char c : g[i]) {
                        if (c == ch)
                            ++ans;
                    }
                } else {
                    break;
                }
            }
            res += ans;
        }
        
        return res;
    }
};