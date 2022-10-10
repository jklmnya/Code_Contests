class Solution {
public:
    string robotWithString(string ss) {
        string res = "";
        vector<pair<char, int>> vv;
        for (int i = 0;i<ss.size();++i)
            vv.emplace_back(ss[i], i);
        sort(vv.begin(), vv.end(), [](const pair<char, int>& p1, const pair<char, int>& p2) {
            if (p1.first == p2.first)
                return p1.second < p2.second;
            return p1.first < p2.first;
        });
        int last = -1;
        vector<int> remain;
        for (auto& [ch, id] : vv) {
            if (id > last) {
                while (remain.size() && remain.back() <= ch) {
                    char c = remain.back();
                    remain.pop_back();
                    res += c;
                }
                res += ch;
                for (int i = last + 1;i<id;++i)
                    remain.push_back(ss[i]);
                last = id;
            }
        }
        while (remain.size()) {
            char ch = remain.back();
            res += ch;
            remain.pop_back();
        }
        return res;
    }
};