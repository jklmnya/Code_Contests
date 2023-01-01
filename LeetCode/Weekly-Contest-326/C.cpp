class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);
        for (int i = 2;i<=right;i++) {
            if (isPrime[i]) {
                for (int j = i + i;j<=right;j += i) {
                    isPrime[j] = false;
                }
            }   
        }
        vector<int> ps;
        for (int i = max(2, left);i<=right;++i) {
            if (isPrime[i]) {
                ps.push_back(i);
            }
        }
        if (ps.size() <= 1) {
            return { -1, -1 };
        } else {
            int x = 0, y = 0;
            int res = INT_MAX;
            for (int i = 1;i<ps.size();++i) {
                if (abs(ps[i] - ps[i - 1]) < res) {
                    x = ps[i - 1], y = ps[i];
                    res = abs(ps[i] - ps[i - 1]);
                }
            }
            return { x, y };
        }
    }
};