class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> s, e, b;
        for (int num : nums) {
            if (num > pivot)
                b.emplace_back(num);
            else if (num < pivot)
                s.emplace_back(num);
            else
                e.emplace_back(num);
        }
        int idx = 0;
        for (int i = 0;i<s.size();++i)
            nums[idx++] = s[i];
        for (int i = 0;i<e.size();++i)
            nums[idx++] = e[i];
        for (int i = 0;i<b.size();++i)
            nums[idx++] = b[i];
        return nums;
    }
};
