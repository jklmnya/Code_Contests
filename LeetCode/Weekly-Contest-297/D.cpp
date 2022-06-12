unordered_set<string> ss;
int f[26][26];

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long res = 0ll;
        memset(f, 0, sizeof f);

        ss.clear();

        for (auto& id : ideas)
            ss.emplace(id);

        for (auto id : ideas) {
            int i = id[0] - 'a';
            for (int j = 0;j<26;++j) {
                id[0] = j + 'a';
                if (!ss.count(id))
                    ++f[i][j];
            }
        }

        for (auto id : ideas) {
            int i = id[0] - 'a';
            for (int j = 0;j<26;++j) {
                id[0] = j + 'a';
                if (!ss.count(id))
                    res += f[j][i];
            }   
        }

        return res;
    }
};