class Solution {
    
    unordered_map<string, int> vv;
    
    const int P = 131;
    using ULL = unsigned long long;
    vector<ULL> Ps;
    
    ULL GetHash(int L, int R, vector<ULL>& Hash) {
        return Hash[R] - Hash[L - 1] * Ps[R - L + 1]; 
    }
    
    int dfs(const string& ss) {
        if (vv.count(ss))
            return vv[ss];
        if (ss.size() == 1)
            return 1;
        vector<ULL> Hash(ss.size() + 1);
        for (int i = 1;i<=ss.size();++i)
            Hash[i] = Hash[i - 1] * P + (ss[i - 1] + 'a' - 1);
        
        // vector<bool> st(26);
        int res = 1, add = 0;
        for (int len = 1;len<=(ss.size() >> 1);++len) {
            if (GetHash(1, 1 + len - 1, Hash) == GetHash(1 + len, 1 + 2 * len - 1, Hash)) {
                if (len == 1 || ss[len - 1] != ss[len - 2])
                    add = max(add, dfs(ss.substr(len)));
            }
        }
        vv.emplace(ss, 1 + add);
        return 1 + add;
    }
    
public:
    int deleteString(string ss) {
        Ps.resize(ss.size() + 1);
        Ps[0] = 1ull;
        for (int i = 1;i<=ss.size();++i)
            Ps[i] = Ps[i - 1] * P;
        return dfs(ss);
    }
};