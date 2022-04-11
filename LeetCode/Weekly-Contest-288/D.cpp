class Solution {

    typedef long long LL;

public:
    LL maximumBeauty(vector<int>& flowers, LL newFlowers, int target, int full, int partial) {
        int n = static_cast<int>(flowers.size());
        sort(flowers.begin(), flowers.end());
        auto iter = lower_bound(flowers.begin(), flowers.end(), target);
        if (iter == flowers.begin())
            return (LL)n * full;
        LL res = (LL)full * (flowers.end() - iter);
        int m = iter - flowers.begin();
        LL f[m + 1];
        f[0] = 0ll;
        for (int i = 0;i<m;++i)
            f[i + 1] = f[i] + flowers[i];
        // 枚举full的个数
        LL ans = 0;
        int k = 0;
        while (k < m && newFlowers > 0) {
            int left = 1, right = target;
            while (left <= right) {
                int mid = (left + right) >> 1;
                auto it = lower_bound(flowers.begin(), iter, mid);
                int len = it - flowers.begin();
                LL need = (LL)len * mid - f[len];
                if (need > newFlowers)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            ans = max(ans, (LL)full * k + (LL)(min(left - 1, target - 1)) * partial);
            --iter;
            newFlowers -= target - *iter;
            ++k;
        }
        if (newFlowers >= 0)
            ans = max(ans, (LL)m * full);
        return res + ans;
    }
};