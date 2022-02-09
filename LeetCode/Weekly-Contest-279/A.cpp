class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> v1, v2;
        for (int i = 0;i<nums.size();++i) {
            if (i % 2)
                v1.emplace_back(nums[i]);
            else
                v2.emplace_back(nums[i]);
        }
        sort(v1.begin(), v1.end(), greater<int>());
        sort(v2.begin(), v2.end());
        for (int i = 0, j = 0, k = 0;k<nums.size();++k) {
            if (k % 2)
                nums[k] = v1[i++];
            else
                nums[k] = v2[j++];
        }
        return nums;
    }
};
