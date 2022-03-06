class Solution {
public:
    vector<string> cellsInRange(string ss) {
        vector<string> res;
        int s = ss[1] - '0', e = ss[4] - '0';
        int cs = ss[0] - 'A', ce = ss[3] - 'A';
        while (cs != ce + 1) {
            for (int i = s;i<=e;++i) {
                string ans = "";
                ans += (char)(cs + 'A');
                ans += (char)(i + '0');
                res.emplace_back(move(ans));
            }
            ++cs;
        }
        return res;
    }
};