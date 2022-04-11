class Solution {
    
public:
    string minimizeResult(string expression) {
        int n = expression.size();
        string ans = "";
        int res = INT_MAX;
        int k;
        for (int i = 0;i<expression.size();++i) {
            if (expression[i] == '+') {
                k = i;
                break;
            }
        }
        for (int s1 = 0;s1<k;++s1) {
            for (int s2 = k + 1;s2<n;++s2) {
                int now = 0;
                int m1 = 1, m2 = 1, a = 0;
                if (s1 > 0)
                    m1 = stoi(expression.substr(0, s1));
                if (s2 < n - 1)
                    m2 = stoi(expression.substr(s2 + 1));
                a = stoi(expression.substr(s1, k - s1)) + stoi(expression.substr(k + 1, s2 - k));
                now = m1 * m2 * a;
                if (now < res) {
                    ans = expression;
                    ans.insert(ans.begin() + s1, 1, '(');
                    ans.insert(ans.begin() + s2 + 2, 1, ')');
                    res = now;
                }
            }
        }
        return ans;
    }
};