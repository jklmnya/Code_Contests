class Solution {
public:
    int partitionString(string ss) {
        int res = 0;
        int f[26];
        int s = 0, n = ss.size();
        while (s < n) {
            memset(f, 0, sizeof f);
            int e = s;
            while (e < n && f[ss[e] - 'a'] == 0) {
                f[ss[e] - 'a']++;
                ++e;
            }
            ++res;
            s = e;
        }
        return res;
    }
};