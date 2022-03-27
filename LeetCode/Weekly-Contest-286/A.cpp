class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res(2);
        unordered_set<int> s1, s2;
        for (int num : nums1)
            s1.insert(num);
        for (int num : nums2)
            s2.insert(num);
        for (int num : s1) {
            if (!s2.count(num))
                res[0].push_back(num);
        }
        for (int num : s2) {
            if (!s1.count(num))
                res[1].push_back(num);
        }
        return res;
    }
};