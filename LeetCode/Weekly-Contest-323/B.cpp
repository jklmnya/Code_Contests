class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int res = -1;
        unordered_set<long long> ss {nums.begin(), nums.end()};
        sort(nums.begin(), nums.end());
        for (int num : nums) {
            int ans = 0;
            long long x = num;
            while (ss.count(x)) {
                ++ans;
                x = x * x;
            }
            if (ans >= 2) {
                res = max(res, ans);
            }
        }
        return res;
    }
};