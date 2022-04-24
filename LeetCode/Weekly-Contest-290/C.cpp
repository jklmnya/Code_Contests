class Solution {
    
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        int n = points.size();
        vector<int> res(n);
        unordered_map<int, vector<int>> vv;
        for (auto& r : rectangles) {
            int x = r[0], y = r[1];
            vv[y].push_back(x);
        }
        for (auto& [k, v] : vv)
            sort(v.begin(), v.end());
        int idx = 0;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            int ans = 0;
            for (auto& [k, v] : vv) {
                if (k >= y) {
                    auto iter = lower_bound(v.begin(), v.end(), x);
                    if (iter != v.end())
                        ans += v.end() - iter;
                }   
            }
            res[idx++] = ans;
        }
        return res;
    }
};