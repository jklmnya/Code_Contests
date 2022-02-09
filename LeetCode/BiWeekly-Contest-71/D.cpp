class Solution {
    
    typedef long long LL;
    
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int d = n / 3;
        LL x = 0ll, y = 0ll;
        priority_queue<LL> pq;
        vector<LL> v1(d + 1), v2(d + 1);
        for (int i = 0;i<d;++i) {
            x += nums[i];
            pq.emplace(nums[i]);
        }
        v1[0] = x;
        for (int i = d;i<2*d;++i) {
            if (nums[i] <= pq.top()) {
                x -= pq.top();
                pq.pop();
                pq.emplace(nums[i]);
                x += nums[i];
            }
            v1[i - d + 1] = x;
        }
        priority_queue<LL, vector<LL>, greater<LL>> pqq;
        for (int i = 2 * d;i<n;++i) {
            y += nums[i];
            pqq.emplace(nums[i]);
        }
        v2[d] = y;
        for (int i = 2*d - 1;i>=d;--i) {
            if (nums[i] >= pqq.top()) {
                y -= pqq.top();
                pqq.pop();
                pqq.emplace(nums[i]);
                y += nums[i];
            }
            v2[i - d] = y;
        }
        LL res = LLONG_MAX;
        for (int i = 0;i<=d;++i)
            res = min(res, v1[i] - v2[i]);
        return res;
    }
};
