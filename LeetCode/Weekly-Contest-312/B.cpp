class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0;
        int max_val = 0;
        for (int num : nums)
            max_val = max(max_val, num);
        for (int i = 0;i<nums.size();) {
            if (nums[i] == max_val) {
                int j = i + 1;
                while (j < nums.size() && nums[j] == nums[i])
                    ++j;
                res = max(res, j - i);
                i = j;
            } else {
                ++i;
            }
        }
        return res;
    }
};