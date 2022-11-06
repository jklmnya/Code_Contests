class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        using LL = long long;
        LL res = 0ll;
        
        unordered_map<int, int> vv;
        int s = 0, e = 0, n = nums.size();
        LL now = 0ll;
        
        while (e < n) {
            vv[nums[e]]++;
            now += nums[e];
            if (e - s + 1 == k && vv.size() == k) {
                res = max(res, now);
            }
            if (e >= k - 1) {
                --vv[nums[s]];
                if (vv[nums[s]] == 0) {
                    vv.erase(nums[s]);
                }
                now -= nums[s];
                ++s;
            }
            ++e;
        }
        
        return res;
    }
};