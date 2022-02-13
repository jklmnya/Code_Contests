class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0, n = nums.size();
        unordered_map<int, int> m1, m2;
        for (int i = 0;i<n;i+=2)
            ++m1[nums[i]];
        for (int i = 1;i<n;i+=2)
            ++m2[nums[i]];
        int cnt1 = 0, cnt2 = 0;
        vector<int> v1, v2;
        for (auto&[k, v] : m1) {
            if (v > cnt1) {
                cnt1 = v;
                v1.clear();
                v1.push_back(k);
            } else if (v == cnt1) {
                v1.push_back(k);
            }
        }
        for (auto&[k, v] : m2) {
            if (v > cnt2) {
                cnt2 = v;
                v2.clear();
                v2.push_back(k);
            } else if (v == cnt2) {
                v2.push_back(k);
            }
        }
        if (v1.size() > 1 || v2.size() > 1) {
            res = n - cnt1 - cnt2;
        } else {
            if (!v2.size())
                return 0;
            if (v1.back() != v2.back()) {
                res = n - cnt1 - cnt2;
            } else {
                int cnt3 = 0, cnt4 = 0;
                for (auto&[k, v] : m1) {
                    if (v < cnt1 && v > cnt3)
                        cnt3 = v;
                }
                for (auto&[k, v] : m2) {
                    if (v < cnt2 && v > cnt4)
                        cnt4 = v;
                }
                res = n - max(cnt1 + cnt4, cnt2 + cnt3);
            }
        }
        return res;
    }
};