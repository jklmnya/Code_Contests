class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> vec;
        stringstream ss(sentence);
        string str;
        while (ss >> str) {
            vec.push_back(str);
        }
        bool res = true;
        for (int i = 0;i<(int)vec.size() - 1;++i) {
            if (vec[i].back() != vec[i + 1][0]) {
                res = false;
                break;
            }
        }
        if (res) {
            if (vec.back().back() != vec[0][0]) {
                res = false;
            }
        }
        return res;
    }
};
