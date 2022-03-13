class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) {
            if (k % 2)
                return -1;
            else
                return nums[0];
        }
        int maxVal = *max_element(nums.begin(), nums.end());
        if (k > n)
            return maxVal;
        int ans = -1;
        for (int i = 0;i<k-1;++i)
            ans = max(ans, nums[i]);
        if (k == n)
            return ans;
        else
            return max(ans, nums[k]);
    }
};