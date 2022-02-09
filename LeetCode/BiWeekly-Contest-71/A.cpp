class Solution {
public:
    int minimumSum(int num) {
        vector<int> vv;
        while (num) {
            vv.emplace_back(num % 10);
            num /= 10;
        }
        sort(vv.begin(), vv.end());
        int res = INT_MAX;
        // 2;
        res = min(res, vv[0] * 10 + vv[1] + vv[2] * 10 + vv[3]);
        res = min(res, vv[0] * 10 + vv[2] + vv[1] * 10 + vv[3]);
        res = min(res, vv[0] * 10 + vv[3] + vv[1] * 10 + vv[2]);
        // 3;
        res = min(res, vv[0] * 100 + vv[1] * 10 + vv[2] + vv[3]);
        // res = min(res, vv[0] * 100 + vv[2] * 10 + vv);
        return res;
    }
};
