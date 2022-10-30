class Solution {
public:
    int averageValue(vector<int>& nums) {
        int res = 0, f = 0;
        for (int num : nums) {
            if (num % 2 == 0 && num % 3 == 0) {
                ++f;
                res += num;
            }
        }
        if (res) {
            return res / f;
        } else {
            return 0;
        }
    }
};