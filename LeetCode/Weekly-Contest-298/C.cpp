class Solution {
public:
    int longestSubsequence(string ss, int k) {
        long long res = 0;
        int zes = 0, n = ss.size();
        for (int i = 0;i<n;++i) {
            if (ss[i] == '0')
                ++zes;
        }
        int s = n - 1, e = n - 1;
        long long now = 0, len = 0;
        while (s >= 0) {
            
            if (ss[s] == '1') {
                while (len >= 32) {
                     if (ss[e] == '0')
                        now >>= 1;
                    else
                        now = (now - 1) >> 1;
                    --e;
                    --len;
                }
                now += (long long)1 << len;
            }
                
            else
                zes--;
            ++len;
            while (now > k) {
                if (ss[e] == '0')
                    now >>= 1;
                else
                    now = (now - 1) >> 1;
                --e;
                --len;
            }
            res = max(res, len + zes);
            --s;
        }
        return res;
    }
};