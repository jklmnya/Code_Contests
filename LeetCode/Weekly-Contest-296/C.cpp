class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int res = 0;
        stack<pair<int, int>> st;
        for (int num : nums) {
            int max_t = 0;
            while (st.size() && st.top().first <= num) {
                max_t = max(max_t, st.top().second);
                st.pop();
            }
            if (st.size())
                max_t++;
            res = max(res, max_t);
            st.emplace(num, max_t);
        }
        return res;
    }
};