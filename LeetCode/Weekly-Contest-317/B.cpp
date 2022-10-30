class Solution {
    
    using LL = long long;
    
public:
    vector<vector<string>> mostPopularCreator(vector<string>& c, vector<string>& id, vector<int>& v) {
        unordered_map<string, LL> v1;
        unordered_map<string, vector<int>> v2;
        
        for (int i = 0;i<c.size();++i) {
            v1[c[i]] += v[i];
            v2[c[i]].push_back(i);
        }
        
        LL maxV = 0ll;
        for (auto& [k, v] : v1) {
            maxV = max(maxV, v);
        }
        
        // cout << maxV << '\n';
        
        vector<vector<string>> res;
        for (auto& [k, vs] : v2) {
            if (v1[k] == maxV) {
                int now = 0;
                string ans = "zzzzz";
                
                // cout << ans << '\n';
                
                for (int i : vs) {
                    if (v[i] > now) {
                        now = v[i];
                        ans = id[i];
                    } else if (v[i] == now) {
                        ans = min(ans, id[i]);
                    }
                }
                res.push_back(vector<string>{k, ans});
                
                // cout << ans << '\n';
            }
        }
        
        return res;
    }
};