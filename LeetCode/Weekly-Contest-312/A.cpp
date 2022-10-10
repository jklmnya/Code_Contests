class Solution {
public:
    vector<string> sortPeople(vector<string>& n, vector<int>& h) {
        vector<string> res;
        vector<pair<string, int>> vv;
        for (int i = 0;i<n.size();++i)
            vv.emplace_back(n[i], h[i]);
        sort(vv.begin(), vv.end(), [](const pair<string, int>& p1, const pair<string, int>& p2) {
            return p1.second > p2.second; 
        });
        for (auto& [name, hei] : vv)
            res.emplace_back(name);
        return res;
    }
};