class Solution {
public:
    string greatestLetter(string s) {
        bool f[26][2];
        memset(f, 0, sizeof f);
        for (char ch : s) {
            if (ch >= 'A' && ch <= 'Z') {
                int i = ch - 'A';
                f[i][1] = true;
            } else {
                int i = ch - 'a';
                f[i][0] = true;
            }
        }
        string res = "";
        for (int i = 0;i<26;++i) {
            if (f[i][0] && f[i][1])
                res = 'A' + i;
        }
        return res;
    }
};