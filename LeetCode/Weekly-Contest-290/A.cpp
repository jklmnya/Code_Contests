class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> vv;
        int n = nums.size();
        for (int i = 0;i<n;++i) {
            for (int j = 0;j<nums[i].size();++j)
                ++vv[nums[i][j]];
        }
        vector<int> res;
        for (auto& [k, v] : vv) {
            if (v == n)
                res.push_back(k);
        }
        sort(res.begin(), res.end());
        return res;
    }
};