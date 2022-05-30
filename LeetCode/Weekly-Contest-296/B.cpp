class Solution {
public:
    string discountPrices(string sentence, int discount) {
        string res = "";
        stringstream ss(sentence);
        string str;
        long double d = double(100 - discount) / 100;
        while (ss >> str) {
            if (str.size() >= 2 && str[0] == '$') {
                bool f = true;
                for (int i = 1;i<str.size();++i) {
                    if (!isdigit(str[i])) {
                        res += str;
                        f = false;
                        break;
                    }
                }
                if (f) {
                        long double p = (double)stoll(str.substr(1));
                        p *= d;
                        string ans = to_string(p);
                        for (int i = 0;i<ans.size();++i) {
                            if (ans[i] == '.') {
                                ans = ans.substr(0, i + 3);
                                break;
                            }
                        }
                        res += '$';
                        res += ans;
                    }
            } else {
                res += str;
            }
            res += ' ';
        }
        res.pop_back();
        return res;
    }
};