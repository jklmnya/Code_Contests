class Solution {
    
    void fun(vector<int>& vv, int& res, int moveCost, int pushCost, int startAt) {
        // out << vv[0] << ' ' << vv[1] << ' ' << vv[2] << ' ' << vv[3] << '\n';
        int ans = 0;
        int idx = 0;
        while (idx < vv.size() && !vv[idx])
            ++idx;
        while (idx < vv.size()) {
            if (startAt != vv[idx]) {
                startAt = vv[idx];
                ans += moveCost;
            }
            ++idx;
            ans += pushCost;
        }
        res = min(res, ans);
    }
    
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int res = INT_MAX;
        int hh = targetSeconds / 60, mm = targetSeconds % 60;
        int h1 = hh / 10, h2 = hh % 10, m1 = mm / 10, m2 = mm % 10;
        if (h1 == 10) {
            h1 = 9;
            h2 = 9;
            m1 += 6;
        }
        vector<int> vv = { h1, h2, m1, m2 };
        fun(vv, res, moveCost, pushCost, startAt);
        if (h1 * 10 + h2 >= 1) {
            if (h2) {
                --h2;
            } else {
                --h1;
                h2 = 9;
            }
            m1 += 6;
            if (h1 * 10 + h2 >= 0 && m1 * 10 + m2 <= 99) {
                vv[0] = h1, vv[1] = h2, vv[2] = m1, vv[3] = m2;
                fun(vv, res, moveCost, pushCost, startAt);
            }        
        }
        return res;
    }
};
