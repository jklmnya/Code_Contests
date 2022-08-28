class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        int n = nums.size(), m = q.size();
        vector<int> res(m);
        sort(nums.begin(), nums.end());
        for (int i = 0;i<m;++i) {
            int t = q[i];
            int now = 0, ans = 0;
            while (ans < n) {
                if (now + nums[ans] > t)
                    break;
                now += nums[ans];
                ++ans;
            }
            res[i] = ans;
        }
        return res;
    }
};