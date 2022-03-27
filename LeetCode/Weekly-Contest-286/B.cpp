class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int res = 0;
        int s = 0, k = 0, n = nums.size();
        while (s < n) {
            int e = s;
            while (e < n && nums[s] == nums[e])
                ++e;
            if (e - s >= 2) {
                if (k % 2 == 0) {
                    res += max(0, e - s - 1);
                    k++;
                } else {
                    res += max(0, e - s - 2);
                    k += 2;
                }
            } else {
                ++k;
            }
            s = e;
        }
        if (k % 2)
            ++res;
        return res;
    }
};