class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        int add = 0;
        int res = max(sum1, sum2);
        int n = nums1.size();
        int s = 0, e = 0;
        while (e < n) {
            add += nums2[e] - nums1[e];
            while (add < 0) {
                add -= nums2[s] - nums1[s];
                ++s;
            }
            res = max(res, sum1 + add);
            ++e;
        }
        s = 0, e = 0, add = 0;
        while (e < n) {
            add += nums1[e] - nums2[e];
            while (add < 0) {
                add -= nums1[s] - nums2[s];
                ++s;
            }
            res = max(res, sum2 + add);
            ++e;
        }
        return res;
    }
};