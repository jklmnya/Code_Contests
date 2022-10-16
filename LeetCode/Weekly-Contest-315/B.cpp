class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> ss {nums.begin(), nums.end()};
        for (int num : nums) {
            string s = to_string(num);
            reverse(s.begin(), s.end());
            ss.emplace(stoi(s));
        }
        return ss.size();
    }
};