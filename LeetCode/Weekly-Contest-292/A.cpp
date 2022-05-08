class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string res = "";
        for (int s = 0;s<n-2;++s) {
            if (num[s] == num[s + 1] && num[s] == num[s + 2]) {
                string ans = num.substr(s, 3);
                if (res == "") {
                    res = ans;
                } else {
                    if (ans[0] > res[0])
                        res = ans;
                }
            }
        }
        return res;
    }
};