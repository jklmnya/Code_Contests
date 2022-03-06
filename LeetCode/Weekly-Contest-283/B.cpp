class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long res = 0ll;
        nums.push_back(0);
        nums.push_back(INT_MAX);
        sort(nums.begin(), nums.end());
        int s = 0;
        while (k > 0 && s < nums.size() - 1) {
            long long x = nums[s], y = min((long long)nums[s + 1], x + k + 1);
            long long len = min((long long)k, max(y - x - 1, 0ll));
            if (len % 2) {
                res += (len / 2) * (x + y) + (x + y) / 2;
            } else {
                res += (len / 2) * (x + y);
            }
            k -= len;
            ++s;
        }
        return res;
    }
};