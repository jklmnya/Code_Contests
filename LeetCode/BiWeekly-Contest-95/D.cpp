class Solution {
    
    using LL = long long;
    
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        LL left = 0ll, right = 1e17;
        int n = stations.size();
        vector<LL> vec(n);
        while (left <= right) {
            LL mid = (left + right) >> 1;
            LL need = 0ll, sum = 0ll;
            int a = 0, b = 0, c = 0;
            for (int i = 0;i<n;++i) {
                vec[i] = stations[i];
            }
            bool ok = true;
            while (b < n) {
                while (c <= min(n - 1, b + r)) {
                    sum += vec[c++];
                }
                while (b - a > r) {
                    sum -= vec[a++];
                }
                if (sum < mid) {
                    LL t = mid - sum;
                    need += t;
                    if (need > k) {
                        ok = false;
                        break;
                    }
                    vec[min(n - 1, b + r)] += t;
                    sum = mid;
                }
                ++b;
            }
            if (!ok) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left - 1;
    }
};