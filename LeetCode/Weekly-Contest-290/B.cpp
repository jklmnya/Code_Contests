class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        unordered_map<int, unordered_set<int>> vv;
        for (auto& c : circles) {
            int x = c[0], y = c[1], r = c[2];
            int lx = x - r, rx = x + r, ly = y - r, ry = y + r;
            for (int i = lx;i<=rx;++i) {
                for (int j = ly;j<=ry;++j) {
                    int len = abs(i - x) * abs(i - x) + abs(j - y) * abs(j - y);
                    if (len <= r * r)
                        vv[i].insert(j);
                }
            }
        }
        int res = 0;
        for (auto& [k, v] : vv)
            res += v.size();
        return res;
    }
};