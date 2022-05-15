class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ww = words;
        for (auto& word : words)
            sort(word.begin(), word.end());
        vector<string> res;
        int s = 0, n = words.size();
        while (s < n) {
            int e = s;
            while (e < n && words[s] == words[e])
                ++e;
            res.push_back(ww[s]);
            s = e;
        }
        return res;
    }
};