class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> vv;
        for (int num : nums) {
            if (num % 2 == 0)
                vv[num]++;
        }
        int res = -1, f = 0;
        for (auto& [k, v] : vv) {
            if (v > f) {
                res = k;
                f = v;
            }
        }
        return res;
    }
};