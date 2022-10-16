class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int res = -1;
        for (int i = 0;i<nums.size();++i) {
            for (int j = 0;j<nums.size();++j) {
                if (nums[i] > 0 && nums[j] == -nums[i])
                    res = max(res, nums[i]);
            }
        }
        return res;
    }
};