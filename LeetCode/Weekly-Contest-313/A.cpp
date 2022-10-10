class Solution {
public:
    int commonFactors(int a, int b) {
        unordered_map<int, int> vv;
        for (int i = 1;i<=a;++i) {
            if (a % i == 0)
                vv[i]++;
        }
        for (int i = 1;i<=b;++i) {
            if (b % i == 0)
                vv[i]++;
        }
        int res = 0;
        for (auto& [k, v] : vv) {
            if (v == 2)
                ++res;
        }
        return res;
    }
};