class Solution {
    
    using LL = long long;
    
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        LL res = 0ll;
        int n = nums.size(), s = 0, e = 0;
        int lastMin = -1, lastMax = -1;
        multiset<int> ss;
        while (e < n) {
            ss.emplace(nums[e]);
            if (nums[e] == minK)
                lastMin = e;
            if (nums[e] == maxK)
                lastMax = e;
            if (*ss.begin() == minK && *ss.rbegin() == maxK) {
                
                if (nums[e] == minK)
                    res += lastMax - s + 1;
                else if (nums[e] == maxK)
                    res += lastMin - s + 1;
                else
                    res += min(lastMin, lastMax) - s + 1;
            }
            while (ss.size() && (*ss.begin() < minK || *ss.rbegin() > maxK)) {
                ss.erase(ss.find(nums[s]));
                ++s;
            }
            ++e;
        }
        return res;
    }
};