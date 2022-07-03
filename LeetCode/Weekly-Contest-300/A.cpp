class Solution {
public:
    string decodeMessage(string key, string message) {
        string res = "";
        bool st[26];
        int v[26];
        memset(st, 0, sizeof st);
        for (int i = 0, j = 0;i<key.size();++i) {
            if (key[i] != ' ' && !st[key[i] - 'a']) {
                st[key[i] - 'a'] = true;
                v[key[i] - 'a'] = j;
                ++j;
            }
        }
        for (char ch : message) {
            if (ch == ' ') {
                res += ' ';
            } else {
                res += char(v[ch - 'a'] + 'a');
            }
        }
        return res;
    }
};