class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        vector<int> vv(31);
        int res = 1, s = 0, e = 0, n = nums.size();
        while (e < n) {
            for (int i = 0;i<=30;++i)
                vv[i] += (nums[e] >> i) & 1;
            while (true) {
                bool f = false;
                for (int i = 0;i<=30;++i) {
                    if (vv[i] >= 2) {
                        f = true;
                        break;
                    }
                }
                if (f) {
                    for (int i = 0;i<=30;++i)
                        vv[i] -= (nums[s] >> i) & 1;
                    ++s;
                } else {
                    break;
                }
            }
            res = max(res, e - s + 1);
            ++e;
        }
        return res;
    }
};