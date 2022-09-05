class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        for (int i = 0;i<26;++i) {
            bool f = false;
            int a = -1, b = -1;
            for (int j = 0;j<s.size();++j) {
                if (s[j] - 'a' == i) {
                    f = true;
                    if (a == -1)
                        a = j;
                    else
                        b = j;
                }
            }
            if (f) {
                if (b - a - 1 != distance[i])
                    return false;
            }
        }
        return true;
    }
};