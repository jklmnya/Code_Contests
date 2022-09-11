class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int res = 0;
        int f[1000005];
        memset(f, 0, sizeof f);
        for (auto& i : intervals) {
            f[i[0]]++;
            f[i[1] + 1]--;
        }
        for (int i = 1, now = 0;i<=1000004;++i) {
            now += f[i];
            res = max(res, now);
        }
        return res;
    }
};