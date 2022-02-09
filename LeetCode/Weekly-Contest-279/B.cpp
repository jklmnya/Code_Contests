class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0)
            return 0ll;
        vector<int> vv;
        bool f = num >= 0;
        num = abs(num);
        while (num) {
            vv.emplace_back(num % 10);
            num /= 10;
        }
        sort(vv.begin(), vv.end());
        long long ans = 0;
        if (f) {
            int idx = 0;
            while (idx < vv.size() && vv[idx] == 0)
                ++idx;
            ans = (long long)pow(10, vv.size() - 1) * vv[idx];
            while (++idx < vv.size()) {
                ans += (long long)pow(10, vv.size() - idx - 1) * vv[idx];
            }
        } else {
            for (int i = vv.size() - 1;i>=0;--i) {
                ans += (long long)pow(10, i) * vv[i];
            }
            ans = -ans;
        }
        return ans;
    }
};
