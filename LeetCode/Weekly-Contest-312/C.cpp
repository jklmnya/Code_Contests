class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> res;
        vector<int> right(nums.size());
        for (int i = nums.size() - 2, t = 1;i>=0;--i) {
            right[i] = t;
            if (nums[i] <= nums[i + 1])
                ++t;
            else
                t = 1;
        }
        
        for (int i = 1, left = 1;i<nums.size();++i) {
            if (left >= k && right[i] >= k)
                res.push_back(i);
            
            if (nums[i] <= nums[i - 1])
                ++left;
            else
                left = 1;
        }
        
        return res;
    }
};