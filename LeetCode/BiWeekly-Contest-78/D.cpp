class Solution {
public:
    int largestVariance(string ss) {
        int res = 0, n = static_cast<int>(ss.size());
        for (int i = 0;i<26;++i) {
            for (int j = 0;j<26;++j) {
                if (i == j)
                    continue;
                char maxC = (char)(i + 'a'), minC = (char)(j + 'a');
                int diff = 0, diff_with_b = INT_MIN;
                for (int k = 0;k<n;++k) {
                    if (ss[k] == maxC) {
                        diff++;
                        diff_with_b++;
                    } else if (ss[k] == minC) {
                        diff_with_b = --diff;
                        diff = max(0, diff_with_b);
                    }
                    res = max(res, diff_with_b);
                }
            }
        }
        return res;
    }
};