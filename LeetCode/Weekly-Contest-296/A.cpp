class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int f[26], n[26];
        memset(f, 0, sizeof f);
        memset(n, 0, sizeof n);
        for (char ch : s)
            ++f[ch - 'a'];
        int res = INT_MAX;
        for (char ch : target)
            ++n[ch - 'a'];
        for (int i = 0;i<26;++i) {
            if (n[i])
                res = min(res, f[i] / n[i]);
        }
        return res;
    }
};