class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();
        int suffix[n + 2];
        suffix[n + 1] = 0;
        int prefix = 0;
        for (int i = n;i>=1;--i) {
            if (s[i - 1] == '0')
                suffix[i] = suffix[i + 1];
            else
                suffix[i] = min(suffix[i + 1] + 2, n - i + 1);
        }
        int res = INT_MAX;
        for (int i = 1;i<=n;++i) {
            if (s[i - 1] == '1')
                prefix = min(prefix + 2, i);
            res = min(res, prefix + suffix[i + 1]);
                
        }
        return res;
    }
};
