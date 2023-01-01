class Solution {
    
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> ss;
        for (int &sum : nums) {
            for (int i = 2;i<=sum/i;i++) {
                if (sum % i == 0) {
                    while (sum % i == 0) {
                        sum /= i;
                    }
                    ss.emplace(i);
                }
            }
            if (sum > 1) {
                ss.emplace(sum);
            }
        }
        return ss.size();
    }
};