class Solution {
public:
    int similarPairs(vector<string>& words) {
        int res = 0;
        for (int i = 0;i<(int)words.size();++i) {
            string s1 = words[i];
            vector<bool> c1(26);
            for (char c : s1) {
                c1[c - 'a'] = true;
            }
            for (int j = i + 1;j<(int)words.size();++j) {
                vector<bool> c2(26);
                string s2 = words[j];
                for (char c : s2) {
                    c2[c - 'a'] = true;
                }
                bool ok = true;
                for (int i = 0;i<26;++i) {
                    if (c1[i] != c2[i]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    ++res;
                }
            }
        }
        return res;
    }
};