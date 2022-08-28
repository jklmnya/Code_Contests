class Solution {
public:
    string removeStars(string s) {
        vector<int> vv;
        for (int i = 0;i<s.size();++i) {
            if (s[i] == '*')
                vv.pop_back();
            else
                vv.push_back(i);
        }
        unordered_set<int> ss(vv.begin(), vv.end());
        string res = "";
        for (int i = 0;i<s.size();++i) {
            if (ss.count(i))
                res += s[i];
        }
        return res;
    }
};