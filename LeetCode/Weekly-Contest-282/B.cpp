class Solution {
public:
    int minSteps(string s, string t) {
        int res = 0;
        int f1[26], f2[26];
        memset(f1, 0, sizeof f1);
        memset(f2, 0, sizeof f2);
        for (char ch : s)
            ++f1[ch - 'a'];
        for (char ch : t)
            ++f2[ch - 'a'];
        for (int i = 0;i<26;++i) {
            if (f1[i] == f2[i])
                continue;
            else
                res += abs(f1[i] - f2[i]);
        }
        return res;
    }
};