class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& s) {
        int res = 0;
        sort(s.begin(), s.end());
        res = max(s[0] - bottom, top - s.back());
        for (int i = 1;i<s.size();++i)
            res = max(res, s[i] - s[i - 1] - 1);
        return res;
    }
};